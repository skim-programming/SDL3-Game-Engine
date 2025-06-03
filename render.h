#pragma once
#ifndef RENDER
#define RENDER

#include <string>
#include <memory>
#include <cstdint>

struct SimpleVertex {
	float x, y;
	float r, g, b, a;
};

class Window {
	struct Impl;
	std::unique_ptr<Impl> pImpl;
public:
	Window(const std::string& title, int w, int h);
	~Window();
	
	void updScreen();
	void clear();
	void windowSize(int* w, int* h);
	void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	void drawTri(SimpleVertex& v1, SimpleVertex& v2, SimpleVertex& v3);
	void drawGrid(uint8_t r, uint8_t g, uint8_t b, uint8_t a, int lineDistance);
};

#endif