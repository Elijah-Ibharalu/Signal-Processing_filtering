# Simulink Projects Portfolio

A curated collection of **Model-Based Design**, **Signal Processing**, and **Communication Systems** projects developed in **MATLAB/Simulink**.  
This repository serves as a central workspace for exploring, validating, and documenting engineering concepts through simulation-driven design.

---

## 👤 About Me

**Elijah Ibharalu**  
R&D Officer | Signal Processing & Model-Based Design Engineer  

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Elijah%20Ibharalu-blue?logo=linkedin&logoColor=white)](https://www.linkedin.com/in/elijah-ibharalu)

---

## 🧰 Tools & Domains

- MATLAB / Simulink  
- DSP System Toolbox  
- Model-Based Design (MBD)  
- FIR / IIR Filtering  
- Multichannel Signal Processing  
- Time & Frequency Domain Analysis  
- Communications & RF System Modelling  

---

## 📂 Project Index

| Project | Domain | Description |
|------|------|------|
| 🔊 Multichannel FIR Filtering Testbed | DSP | Parallel FIR filtering of independent audio channels |
| 📡 *(Upcoming)* ADS-B Receiver Modelling | Communications | Physical layer modelling of ADS-B signal reception |
| 📶 *(Upcoming)* SDR Signal Chain Experiments | RF / DSP | Baseband processing and channel impairments |
| 🛰 *(Upcoming)* Command & Control Logic Models | Aerospace | Fault-tolerant command validation architectures |

> Click a project below to view detailed models, diagrams, and explanations.

---

## 🔊 Multichannel FIR Filtering Testbed
📁 **Directory:** [`multichannel-fir-filtering`](./multichannel-fir-filtering)

### Overview
A Simulink-based testbed developed to investigate **parallel FIR filtering** across multiple independent signal channels using a **single multichannel architecture**.

### Key Features
- Accepts **real audio** and **synthetic test signals**
- Independent channels grouped as a **multichannel signal**
- Symmetric **4-tap FIR low-pass filter**
- Time-domain and frequency-domain visualisation
- Selective playback of individual processed channels

### Engineering Objective
To validate that identical FIR operations can be applied **consistently and efficiently** across parallel signal paths using vectorised multichannel processing in Simulink.

➡️ **[View Project](./multichannel-fir-filtering)**

---

## 📐 Modelling Philosophy

All projects in this repository follow a disciplined structure:

1. Clearly defined **inputs and outputs**
2. Explicit **signal flow and assumptions**
3. Time–frequency validation where applicable
4. Emphasis on **clarity, scalability, and reusability**

This mirrors real-world **defence, aerospace, and communications** development workflows.

---

## 🚀 Roadmap

- Expand DSP testbeds (filter banks, multirate systems)
- Communications receivers and synchronisation models
- Fault-tolerant logic and validation architectures
- Hardware-aware modelling for SDR deployment

---

## 📬 Contact

For collaboration, technical discussion, or research opportunities:

🔗 **LinkedIn:**  
https://www.linkedin.com/in/elijah-ibharalu

