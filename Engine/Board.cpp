#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{

}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x > 0);
	assert(loc.x < width);
	assert(loc.y > 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x*dimension - 1, loc.y*dimension - 1, dimension - 2, dimension - 2, c);
}

void Board::DrawBorder() const
{
	const int top = y - 3;
	const int bottom = height*dimension + borderThickness - 1;
	const int left = x - 3;
	const int right = width*dimension + borderThickness - 1;

	gfx.DrawRect(left, top, right, top + borderThickness, borderColor);
	gfx.DrawRect(left, top + borderThickness, left + borderThickness, bottom - borderThickness, borderColor);
	gfx.DrawRect(right - borderThickness, top + borderThickness, right, bottom - borderThickness, borderColor);
	gfx.DrawRect(left, bottom - borderThickness, right, bottom, borderColor);

}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location & loc) const
{
	return 
		loc.x > 0 && loc.x < width &&
		loc.y > 0 && loc.y < height;
}
