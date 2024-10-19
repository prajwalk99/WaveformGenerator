#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <memory>

const double PI = 3.14159265358979323846;

// Base Class for Waveforms
class Waveform {
public:
    virtual ~Waveform() = default;

    virtual float generate(float time) = 0;
    virtual void setFrequency(float frequency) = 0;
    virtual void setAmplitude(float amplitude) = 0;
    virtual void setPhase(float phase) = 0;
};

// Derived Class for Sine Wave
class SineWave : public Waveform {
private:
    float frequency;
    float amplitude;
    float phase;

public:
    SineWave(float f, float a, float p) : frequency(f), amplitude(a), phase(p) {}

    float generate(float time) override {
        return amplitude * std::sin(2 * PI * frequency * time + phase);
    }

    void setFrequency(float f) override { frequency = f; }
    void setAmplitude(float a) override { amplitude = a; }
    void setPhase(float p) override { phase = p; }
};

// Derived Class for Square Wave
class SquareWave : public Waveform {
private:
    float frequency;
    float amplitude;
    float phase;

public:
    SquareWave(float f, float a, float p) : frequency(f), amplitude(a), phase(p) {}

    float generate(float time) override {
        float value = std::sin(2 * PI * frequency * time + phase);
        return value >= 0 ? amplitude : -amplitude;
    }

    void setFrequency(float f) override { frequency = f; }
    void setAmplitude(float a) override { amplitude = a; }
    void setPhase(float p) override { phase = p; }
};

// Function to generate waveform data
void generateWaveformData(Waveform& waveform, float duration, int sampleRate, const std::string& filename) {
    std::vector<float> times;
    std::vector<float> values;

    for (int i = 0; i < duration * sampleRate; ++i) {
        float time = static_cast<float>(i) / sampleRate;
        times.push_back(time);
        values.push_back(waveform.generate(time));
    }

    // Write to CSV file
    std::ofstream file(filename);
    file << "Time,Value\n";
    for (size_t i = 0; i < times.size(); ++i) {
        file << times[i] << "," << values[i] << "\n";
    }
    file.close();
}

// Main Function
int main() {
    std::string waveformType;
    float frequency, amplitude, phase = 0.0f;

    std::cout << "Enter waveform type (sine/square): ";
    std::cin >> waveformType;
    std::cout << "Enter frequency (Hz): ";
    std::cin >> frequency;
    std::cout << "Enter amplitude: ";
    std::cin >> amplitude;
    std::cout << "Enter phase shift (radians, optional, default is 0): ";
    std::cin.ignore();
    std::string phaseInput;
    std::getline(std::cin, phaseInput);
    if (!phaseInput.empty()) {
        phase = std::stof(phaseInput);
    }

    std::unique_ptr<Waveform> waveform;
    if (waveformType == "sine") {
        waveform = std::make_unique<SineWave>(frequency, amplitude, phase);
    } else if (waveformType == "square") {
        waveform = std::make_unique<SquareWave>(frequency, amplitude, phase);
    } else {
        std::cerr << "Unknown waveform type!" << std::endl;
        return 1;
    }

    // Generate waveform data
    float duration = 1.0f; // 1 second
    int sampleRate = 1000; // 1000 samples/second
    std::string filename = waveformType + "_waveform.csv";
    generateWaveformData(*waveform, duration, sampleRate, filename);

    std::cout << "Waveform data saved to " << filename << std::endl;
    return 0;
}
