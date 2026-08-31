# Console Music Hub

A lightweight, modular, text-based music player architecture built in pure C. This project simulates foundational audio playback loops, tracking states, and playlist indexes entirely inside a command-line terminal environment.

## Key Architecture Features

* **Modular Structure**: Split cleanly into interface headers, execution logic, and runtime entry loops.
* **Playback Simulation Engine**: Tracks mock real-time metrics and supports automated sequential progression.
* **Data Validations**: Built-in boundary checks for structural queue limits and user inputs.

## Compilation and Execution

Compile the source using GCC:

```bash
gcc main.c player.c -o music_app
```

Run the compiled executable:

```bash
./music_app
```
