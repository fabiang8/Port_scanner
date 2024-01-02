This code is a simple port scanner tool built in C++ using the SFML networking library. 
### Purpose:
The code serves as a basic port scanner, offering two scan options:
1. **Vanilla Scan:** Scans a range of ports for a given host.
2. **Strobe Scan:** Scans specific well-known ports for a given host.

### Description:

- **Libraries Included:** 
  - `iostream`: Standard I/O operations.
  - `SFML/Network.hpp`: SFML networking library for TCP socket operations.
  - `string`, `fstream`, `sstream`: Standard C++ libraries for string manipulation and file handling.

- **Functions:**
  - `is_port_open`: Function to check if a specific port is open on a given host without a timeout.
  - `is_port_open_w_timeout`: Function to check if a specific port is open on a given host with a 2-second timeout.
  - `port_vector`: Function that generates a vector of integers representing a range of ports between `range` and `range2`.

- **Main Function:**
  - Asks the user to select an option: Vanilla Scan (1) or Strobe Scan (2).
  - Parses the user's input option and switches to the respective case.
  
### Vanilla Scan (Option 1):
- Asks the user to input a host address, a range of ports to scan.
- Generates a vector of ports using `port_vector` within the specified range.
- Iterates through each port in the vector and checks if it's open using `is_port_open` function. If open, prints a message stating that the port is open.

### Strobe Scan (Option 2):
- Asks the user to input a host address.
- Has a predefined list of well-known ports.
- Iterates through each port in the predefined list and checks if it's open using `is_port_open` function. Prints whether the port is open or closed.

### Troubleshooting:
- There might be an issue with the `is_port_open_w_timeout` function, as it appears that the ports are reported as closed consistently when using this function compared to the `is_port_open` function.

### Additional Notes:
- It's a console-based tool, utilizing user input to select scan options and provide host and port range information.
- The code structure follows a switch-case pattern to handle different scanning scenarios based on the selected option.

