/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	void DrawStart(int x, int y);
	void DrawP1Win();
	void DrawP2Win();
	void DrawPlayer();
	void DrawPlayer2();
	void DrawNet();
	void DrawZero(int x, int y);
	void DrawOne(int x, int y);
	void DrawTwo(int x, int y);
	void DrawThree(int x, int y);
	void DrawScore();
	void DrawBall();
	void MoveBall();
	int ClampScreenX(int x, int w);
	int ClampScreenY(int y, int h);
	bool IsColliding(int x0, int y0, int width0, int height0, int x1, int y1, int width1, int height1);
	void Reset();
	void Stop();
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	bool gameIsStarted = false;
	int playerx = 80;
	int playery = 275;
	int playerspeed = 4;
	int playerwidth = 7;
	int playerheight = 50;
	int playerscore = 0;
	int player2x = gfx.ScreenWidth - playerx;
	int player2y = playery;
	int pwinx = 200;
	int pwiny = 275;
	int p2winx = gfx.ScreenWidth - pwinx - 20;
	int p2winy = pwiny;
	int player2score = 0;
	int ballx = 400;
	int bally = 0;
	int ballxspeed = 3;
	int ballyspeed = 3;
	int ballwidth = 5;
	int ballheight = 5;
	int netx = 400;
	int nety = 0;
	int netred = 0;
	int netgreen = 0;
	int netblue = 255;
	int playerscorex = 200;
	int playerscorey = 100;
	int player2scorex = 600;
	int player2scorey = 100;
	int scorered = 0;
	int scoregreen = 255;
	int scoreblue = 0;
	int fontred = 255;
	int fontgreen = 255;
	int fontblue = 255;
	/********************************/
};