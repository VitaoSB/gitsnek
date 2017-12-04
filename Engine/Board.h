#pragma once

#include "Graphics.h"
#include "Location.h"
#include <assert.h>

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc,Color c);
	void DrawBorder() const;
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard(const Location& loc) const;
private:
	static constexpr int dimension = 20;
	static constexpr int width = 39;
	static constexpr int height = 29;
	static constexpr int borderThickness = 5;
	static constexpr Color borderColor = Colors::Blue;
	static constexpr int x = dimension - borderThickness;
	static constexpr int y = dimension - borderThickness;
	Graphics& gfx;
};