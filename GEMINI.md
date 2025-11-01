# Mixxx DJ Software

## Project Overview

Mixxx is a free and open-source DJ software that provides a comprehensive set of features for live DJ mixing. It is a cross-platform application that runs on GNU/Linux, Windows, and macOS.

The project is primarily written in C++ and uses the Qt framework for its graphical user interface. It also utilizes QML for some of its UI components. The build system is based on CMake, which allows for a flexible and cross-platform build process.

The source code is well-organized, with a clear separation of concerns. The `src` directory contains the core application logic, while the `res` directory holds resources such as skins, controller mappings, and translations. The `lib` directory contains third-party libraries used by the project.

## Building and Running

The project uses CMake for its build system. To build the project, you will need to have a C++ compiler and the Qt development libraries installed.

The `README.md` file provides detailed instructions on how to build the project on different platforms. Here is a summary of the build process:

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/mixxxdj/mixxx.git
    cd mixxx
    ```

2.  **Set up the build environment:**
    *   **Windows:** `tools\windows_buildenv.bat`
    *   **macOS:** `source tools/macos_buildenv.sh setup`
    *   **Debian/Ubuntu:** `tools/debian_buildenv.sh setup`
    *   **Fedora:** `tools/rpm_buildenv.sh setup`

3.  **Build the project:**
    ```bash
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```

After the build is complete, the `mixxx` executable will be located in the `build` directory.

## Development Conventions

The project has a set of coding guidelines and development conventions that are documented in the `CONTRIBUTING.md` file and on the [Mixxx wiki](https://github.com/mixxxdj/mixxx/wiki/Coding-Guidelines).

Here are some of the key conventions:

*   **Code Style:** The project uses `pre-commit` to enforce a consistent code style. The configuration for `pre-commit` can be found in the `.pre-commit-config.yaml` file.
*   **Git Workflow:** The project follows a standard Git workflow with feature branches and pull requests. The `CONTRIBUTING.md` file provides detailed instructions on how to contribute to the project.
*   **Internationalization:** The project is translated into multiple languages. The translation files are located in the `res/translations` directory.
*   **Testing:** The project has a suite of tests that can be run to ensure the quality of the code. The tests are located in the `src/test` directory.
