/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{	
	if (gameIsStarted) {
		//Player
		if (wnd.kbd.KeyIsPressed('W')) {
			playery -= playerspeed;
		}
		if (wnd.kbd.KeyIsPressed('S')) {
			playery += playerspeed;
		}
		playery = ClampScreenY(playery, playerheight);
		//Player2
		if (wnd.kbd.KeyIsPressed(VK_UP)) {
			player2y -= playerspeed;
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			player2y += playerspeed;
		}
		player2y = ClampScreenY(player2y, playerheight);
		MoveBall();
	}
	else {
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			gameIsStarted = true;
		}
	}
}

void Game::ComposeFrame()
{
	if (!gameIsStarted) {
		DrawStart(370, 300);
	}
	else {
		DrawPlayer();
		DrawPlayer2();
		DrawBall();
		DrawNet();
		DrawScore();
	}
}

void Game::DrawStart(int x, int y)
{
	//P
	//Sol kenar
	gfx.PutPixel(x, y    , fontred, fontgreen, fontblue);
	gfx.PutPixel(x, y + 1, fontred, fontgreen, fontblue);
	gfx.PutPixel(x, y + 2, fontred, fontgreen, fontblue);
	gfx.PutPixel(x, y + 3, fontred, fontgreen, fontblue);
	gfx.PutPixel(x, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x, y + 5, fontred, fontgreen, fontblue);
	gfx.PutPixel(x, y + 6, fontred, fontgreen, fontblue);
	gfx.PutPixel(x, y + 7, fontred, fontgreen, fontblue);
	gfx.PutPixel(x, y + 8, fontred, fontgreen, fontblue);
	gfx.PutPixel(x, y + 9, fontred, fontgreen, fontblue);
	//Üst kenar	 
	gfx.PutPixel(x + 1, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 2, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 3, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 4, y, fontred, fontgreen, fontblue);
	//Sað kenar	 
	gfx.PutPixel(x + 4, y + 1, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 4, y + 2, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 4, y + 3, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 4, y + 4, fontred, fontgreen, fontblue);
	//Alt kenar	 
	gfx.PutPixel(x + 3, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 2, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 1, y + 4, fontred, fontgreen, fontblue);
	//R			 
	//Sol kenar	 
	gfx.PutPixel(x + 8, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 8, y + 1, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 8, y + 2, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 8, y + 3, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 8, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 8, y + 5, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 8, y + 6, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 8, y + 7, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 8, y + 8, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 8, y + 9, fontred, fontgreen, fontblue);
	//Üst kenar	 
	gfx.PutPixel(x + 9 , y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 10, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 11, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 12, y, fontred, fontgreen, fontblue);
	//Sað kenar	 
	gfx.PutPixel(x + 12, y + 1, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 12, y + 2, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 12, y + 3, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 12, y + 4, fontred, fontgreen, fontblue);
	//Alt kenar	 
	gfx.PutPixel(x + 11, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 10, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x +  9, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x +  8, y + 4, fontred, fontgreen, fontblue);
	//Alt çapraz 
	gfx.PutPixel(x + 13, y + 5, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 14, y + 6, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 14, y + 7, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 14, y + 8, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 14, y + 9, fontred, fontgreen, fontblue);
	//E			 
	//Sol kenar	 
	gfx.PutPixel(x + 18, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 18, y + 1, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 18, y + 2, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 18, y + 3, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 18, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 18, y + 5, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 18, y + 6, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 18, y + 7, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 18, y + 8, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 18, y + 9, fontred, fontgreen, fontblue);
	//Üst kenar	 
	gfx.PutPixel(x + 19, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 20, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 21, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 22, y, fontred, fontgreen, fontblue);
	//Orta kenar 
	gfx.PutPixel(x + 19, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 20, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 21, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 22, y + 4, fontred, fontgreen, fontblue);
	//Alt kenar	 
	gfx.PutPixel(x + 19, y + 9, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 20, y + 9, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 21, y + 9, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 22, y + 9, fontred, fontgreen, fontblue);
	//Ýlk S		 
	//Üst kenar	 
	gfx.PutPixel(x + 26, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 27, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 28, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 29, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 30, y, fontred, fontgreen, fontblue);
	//Sol kenar	 
	gfx.PutPixel(x + 26, y + 1, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 26, y + 2, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 26, y + 3, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 26, y + 4, fontred, fontgreen, fontblue);
	//Orta kenar 
	gfx.PutPixel(x + 27, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 28, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 29, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 30, y + 4, fontred, fontgreen, fontblue);
	//Sað kenar	 
	gfx.PutPixel(x + 30, y + 6, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 30, y + 7, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 30, y + 8, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 30, y + 9, fontred, fontgreen, fontblue);
	//Alt kenar	 
	gfx.PutPixel(x + 29, y + 9, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 28, y + 9, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 27, y + 9, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 26, y + 9, fontred, fontgreen, fontblue);
	//Ýkinci S	 
	//Üst kenar	 
	gfx.PutPixel(x + 26 + 8, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 27 + 8, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 28 + 8, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 29 + 8, y, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 30 + 8, y, fontred, fontgreen, fontblue);
	//Sol kenar	   
	gfx.PutPixel(x + 26 + 8, y + 1, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 26 + 8, y + 2, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 26 + 8, y + 3, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 26 + 8, y + 4, fontred, fontgreen, fontblue);
	//Orta kenar   			 
	gfx.PutPixel(x + 27 + 8, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 28 + 8, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 29 + 8, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 30 + 8, y + 4, fontred, fontgreen, fontblue);
	//Sað kenar	   			 
	gfx.PutPixel(x + 30 + 8, y + 6, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 30 + 8, y + 7, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 30 + 8, y + 8, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 30 + 8, y + 9, fontred, fontgreen, fontblue);
	//Alt kenar		   		 
	gfx.PutPixel(x + 29 + 8, y + 9, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 28 + 8, y + 9, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 27 + 8, y + 9, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 26 + 8, y + 9, fontred, fontgreen, fontblue);
	//Enter þekli
	gfx.PutPixel(x + 50, y + 4, fontred, fontgreen, fontblue);
				 
	gfx.PutPixel(x + 51, y + 3, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 51, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 51, y + 5, fontred, fontgreen, fontblue);
						 
	gfx.PutPixel(x + 52, y + 2, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 52, y + 3, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 52, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 52, y + 5, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 52, y + 6, fontred, fontgreen, fontblue);
				 		 
	gfx.PutPixel(x + 53, y + 1, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 53, y + 2, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 53, y + 3, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 53, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 53, y + 5, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 53, y + 6, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 53, y + 7, fontred, fontgreen, fontblue);
				 		 
	gfx.PutPixel(x + 54, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 55, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 56, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 57, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 58, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 59, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 60, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 61, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 62, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 63, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 64, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 65, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 66, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 67, y + 4, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 68, y + 4, fontred, fontgreen, fontblue);
				 		 
	gfx.PutPixel(x + 68, y + 3, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 68, y + 2, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 68, y + 1, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 68, y + 0, fontred, fontgreen, fontblue);
	gfx.PutPixel(x + 68, y - 1, fontred, fontgreen, fontblue);









}

void Game::DrawP1Win()
{
	//P
	//Sol kenar
	gfx.PutPixel(pwinx, pwiny, 255, 255, 255);
	gfx.PutPixel(pwinx, pwiny + 1, 255, 255, 255);
	gfx.PutPixel(pwinx, pwiny + 2, 255, 255, 255);
	gfx.PutPixel(pwinx, pwiny + 3, 255, 255, 255);
	gfx.PutPixel(pwinx, pwiny + 4, 255, 255, 255);
	gfx.PutPixel(pwinx, pwiny + 5, 255, 255, 255);
	gfx.PutPixel(pwinx, pwiny + 6, 255, 255, 255);
	gfx.PutPixel(pwinx, pwiny + 7, 255, 255, 255);
	gfx.PutPixel(pwinx, pwiny + 8, 255, 255, 255);
	gfx.PutPixel(pwinx, pwiny + 9, 255, 255, 255);
	//Üst kenar
	gfx.PutPixel(pwinx + 1, pwiny, 255, 255, 255);
	gfx.PutPixel(pwinx + 2, pwiny, 255, 255, 255);
	gfx.PutPixel(pwinx + 3, pwiny, 255, 255, 255);
	gfx.PutPixel(pwinx + 4, pwiny, 255, 255, 255);
	//Sað kenar
	gfx.PutPixel(pwinx + 4, pwiny + 1, 255, 255, 255);
	gfx.PutPixel(pwinx + 4, pwiny + 2, 255, 255, 255);
	gfx.PutPixel(pwinx + 4, pwiny + 3, 255, 255, 255);
	gfx.PutPixel(pwinx + 4, pwiny + 4, 255, 255, 255);
	//Alt kenar
	gfx.PutPixel(pwinx + 3, pwiny + 4, 255, 255, 255);
	gfx.PutPixel(pwinx + 2, pwiny + 4, 255, 255, 255);
	gfx.PutPixel(pwinx + 1, pwiny + 4, 255, 255, 255);
	//1
	gfx.PutPixel(pwinx + 8, pwiny, 255, 255, 255);
	gfx.PutPixel(pwinx + 8, pwiny + 1, 255, 255, 255);
	gfx.PutPixel(pwinx + 8, pwiny + 2, 255, 255, 255);
	gfx.PutPixel(pwinx + 8, pwiny + 3, 255, 255, 255);
	gfx.PutPixel(pwinx + 8, pwiny + 4, 255, 255, 255);
	gfx.PutPixel(pwinx + 8, pwiny + 5, 255, 255, 255);
	gfx.PutPixel(pwinx + 8, pwiny + 6, 255, 255, 255);
	gfx.PutPixel(pwinx + 8, pwiny + 7, 255, 255, 255);
	gfx.PutPixel(pwinx + 8, pwiny + 8, 255, 255, 255);
	gfx.PutPixel(pwinx + 8, pwiny + 9, 255, 255, 255);
	//W
	//Sol kenar
	gfx.PutPixel(pwinx + 16, pwiny    , 255, 255, 255);
	gfx.PutPixel(pwinx + 16, pwiny + 1, 255, 255, 255);
	gfx.PutPixel(pwinx + 16, pwiny + 2, 255, 255, 255);
	gfx.PutPixel(pwinx + 16, pwiny + 3, 255, 255, 255);
	gfx.PutPixel(pwinx + 16, pwiny + 4, 255, 255, 255);
	gfx.PutPixel(pwinx + 16, pwiny + 5, 255, 255, 255);
	gfx.PutPixel(pwinx + 16, pwiny + 6, 255, 255, 255);
	gfx.PutPixel(pwinx + 16, pwiny + 7, 255, 255, 255);
	gfx.PutPixel(pwinx + 16, pwiny + 8, 255, 255, 255);
	gfx.PutPixel(pwinx + 16, pwiny + 9, 255, 255, 255);
	//Orta kýsým
	gfx.PutPixel(pwinx + 17, pwiny + 8, 255, 255, 255);

	gfx.PutPixel(pwinx + 18, pwiny + 7, 255, 255, 255);
	gfx.PutPixel(pwinx + 18, pwiny + 6, 255, 255, 255);

	gfx.PutPixel(pwinx + 19, pwiny + 5, 255, 255, 255);
	gfx.PutPixel(pwinx + 19, pwiny + 4, 255, 255, 255);

	gfx.PutPixel(pwinx + 20, pwiny + 7, 255, 255, 255);
	gfx.PutPixel(pwinx + 20, pwiny + 6, 255, 255, 255);

	gfx.PutPixel(pwinx + 21, pwiny + 8, 255, 255, 255);
	//Sað kenar
	gfx.PutPixel(pwinx + 22, pwiny, 255, 255, 255);
	gfx.PutPixel(pwinx + 22, pwiny + 1, 255, 255, 255);
	gfx.PutPixel(pwinx + 22, pwiny + 2, 255, 255, 255);
	gfx.PutPixel(pwinx + 22, pwiny + 3, 255, 255, 255);
	gfx.PutPixel(pwinx + 22, pwiny + 4, 255, 255, 255);
	gfx.PutPixel(pwinx + 22, pwiny + 5, 255, 255, 255);
	gfx.PutPixel(pwinx + 22, pwiny + 6, 255, 255, 255);
	gfx.PutPixel(pwinx + 22, pwiny + 7, 255, 255, 255);
	gfx.PutPixel(pwinx + 22, pwiny + 8, 255, 255, 255);
	gfx.PutPixel(pwinx + 22, pwiny + 9, 255, 255, 255);
	//I
	//Üst kenar
	gfx.PutPixel(pwinx + 26, pwiny, 255, 255, 255);
	gfx.PutPixel(pwinx + 27, pwiny, 255, 255, 255);
	gfx.PutPixel(pwinx + 28, pwiny, 255, 255, 255);
	//Orta kenar
	gfx.PutPixel(pwinx + 27, pwiny + 1, 255, 255, 255);
	gfx.PutPixel(pwinx + 27, pwiny + 2, 255, 255, 255);
	gfx.PutPixel(pwinx + 27, pwiny + 3, 255, 255, 255);
	gfx.PutPixel(pwinx + 27, pwiny + 4, 255, 255, 255);
	gfx.PutPixel(pwinx + 27, pwiny + 5, 255, 255, 255);
	gfx.PutPixel(pwinx + 27, pwiny + 6, 255, 255, 255);
	gfx.PutPixel(pwinx + 27, pwiny + 7, 255, 255, 255);
	gfx.PutPixel(pwinx + 27, pwiny + 8, 255, 255, 255);
	//Alt kenar
	gfx.PutPixel(pwinx + 26, pwiny + 9, 255, 255, 255);
	gfx.PutPixel(pwinx + 27, pwiny + 9, 255, 255, 255);
	gfx.PutPixel(pwinx + 28, pwiny + 9, 255, 255, 255);
	//N
	//Sol kenar
	gfx.PutPixel(pwinx + 32, pwiny, 255, 255, 255);
	gfx.PutPixel(pwinx + 32, pwiny + 1, 255, 255, 255);
	gfx.PutPixel(pwinx + 32, pwiny + 2, 255, 255, 255);
	gfx.PutPixel(pwinx + 32, pwiny + 3, 255, 255, 255);
	gfx.PutPixel(pwinx + 32, pwiny + 4, 255, 255, 255);
	gfx.PutPixel(pwinx + 32, pwiny + 5, 255, 255, 255);
	gfx.PutPixel(pwinx + 32, pwiny + 6, 255, 255, 255);
	gfx.PutPixel(pwinx + 32, pwiny + 7, 255, 255, 255);
	gfx.PutPixel(pwinx + 32, pwiny + 8, 255, 255, 255);
	gfx.PutPixel(pwinx + 32, pwiny + 9, 255, 255, 255);
	//Çapraz kenar
	gfx.PutPixel(pwinx + 32, pwiny, 255, 255, 255);
	gfx.PutPixel(pwinx + 33, pwiny + 1, 255, 255, 255);
	gfx.PutPixel(pwinx + 34, pwiny + 2, 255, 255, 255);
	gfx.PutPixel(pwinx + 34, pwiny + 3, 255, 255, 255);
	gfx.PutPixel(pwinx + 35, pwiny + 4, 255, 255, 255);
	gfx.PutPixel(pwinx + 35, pwiny + 5, 255, 255, 255);
	gfx.PutPixel(pwinx + 36, pwiny + 6, 255, 255, 255);
	gfx.PutPixel(pwinx + 36, pwiny + 7, 255, 255, 255);
	gfx.PutPixel(pwinx + 37, pwiny + 8, 255, 255, 255);
	gfx.PutPixel(pwinx + 37, pwiny + 9, 255, 255, 255);
	//Sað kenar
	gfx.PutPixel(pwinx + 38, pwiny, 255, 255, 255);
	gfx.PutPixel(pwinx + 38, pwiny + 1, 255, 255, 255);
	gfx.PutPixel(pwinx + 38, pwiny + 2, 255, 255, 255);
	gfx.PutPixel(pwinx + 38, pwiny + 3, 255, 255, 255);
	gfx.PutPixel(pwinx + 38, pwiny + 4, 255, 255, 255);
	gfx.PutPixel(pwinx + 38, pwiny + 5, 255, 255, 255);
	gfx.PutPixel(pwinx + 38, pwiny + 6, 255, 255, 255);
	gfx.PutPixel(pwinx + 38, pwiny + 7, 255, 255, 255);
	gfx.PutPixel(pwinx + 38, pwiny + 8, 255, 255, 255);
	gfx.PutPixel(pwinx + 38, pwiny + 9, 255, 255, 255);
}

void Game::DrawP2Win()
{
	//P
	//Sol kenar
	gfx.PutPixel(p2winx, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx, p2winy + 1, 255, 255, 255);
	gfx.PutPixel(p2winx, p2winy + 2, 255, 255, 255);
	gfx.PutPixel(p2winx, p2winy + 3, 255, 255, 255);
	gfx.PutPixel(p2winx, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx, p2winy + 5, 255, 255, 255);
	gfx.PutPixel(p2winx, p2winy + 6, 255, 255, 255);
	gfx.PutPixel(p2winx, p2winy + 7, 255, 255, 255);
	gfx.PutPixel(p2winx, p2winy + 8, 255, 255, 255);
	gfx.PutPixel(p2winx, p2winy + 9, 255, 255, 255);
	//Üst kenar	  
	gfx.PutPixel(p2winx + 1, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx + 2, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx + 3, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx + 4, p2winy, 255, 255, 255);
	//Sað kenar	  			 
	gfx.PutPixel(p2winx + 4, p2winy + 1, 255, 255, 255);
	gfx.PutPixel(p2winx + 4, p2winy + 2, 255, 255, 255);
	gfx.PutPixel(p2winx + 4, p2winy + 3, 255, 255, 255);
	gfx.PutPixel(p2winx + 4, p2winy + 4, 255, 255, 255);
	//Alt kenar	  			  
	gfx.PutPixel(p2winx + 3, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx + 2, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx + 1, p2winy + 4, 255, 255, 255);
	//2
	//Üst kenar			  			  
	gfx.PutPixel(p2winx + 8, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx + 9, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx + 10, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx + 11, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx + 12, p2winy, 255, 255, 255);
	//Sað kenar
	gfx.PutPixel(p2winx + 12, p2winy + 1, 255, 255, 255);
	gfx.PutPixel(p2winx + 12, p2winy + 2, 255, 255, 255);
	gfx.PutPixel(p2winx + 12, p2winy + 3, 255, 255, 255);
	//Orta kenar
	gfx.PutPixel(p2winx + 12, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx + 11, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx + 10, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx +  9, p2winy + 4, 255, 255, 255);
	//Sol kenar
	gfx.PutPixel(p2winx + 8, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx + 8, p2winy + 5, 255, 255, 255);
	gfx.PutPixel(p2winx + 8, p2winy + 6, 255, 255, 255);
	gfx.PutPixel(p2winx + 8, p2winy + 7, 255, 255, 255);
	gfx.PutPixel(p2winx + 8, p2winy + 8, 255, 255, 255);
	//Alt kenar
	gfx.PutPixel(p2winx + 8, p2winy + 9, 255, 255, 255);
	gfx.PutPixel(p2winx + 9, p2winy + 9, 255, 255, 255);
	gfx.PutPixel(p2winx + 10, p2winy + 9, 255, 255, 255);
	gfx.PutPixel(p2winx + 11, p2winy + 9, 255, 255, 255);
	gfx.PutPixel(p2winx + 12, p2winy + 9, 255, 255, 255);





	//W			  
	//Sol kenar	  
	gfx.PutPixel(p2winx +10 + 16, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 16, p2winy + 1, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 16, p2winy + 2, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 16, p2winy + 3, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 16, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 16, p2winy + 5, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 16, p2winy + 6, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 16, p2winy + 7, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 16, p2winy + 8, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 16, p2winy + 9, 255, 255, 255);
	//Orta kýsým  		 
	gfx.PutPixel(p2winx +10 + 17, p2winy + 8, 255, 255, 255);
				  		 
	gfx.PutPixel(p2winx +10 + 18, p2winy + 7, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 18, p2winy + 6, 255, 255, 255);
				  	  	 
	gfx.PutPixel(p2winx +10 + 19, p2winy + 5, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 19, p2winy + 4, 255, 255, 255);
				  	  	 
	gfx.PutPixel(p2winx +10 + 20, p2winy + 7, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 20, p2winy + 6, 255, 255, 255);
				  	  	 
	gfx.PutPixel(p2winx +10 + 21, p2winy + 8, 255, 255, 255);
	//Sað kenar	  	 	 
	gfx.PutPixel(p2winx +10 + 22, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 22, p2winy + 1, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 22, p2winy + 2, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 22, p2winy + 3, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 22, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 22, p2winy + 5, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 22, p2winy + 6, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 22, p2winy + 7, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 22, p2winy + 8, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 22, p2winy + 9, 255, 255, 255);
	//I			  	  	 
	//Üst kenar	  	  	 
	gfx.PutPixel(p2winx +10 + 26, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 27, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 28, p2winy, 255, 255, 255);
	//Orta kenar  	 	 
	gfx.PutPixel(p2winx +10 + 27, p2winy + 1, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 27, p2winy + 2, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 27, p2winy + 3, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 27, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 27, p2winy + 5, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 27, p2winy + 6, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 27, p2winy + 7, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 27, p2winy + 8, 255, 255, 255);
	//Alt kenar	  		   
	gfx.PutPixel(p2winx +10 + 26, p2winy + 9, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 27, p2winy + 9, 255, 255, 255);
	gfx.PutPixel(p2winx +10 + 28, p2winy + 9, 255, 255, 255);
	//N			 			   
	//Sol kenar	  			   
	gfx.PutPixel(p2winx + 10 + 32, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 32, p2winy + 1, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 32, p2winy + 2, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 32, p2winy + 3, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 32, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 32, p2winy + 5, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 32, p2winy + 6, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 32, p2winy + 7, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 32, p2winy + 8, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 32, p2winy + 9, 255, 255, 255);
	//Çapraz kenar			    
	gfx.PutPixel(p2winx + 10 + 32, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 33, p2winy + 1, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 34, p2winy + 2, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 34, p2winy + 3, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 35, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 35, p2winy + 5, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 36, p2winy + 6, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 36, p2winy + 7, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 37, p2winy + 8, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 37, p2winy + 9, 255, 255, 255);
	//Sað kenar	  			   
	gfx.PutPixel(p2winx + 10 + 38, p2winy, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 38, p2winy + 1, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 38, p2winy + 2, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 38, p2winy + 3, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 38, p2winy + 4, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 38, p2winy + 5, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 38, p2winy + 6, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 38, p2winy + 7, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 38, p2winy + 8, 255, 255, 255);
	gfx.PutPixel(p2winx + 10 + 38, p2winy + 9, 255, 255, 255);
}

void Game::DrawPlayer(){
	//Y 1. sütun
	gfx.PutPixel(playerx, playery, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 1, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 2, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 3, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 4, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 5, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 6, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 7, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 8, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 9, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 10, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 11, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 12, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 13, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 14, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 15, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 16, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 17, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 18, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 19, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 20, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 21, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 22, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 23, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 24, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 25, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 26, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 27, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 28, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 29, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 30, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 31, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 32, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 33, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 34, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 35, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 36, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 37, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 38, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 39, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 40, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 41, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 42, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 43, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 44, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 45, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 46, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 47, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 48, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 49, 255, 255, 255);
	gfx.PutPixel(playerx, playery + 50, 255, 255, 255);
	//y 2. sütun
	gfx.PutPixel(playerx + 1, playery, 255, 255, 255);
	gfx.PutPixel(playerx + 1, playery + 50, 255, 255, 255);
	//3. sütun
	gfx.PutPixel(playerx + 2, playery, 255, 255, 255);
	gfx.PutPixel(playerx + 2, playery + 50, 255, 255, 255);
	//4. sütun
	gfx.PutPixel(playerx + 3, playery, 255, 255, 255);
	gfx.PutPixel(playerx + 3, playery + 50, 255, 255, 255);
	//5. sütun
	gfx.PutPixel(playerx + 4, playery, 255, 255, 255);
	gfx.PutPixel(playerx + 4, playery + 50, 255, 255, 255);
	//6. Sütun
	gfx.PutPixel(playerx + 5, playery, 255, 255, 255);
	gfx.PutPixel(playerx + 5, playery + 50, 255, 255, 255);
	//7. Sütun
	gfx.PutPixel(playerx + 6, playery, 255, 255, 255);
	gfx.PutPixel(playerx + 6, playery + 50, 255, 255, 255);
	//8. sütun
	gfx.PutPixel(playerx + 7, playery, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 1, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 2, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 3, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 4, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 5, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 6, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 7, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 8, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 9, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 10, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 11, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 12, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 13, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 14, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 15, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 16, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 17, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 18, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 19, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 20, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 21, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 22, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 23, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 24, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 25, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 26, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 27, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 28, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 29, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 30, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 31, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 32, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 33, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 34, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 35, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 36, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 37, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 38, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 39, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 40, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 41, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 42, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 43, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 44, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 45, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 46, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 47, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 48, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 49, 255, 255, 255);
	gfx.PutPixel(playerx + 7, playery + 50, 255, 255, 255);
}

void Game::DrawPlayer2()
{
	//Y 1. sütun
	gfx.PutPixel(player2x, player2y, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 1, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 2, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 3, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 4, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 5, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 6, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 7, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 8, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 9, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 10, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 11, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 12, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 13, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 14, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 15, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 16, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 17, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 18, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 19, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 20, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 21, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 22, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 23, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 24, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 25, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 26, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 27, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 28, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 29, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 30, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 31, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 32, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 33, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 34, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 35, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 36, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 37, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 38, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 39, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 40, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 41, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 42, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 43, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 44, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 45, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 46, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 47, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 48, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 49, 255, 255, 255);
	gfx.PutPixel(player2x, player2y + 50, 255, 255, 255);
	//y 2. sütun
	gfx.PutPixel(player2x + 1, player2y, 255, 255, 255);
	gfx.PutPixel(player2x + 1, player2y + 50, 255, 255, 255);
	//3. sütun		   				 
	gfx.PutPixel(player2x + 2, player2y, 255, 255, 255);
	gfx.PutPixel(player2x + 2, player2y + 50, 255, 255, 255);
	//4. sütun		   				 
	gfx.PutPixel(player2x + 3, player2y, 255, 255, 255);
	gfx.PutPixel(player2x + 3, player2y + 50, 255, 255, 255);
	//5. sütun		   				 
	gfx.PutPixel(player2x + 4, player2y, 255, 255, 255);
	gfx.PutPixel(player2x + 4, player2y + 50, 255, 255, 255);
	//6. Sütun		   				 
	gfx.PutPixel(player2x + 5, player2y, 255, 255, 255);
	gfx.PutPixel(player2x + 5, player2y + 50, 255, 255, 255);
	//7. Sütun		   				 
	gfx.PutPixel(player2x + 6, player2y, 255, 255, 255);
	gfx.PutPixel(player2x + 6, player2y + 50, 255, 255, 255);
	//8. sütun		   				 
	gfx.PutPixel(player2x + 7, player2y, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 1, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 2, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 3, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 4, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 5, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 6, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 7, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 8, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 9, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 10, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 11, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 12, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 13, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 14, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 15, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 16, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 17, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 18, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 19, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 20, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 21, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 22, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 23, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 24, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 25, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 26, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 27, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 28, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 29, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 30, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 31, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 32, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 33, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 34, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 35, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 36, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 37, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 38, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 39, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 40, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 41, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 42, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 43, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 44, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 45, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 46, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 47, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 48, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 49, 255, 255, 255);
	gfx.PutPixel(player2x + 7, player2y + 50, 255, 255, 255);
}

void Game::DrawNet()
{
	gfx.PutPixel(netx, nety + 89, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 90, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 91, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 92, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 93, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 94, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 95, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 96, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 97, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 98, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 99, netred, netgreen, netblue);

	gfx.PutPixel(netx, nety + 169, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 170, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 171, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 172, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 173, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 174, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 175, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 176, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 177, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 178, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 179, netred, netgreen, netblue);

	gfx.PutPixel(netx, nety + 259, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 260, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 261, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 262, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 263, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 264, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 265, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 266, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 267, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 268, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 269, netred, netgreen, netblue);

	gfx.PutPixel(netx, nety + 349, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 350, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 351, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 352, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 353, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 354, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 355, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 356, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 357, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 358, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 359, netred, netgreen, netblue);

	gfx.PutPixel(netx, nety + 439, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 440, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 441, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 442, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 443, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 444, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 445, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 446, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 447, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 448, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 449, netred, netgreen, netblue);

	gfx.PutPixel(netx, nety + 529, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 530, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 531, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 532, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 533, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 534, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 535, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 536, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 537, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 538, netred, netgreen, netblue);
	gfx.PutPixel(netx, nety + 539, netred, netgreen, netblue);
}

void Game::DrawZero(int x, int y)
{	
	//Üst Kenar
	gfx.PutPixel(x - 15, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 14, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 13, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 12, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 11, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 10, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  9, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  8, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  7, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  6, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  5, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  4, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  3, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  2, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  1, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  0, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  1, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  2, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  3, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  4, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  5, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  6, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  7, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  8, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  9, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 10, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 11, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 12, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 13, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 14, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 25, scorered, scoregreen, scoreblue);
	//Sol kenar
	gfx.PutPixel(x - 15, y - 24, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 23, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 22, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 21, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 20, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 19, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 18, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 17, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 16, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 15, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 14, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 13, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 12, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 11, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y - 10, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y -  9, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y -  8, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y -  7, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y -  6, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y -  5, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y -  4, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y -  3, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y -  2, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y -  1, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y -  0, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y +  1, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y +  2, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y +  3, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y +  4, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y +  5, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y +  6, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y +  7, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y +  8, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y +  9, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 10, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 11, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 12, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 13, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 14, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 15, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 16, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 17, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 18, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 19, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 20, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 21, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 22, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 23, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 24, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 25, scorered, scoregreen, scoreblue);
	//Sað kenar
	gfx.PutPixel(x + 15, y - 24, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 23, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 22, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 21, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 20, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 19, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 18, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 17, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 16, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 15, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 14, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 13, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 12, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 11, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 10, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 9, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 8, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 7, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 6, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 5, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 4, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 3, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 2, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 1, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 0, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 1, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 2, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 3, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 4, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 5, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 6, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 7, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 8, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 9, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 10, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 11, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 12, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 13, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 14, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 15, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 16, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 17, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 18, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 19, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 20, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 21, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 22, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 23, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 24, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 25, scorered, scoregreen, scoreblue);
	//Alt kenar
	gfx.PutPixel(x - 15, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 14, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 13, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 12, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 11, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 10, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  9, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  8, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  7, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  6, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  5, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  4, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  3, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  2, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  1, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  0, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  1, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  2, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  3, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  4, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  5, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  6, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  7, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  8, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  9, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 10, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 11, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 12, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 13, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 14, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 25, scorered, scoregreen, scoreblue);
}

void Game::DrawOne(int x, int y)
{
	gfx.PutPixel(x, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 24, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 23, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 22, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 21, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 20, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 19, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 18, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 17, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 16, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 15, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 14, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 13, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 12, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 11, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 10, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 9, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 8, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 7, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 6, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 5, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 4, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 3, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 2, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 1, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y - 0, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 1, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 2, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 3, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 4, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 5, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 6, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 7, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 8, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 9, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 10, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 11, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 12, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 13, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 14, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 15, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 16, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 17, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 18, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 19, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 20, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 21, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 22, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 23, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 24, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x, y + 25, scorered, scoregreen, scoreblue);



}

void Game::DrawTwo(int x, int y)
{
	//Üst Kenar
	gfx.PutPixel(x - 15, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 14, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 13, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 12, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 11, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 10, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 9, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 8, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 7, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 6, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 5, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 4, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 3, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 2, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 1, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 0, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 1, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 2, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 3, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 4, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 5, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 6, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 7, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 8, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 9, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 10, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 11, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 12, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 13, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 14, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 25, scorered, scoregreen, scoreblue);
	//Sað kenar
	gfx.PutPixel(x + 15, y - 24, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 23, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 22, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 21, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 20, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 19, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 18, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 17, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 16, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 15, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 14, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 13, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 12, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 11, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 10, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 9, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 8, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 7, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 6, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 5, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 4, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 3, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 2, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 1, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 0, scorered, scoregreen, scoreblue);
	//Orta kenar
	gfx.PutPixel(x - 15, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 14, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 13, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 12, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 11, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 10, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  9, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  8, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  7, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  6, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  5, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  4, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  3, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  2, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  1, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x -  0, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  1, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  2, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  3, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  4, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  5, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  6, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  7, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  8, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x +  9, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 10, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 11, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 12, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 13, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 14, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y, scorered, scoregreen, scoreblue);
	//Sol kenar
	gfx.PutPixel(x - 15, y + 1, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 2, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 3, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 4, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 5, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 6, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 7, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 8, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 9, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 10, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 11, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 12, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 13, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 14, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 15, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 16, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 17, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 18, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 19, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 20, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 21, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 22, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 23, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 24, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 15, y + 25, scorered, scoregreen, scoreblue);
	//Alt kenar
	gfx.PutPixel(x - 15, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 14, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 13, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 12, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 11, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 10, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 9, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 8, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 7, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 6, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 5, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 4, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 3, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 2, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 1, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 0, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 1, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 2, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 3, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 4, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 5, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 6, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 7, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 8, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 9, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 10, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 11, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 12, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 13, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 14, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 25, scorered, scoregreen, scoreblue);
}

void Game::DrawThree(int x, int y)
{
	//Üst kenar
	gfx.PutPixel(x - 15, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 14, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 13, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 12, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 11, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 10, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 9, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 8, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 7, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 6, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 5, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 4, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 3, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 2, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 1, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 0, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 1, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 2, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 3, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 4, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 5, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 6, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 7, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 8, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 9, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 10, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 11, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 12, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 13, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 14, y - 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 25, scorered, scoregreen, scoreblue);
	//Sað üst kenar
	gfx.PutPixel(x + 15, y - 24, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 23, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 22, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 21, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 20, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 19, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 18, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 17, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 16, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 15, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 14, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 13, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 12, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 11, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 10, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 9, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 8, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 7, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 6, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 5, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 4, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 3, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 2, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y - 1, scorered, scoregreen, scoreblue);
	//Orta kenar
	gfx.PutPixel(x - 15, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 14, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 13, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 12, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 11, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 10, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 9, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 8, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 7, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 6, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 5, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 4, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 3, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 2, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 1, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 0, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 1, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 2, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 3, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 4, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 5, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 6, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 7, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 8, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 9, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 10, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 11, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 12, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 13, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 14, y, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y, scorered, scoregreen, scoreblue);
	//Sað alt kenar
	gfx.PutPixel(x + 15, y + 1, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 2, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 3, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 4, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 5, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 6, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 7, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 8, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 9, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 10, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 11, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 12, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 13, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 14, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 15, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 16, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 17, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 18, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 19, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 20, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 21, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 22, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 23, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 24, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 25, scorered, scoregreen, scoreblue);
	//Alt kenar
	gfx.PutPixel(x - 15, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 14, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 13, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 12, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 11, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 10, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 9, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 8, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 7, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 6, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 5, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 4, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 3, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 2, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 1, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x - 0, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 1, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 2, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 3, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 4, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 5, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 6, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 7, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 8, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 9, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 10, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 11, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 12, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 13, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 14, y + 25, scorered, scoregreen, scoreblue);
	gfx.PutPixel(x + 15, y + 25, scorered, scoregreen, scoreblue);
}

void Game::DrawScore()
{
	if (playerscore == 0) {
		DrawZero(playerscorex, playerscorey);
	}
	if (playerscore == 1) {
		DrawOne(playerscorex, playerscorey);
	}
	if (playerscore == 2) {
		DrawTwo(playerscorex, playerscorey);
	}
	if (playerscore == 3) {
		DrawThree(playerscorex, playerscorey);
		Stop();
		DrawP1Win();
		DrawStart(185, 300);
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			Reset();
		}
	}
	if (player2score == 0) {
		DrawZero(player2scorex, player2scorey);
	}
	if (player2score == 1) {
		DrawOne(player2scorex, player2scorey);
	}
	if (player2score == 2) {
		DrawTwo(player2scorex, player2scorey);
	}
	if (player2score == 3) {
		DrawThree(player2scorex, player2scorey);
		Stop();
		DrawP2Win();
		DrawStart(p2winx - 10, p2winy + 25);
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			Reset();
		}
	}
}

void Game::DrawBall()
{
	//Üst kenar
	gfx.PutPixel(ballx, bally, 255, 255, 255);
	gfx.PutPixel(ballx + 1, bally, 255, 255, 255);
	gfx.PutPixel(ballx + 2, bally, 255, 255, 255);
	gfx.PutPixel(ballx + 3, bally, 255, 255, 255);
	gfx.PutPixel(ballx + 4, bally, 255, 255, 255);
	//Sol kenar
	gfx.PutPixel(ballx, bally + 1, 255, 255, 255);
	gfx.PutPixel(ballx, bally + 2, 255, 255, 255);
	gfx.PutPixel(ballx, bally + 3, 255, 255, 255);
	gfx.PutPixel(ballx, bally + 4, 255, 255, 255);
	//Sað kenar
	gfx.PutPixel(ballx + 4, bally + 1, 255, 255, 255);
	gfx.PutPixel(ballx + 4, bally + 2, 255, 255, 255);
	gfx.PutPixel(ballx + 4, bally + 3, 255, 255, 255);
	gfx.PutPixel(ballx + 4, bally + 4, 255, 255, 255);
	//Alt kenar
	gfx.PutPixel(ballx + 1, bally + 4, 255, 255, 255);
	gfx.PutPixel(ballx + 2, bally + 4, 255, 255, 255);
	gfx.PutPixel(ballx + 3, bally + 4, 255, 255, 255);
}

void Game::MoveBall()
{
	ballx += ballxspeed;
	bally += ballyspeed;
	ballx = ClampScreenX(ballx, ballwidth);
	bally = ClampScreenY(bally, ballheight);
	if (ballx == gfx.ScreenWidth - 1 - ballwidth) {
		ballx = 400;
		bally = 0;
		ballxspeed = -ballxspeed;
		ballyspeed = -ballyspeed;
		playerscore += 1;
	}
	if (ballx == 0) {
		ballx = 400;
		bally = 0;
		ballxspeed = -ballxspeed;
		ballyspeed = -ballyspeed;
		player2score += 1;
	}
	if (bally == 0) {
		ballyspeed = -ballyspeed;
	}
	if (bally == gfx.ScreenHeight - 1 - ballheight) {
		ballyspeed = -ballyspeed;
	}
	if (IsColliding(ballx, bally, ballwidth, ballheight, playerx, playery, playerwidth, playerheight)) {
		ballxspeed = -ballxspeed;
	}
	if (IsColliding(ballx, bally, ballwidth, ballheight, player2x, player2y, playerwidth, playerheight)) {
		ballxspeed = -ballxspeed;
	}
}

int Game::ClampScreenX(int x, int width)
{
	const int right = x + width;
	if (x < 0) {
		return 0;
	}
	else if (right >= gfx.ScreenWidth) {
		return(gfx.ScreenWidth - 1) - width;
	}
	else {
		return x;
	}
}

int Game::ClampScreenY(int y, int height)
{
	const int bottom = y + height;
	if (y < 0) {
		return 0;
	}
	else if (bottom >= gfx.ScreenHeight) {
		return(gfx.ScreenHeight - 1) - height;
	}
	else {
		return y;
	}
}

bool Game::IsColliding(int x0, int y0, int width0, int height0, int x1, int y1, int width1, int height1)
{
	const int right0 = x0 + width0;
	const int bottom0 = y0 + height0;
	const int right1 = x1 + width1;
	const int bottom1 = y1 + height1;
	return
		right0 >= x1 && x0 <= right1 && bottom0 >= y1 && y0 <= bottom1;
}

void Game::Reset()
{
	playerscore = 0;
	player2score = 0;
	playerx = 80;
	playery = 275;
	player2x = gfx.ScreenWidth - 80;
	player2y = playery;
	ballxspeed = 3;
	ballyspeed = 3;
	playerspeed = 4;
}

void Game::Stop()
{
	ballxspeed = 0;
	ballyspeed = 0;
	playerspeed = 0;
}
