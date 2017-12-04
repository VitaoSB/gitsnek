#pragma once

#include "Board.h"
#include <random>


class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody(Color color);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		const Location& GetLocation()const;
	private:
		Location loc;
		Color c;
	};

public:
	Snake(std::mt19937 & rng, const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow(std::mt19937 & rng);
	void Draw(Board& brd) const;
	Location GetNextHeadLocation(const Location& delta_loc) const;
	bool IsInTileExceptEnd(const Location& target) const;
	bool IsInTile(const Location& target) const;
	bool IsMovingUp()const;
	bool IsMovingDown()const;
	bool IsMovingLeft()const;
	bool IsMovingRight()const;

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	int bodyColorCounter = 0;
	int count = 1;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;

};