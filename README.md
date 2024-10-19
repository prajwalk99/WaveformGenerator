#WaveformGenerator
This C++ program generates sine and square waveforms based on user-defined parameters such as frequency, amplitude, and phase shift. The generated waveform data is saved in a CSV file format for further analysis or visualization.

## Features

- Generates sine and square waveforms.
- Allows user input for frequency, amplitude, and phase shift.
- Saves output data in a CSV file.

## Requirements

- C++ compiler (e.g., g++, MinGW)
- IDE (e.g., Code::Blocks, Visual Studio)

## Compilation and Usage

1. *Clone the repository* (if applicable) or download the source code.
2. Open the main.cpp file in your preferred C++ IDE.
3. Compile the program.
4. Run the executable.

### Input

When prompted, provide the following:
- *Waveform Type*: Type sine or square.
- *Frequency (Hz)*: Enter a numeric value.
- *Amplitude*: Enter a numeric value.
- *Phase Shift (optional)*: Enter a numeric value in radians (default is 0).

### Output

The program generates a CSV file named <waveform_type>_waveform.csv containing the waveform data, with columns for time and value.
