# Gilded Rose Refactoring Kata

## What is it?

The Gilded Rose Refactoring Kata is an immersive coding exercise aimed at honing one's abilities in the practice of refactoring legacy code. The kata focuses on an inn by the name of the "Gilded Rose," which sells an assortment of items, each with various properties that change over time differently. Developers embarking on this kata are tasked with improving the codebase to facilitate the addition of new features without breaking any existing functionality.

## Origin of the Kata

This refactoring challenge was initially crafted by Emily Bache as a means for developers to sharpen their skills in a safe and controlled environment. The inspiration behind the Gilded Rose Kata was to simulate a real-world scenario where one must work with and improve upon a not-so-perfect codebase.

For further details and to try out the kata in different languages, check out Emily Bache's repository:
[Emily Bache's Gilded Rose Refactoring Kata](https://github.com/emilybache/GildedRose-Refactoring-Kata)

## Why These Languages?

In this iteration of the Gilded Rose Refactoring Kata, the focus has been narrowed down to C++, C#, PHP, and Python. The reason for this selection is simple: they are the languages with which I have regular interaction. By concentrating on these languages, the goal is to deepen practical understanding and proficiency in environments I frequently encounter in professional settings.

## License

This project operates under the MIT License, granting everyone the freedom to use, modify, share, and distribute the code subject to the terms outlined in the 'LICENSE' document found in this repository.

## Special Instructions (C++)

I changed the code to work under Windows, so below is a tutorial on how to install it:

1. Install build tools for visual studio: https://aka.ms/vs/17/release/vs_BuildTools.exe
2. You write these commands in terminal:
```
cmake -Bbuild .
cmake --build build --target GildedRose
.\build\Debug\GildedRose.exe
```

## Current Status

- [x] C++
- [ ] C#
- [ ] PHP
- [ ] Python
