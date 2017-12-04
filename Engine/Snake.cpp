#include "Snake.h"
#include <assert.h>

Snake::Snake(std::mt19937 & rng, const Location & loc)
{
	isMovingRight = true;
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);

	isMovingUp = false;
	isMovingDown = false;
	isMovingLeft = false;
	isMovingRight = false;

	if (delta_loc.x == 0 && delta_loc.y == -1)
	{
		isMovingUp = true;
	}else if (delta_loc.x == 0 && delta_loc.y == 1)
	{
		isMovingDown = true;
	}else if (delta_loc.x == -1 && delta_loc.y == 0)
	{
		isMovingLeft = true;
	}else if (delta_loc.x == 1 && delta_loc.y == 0)
	{
		isMovingRight = true;
	}

}

void Snake::Grow(std::mt19937 & rng)
{
	if (nSegments < nSegmentsMax)
	{
		std::uniform_int_distribution<int> colorDist(5, 250);
		Color c = Colors::MakeRGB(colorDist(rng), 250/*colorDist(rng)*/, colorDist(rng));
		segments[nSegments].InitBody(c);
		nSegments++;
		/*segments[nSegments].InitBody(bodyColorCounter);
		nSegments++;
		if (bodyColorCounter == 0)
		{
			count = 1;	
		}else if (bodyColorCounter == 2)
		{
			count = -1;
		}
		bodyColorCounter += count;*/
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::GetNextHeadLocation(const Location & delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

bool Snake::IsInTileExceptEnd(const Location & target) const
{
	for (int i = 0; i < nSegments - 1; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile(const Location & target) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsMovingUp() const
{
	return isMovingUp;
}

bool Snake::IsMovingDown() const
{
	return isMovingDown;
}

bool Snake::IsMovingLeft() const
{
	return isMovingLeft;
}

bool Snake::IsMovingRight() const
{
	return isMovingRight;
}

void Snake::Segment::InitHead(const Location & in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(Color color)
{
	c = color;
	//c = Colors::MakeRGB(0, 150 + i*50,0);
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
