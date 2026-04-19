# 🫖 Advanced Teapot Visualizer

<div align="center">

![OpenGL](https://img.shields.io/badge/Graphics-OpenGL-blue?style=for-the-badge&logo=opengl&logoColor=white)
![C++](https://img.shields.io/badge/Language-C%2B%2B-blueviolet?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-brightgreen?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-lightgrey?style=for-the-badge)
![Build](https://img.shields.io/badge/Build-Passing-success?style=for-the-badge)

</div>

---

## 🚀 Project Overview

Welcome to **`teapot.cpp`**, a high-performance OpenGL-powered visualizer. This project showcases advanced real-time rendering techniques, including Blinn-Phong lighting models, interactive matrix transformations, and dynamic viewport management.

> A modern take on the classic Utah Teapot, built in C++ using `GLUT`, `GLU`, and `OpenGL`.

---

## ✨ Highlights

- 🎥 **Dynamic Shading**: Real-time lighting with metallic material properties.
- 🛠️ **Rendering Modes**: Toggle between polished solid and wireframe views.
- 🔄 **Automatic Rotation**: Smooth animation with manual override.
- �️ Mouse drag for live object rotation
- 🔎 Scroll / keyboard zoom support
- 🧩 Minimal, portable source code for fast experimentation

---

## 🛠️ Technical Specifications

| Component         | Technology / Value                         |
| :---------------- | :----------------------------------------- |
| **Graphics API**  | OpenGL 2.1 (Fixed Function Pipeline)       |
| **Windowing**     | GLUT / FreeGLUT                            |
| **Shading Model** | `GL_SMOOTH` (Gouraud/Phong style)          |
| **Materials**     | Gold Metallic (Ambient, Diffuse, Specular) |
| **Light Sources** | 1x Directional Light (`GL_LIGHT0`)         |
| **Depth Testing** | Enabled (24-bit Z-buffer)                  |

---

## 🎯 Project Features

| Feature              | Description                                       | Controls            |
| -------------------- | ------------------------------------------------- | ------------------- |
| Auto Animation       | The teapot rotates continuously around the Y axis | —                   |
| Interactive Rotation | Drag with left mouse button to orbit the model    | `Left click + drag` |
| Smooth Zoom          | Zoom in/out using mouse wheel or keyboard         | `+`, `-`, `Wheel`   |
| Toggle Mode          | Switch between Wireframe and Solid rendering      | `W` key             |
| Pause Animation      | Toggle auto-rotation on/off                       | `Space`             |
| Depth Test           | Correct 3D layering with depth buffering          | —                   |
| Portable Build       | Works on Linux with `GLUT`, `GLU`, and `OpenGL`   | —                   |

---

## 🛠️ Build & Run

Use this command to compile the demo on Linux:

```bash
g++ main.c++ -o teapot -lGL -lGLU -lglut -ldl && ./teapot
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
- `W` — toggle Wireframe/Solid mode
- `Space` — toggle auto-rotation

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
