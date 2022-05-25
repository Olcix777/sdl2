#pragma once
#include <utility>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Color {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
};

struct Point
{
	uint32_t x;
	uint32_t y;
};

class Shape
{
public:
	Shape() {};
	int m_x = 0;
	int m_y = 0;
	Color m_color{ 0,0,0,0 };
	virtual void Draw() { cout << "Base Draw\n"; };
};

class Triangle : public Shape
{
	string m_name;
	Point m_start{ 0,0 };
	uint32_t m_a, m_h;
public:
	Triangle(string name, const Color& color, int x, int y, uint32_t a, uint32_t h) : m_name(move(name)), m_a(a), m_h(h)
	{
		m_color = color;
		m_x = x;
		m_y = y;
	};

	void Draw() override;
};

class Circle : public Shape
{
	string m_name;
	int32_t m_radius;
public:

	Circle(string name, int x, int y, int32_t radius, const Color& color) : m_name(move(name)), m_radius(radius)
	{
		m_x = x;
		m_y = y;
		m_color = color;
	};

	void Draw() override;
};

class Rectangle : public Shape
{
	string m_name;
	int m_width;
	int m_height;
public:
	Rectangle(string name, int x, int y, int width, int height, const Color& color) : m_name(move(name)), m_width(width), m_height(height)
	{
		m_x = x;
		m_y = y;
		m_color = color;
	};
	void Draw() override;

};


class DrawingEngine
{
public:
	static void Render(vector<Shape*>& shapes)
	{
		for (Shape* it : shapes)
		{
			it->Draw();
			delete it;
		}
	}
};