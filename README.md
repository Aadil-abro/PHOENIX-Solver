# 🔱 PHOENIX: Advanced Subset Sum Solver

![C++](https://img.shields.io/badge/Language-C++-blue.svg)
![Status](https://img.shields.io/badge/Status-Active-success.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

## 📌 Overview
**PHOENIX** is a high-performance algorithmic engine built to tackle the **Subset Sum Problem**, a well-known NP-Complete challenge in computer science and cryptography. Proudly developed and stress-tested in Larkana, Sindh, this project represents a journey from basic brute-force counting to advanced cryptographic logic.

The engine was rigorously tested against complex, AI-generated cryptographic challenges (up to $N=100$) and is designed with one core philosophy: **Honesty in Computation**. If a target is solvable, PHOENIX acts as a hunter; if it is mathematically impossible, it acts as a judge and accurately rejects it.

## 🚀 Features

* **V100 - The Brute Force Engine:** Handles $N \le 20$ using standard bitmasking.
* **V300 - Lattice Basis Simulation:** Simulates the logic of Lenstra-Lenstra-Lovász (LLL) lattice reduction for large datasets ($N=100$) with low density.
* **V500 - Meet-in-the-Middle Architecture:** Cuts time complexity from $O(2^N)$ to $O(2^{N/2})$, successfully verifying $1.07$ Billion combinations ($N=30$) in mere milliseconds.
* **Zero-Approximation Output:** Built to find *exact* subsets without floating-point errors, utilizing 128-bit integer processing (`__int128_t`) for massive cryptographic targets.

## 🧠 The Philosophy (Not a $P=NP$ Proof)
PHOENIX does not claim to solve $P=NP$. Instead, it demonstrates how practical optimization techniques (like Time-Memory tradeoffs in Meet-in-the-Middle) can crack seemingly impossible combinations within real-world constraints. It is a practical, working solver that knows its limits and maximizes its algorithmic efficiency.

## 🛠️ Usage & Compilation

This code is optimized to run efficiently on standard C++ compilers, including mobile IDEs like Cxxdroid.

### Compilation
```bash
g++ -O3 phoenix_solver.cpp -o phoenix_solver
