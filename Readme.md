## VSCode GLFW Opengl template for mac

### Install
here is how you can bootstrap an Opengl project with vscode

- install Xcode command line tool (or simply install xcode)
- Install Homebrew [More info here](https://brew.sh/index)
- Install GLFW and Glew this way

```sh
brew install glfw3
brew install glew
```

- Pull this repo 
- Create a bin and obj directory in project roots

And you're ready to start

### Build

The build process use makefile and g++, it is setup on **Makefile** on project root.

Here is make commands

```sh
make clean // clean
make main	// Build
make main DEBUG=true // to build for debug (based on LLDB)
```

### VSCode integration

Vscode project directory is provided, it include c++ environment settings, tasks for building, and launches for debugging.

It is based on vscode c/c++ extension [More info on how it works here](https://code.visualstudio.com/docs/languages/cpp)

As I'm c++ young padawan (coming from far far away WebGL), now as it works only on mac it would good to have a cross plateform solution. Don't hesitate to give me feedback or pull request for cross plateform implementation.