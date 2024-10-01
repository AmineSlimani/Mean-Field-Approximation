# Mean Field Approximation for Spin = 2

This repository contains C code implementations for the mean field approximation of a system with Spin = 2. The project calculates the magnetization and subsequently uses it to compute the free energy of the system. 

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Code Overview](#code-overview)
- [Results](#results)
- [License](#license)

## Introduction

The mean field approximation is a mathematical approach used in statistical mechanics to simplify the analysis of many-body systems. This project focuses on a spin system where we calculate the magnetization as a function of temperature and then use these values to compute the free energy of the system.

## Installation

To compile and run the code, you need to have a C compiler installed (e.g., GCC). 

1. Clone the repository:
   ```bash
   git clone https://github.com/AmineSlimani/Mean-Field-Approximation.git
   cd Mean-Field-Approximation
   ```

2. Compile the code:
   ```bash
   gcc -o Mean_Field_Simulation Mean_Field_Simulation.c -lm
   gcc -o Free_Energy_Calculation Free_Energy.c -lm
   ```

## Usage

1. Run the mean field simulation code:
   ```bash
   ./Mean_Field_Simulation
   ```
   This will generate the file `champ.dat`, which contains the temperature, magnetization, susceptibility, and heat capacity values.

2. Run the free energy calculation code:
   ```bash
   ./Free_Energy_Calculation
   ```
   This will generate the file `Flibre8.dat`, which contains the temperature, magnetization, and free energy values.

## Code Overview

### Mean Field Simulation

The `Mean_Field_Simulation.c` file computes the magnetization \( m \) of the system using the following formula:

```c
m = (2 * sinh(2 * J * m / (k * T)) + sinh(J * m / (k * T))) / 
    (cosh(2 * J * m / (k * T)) + cosh(J * m / (k * T)) + 0.5);
```

The program iteratively updates the magnetization until it converges to a stable value.

### Free Energy Calculation

The `Free_Energy_Calculation.c` file calculates the free energy \( F \) using the magnetization values obtained from the previous computation:

```c
F = KB * T * N * log(2 * cosh(2 * J * m / (KB * T)) + 
                     2 * cosh(J * m / (KB * T)) + 1);
```

## Results

The resulting data files (`champ.dat` and `Flibre8.dat`) contain the calculated values for each temperature step. You can analyze these files using your preferred data analysis tools or libraries.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Author

**Amine Slimani**  
Feel free to reach out via GitHub for any questions or suggestions!
