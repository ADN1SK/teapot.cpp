# teapot.cpp

[![OpenGL](https://img.shields.io/badge/Graphics-OpenGL-blue?logo=opengl&logoColor=white)](https://www.opengl.org/)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blueviolet?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-brightgreen)](LICENSE)

---

## 🚀 Advanced Interactive Teapot Visualizer

Welcome to **`teapot.cpp`**, a sleek OpenGL-powered wireframe teapot demo with interactive camera control, auto-animation, and smooth zooming.

> A modern take on the classic Utah Teapot, built in C++ using `GLUT`, `GLU`, and `OpenGL`.

---

## ✨ Highlights

- 🎥 Automatic rotation animation
- 🖱️ Mouse drag for live object rotation
- 🔎 Scroll / keyboard zoom support
- 🌐 Clean wireframe rendering with depth testing
- 🧩 Minimal, portable source code for fast experimentation

---

## 🎯 Project Features

| Feature              | Description                                       | Controls            |
| -------------------- | ------------------------------------------------- | ------------------- |
| Auto Animation       | The teapot rotates continuously around the Y axis | —                   |
| Interactive Rotation | Drag with left mouse button to orbit the model    | `Left click + drag` |
| Smooth Zoom          | Zoom in/out using mouse wheel or keyboard         | `+`, `-`, `Wheel`   |
| Depth Test           | Correct 3D layering with depth buffering          | —                   |
| Portable Build       | Works on Linux with `GLUT`, `GLU`, and `OpenGL`   | —                   |

---

## 🛠️ Build & Run

Use this command to compile the demo on Linux:

```bash
g++ main.c++ -o teapot -lGL -lGLU -lglut -ldl
```

Or compile and run in one line:

```bash
g++ main.c++ -o teapot -lGL -lGLU -lglut -ldl && ./teapot
```

Then launch it with:

```bash
./teapot
```

> Tip: If your system uses `freeglut`, the mouse wheel zoom will be enabled automatically during runtime.

---

## 🧠 Controls

- `Left Click + Drag` — rotate teapot
- `Mouse Wheel` — zoom in/out
- `+` or `=` — zoom in
- `-` — zoom out

---

## 📁 File Overview

| File        | Purpose                                    |
| ----------- | ------------------------------------------ |
| `main.c++`  | OpenGL teapot renderer + interaction logic |
| `LICENSE`   | Project license details                    |
| `README.md` | Project documentation                      |

---

## 💡 Notes

- This demo is ideal for learning OpenGL interaction, matrix transforms, and basic GLUT event handling.
- The code is intentionally compact so it can be extended for lighting, shading, or mesh loading.

---

## 🌟 Ready to Extend

Want to make it even more advanced? Consider adding:

- dynamic lighting and material colors
- textured surfaces or a shaded teapot
- keyboard shortcuts for animation speed
- a custom UI overlay with frame info

---

## 📝 License

This project is released under the [MIT License](LICENSE).
