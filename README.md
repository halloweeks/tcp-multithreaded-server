# Multi-Threaded TCP Server

This project implements a multi-threaded TCP server in C that can handle multiple client connections concurrently. The server responds to client messages with a predefined response, showcasing basic socket programming and multithreading concepts in C.

## Features

- **Concurrent Connections**: The server can manage multiple client connections using threads.
- **Thread Management**: Each client connection is handled by a separate thread.
- **Simple Protocol**: Clients can send messages to the server, which responds with a greeting.
- **Error Handling**: Basic error handling for socket operations is included.

## Requirements

- GCC (GNU Compiler Collection)
- POSIX Threads (pthreads)
- Linux or UNIX-based operating system

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/halloweeks/tcp-multithreaded-server.git
   cd tcp-multithreaded-server
   ```

2. **Compile the server**:
   ```bash
   gcc -o server server.c -lpthread
   ```

3. **Compile the client**:
   ```bash
   gcc -o client client.c
   ```

4. **Run the server**:
   ```bash
   ./server
   ```

## Usage

To test the server, follow these steps:

1. **Run the server**:
   ```bash
   ./server
   ```

2. **Run the client** in another terminal:
   ```bash
   ./client
   ```

3. **Interact with the server**:
   - Type your message and press Enter.
   - Type `exit` to close the client connection.

## Code Structure

- `server.c`: The main file containing the server implementation.
- `client.c`: The main file containing the client implementation.
- `README.md`: Documentation for the project.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue if you have suggestions or improvements.
