/*
 * This class controls all aspects of Input including:
 *		- Keyboard, which keys pressed/released.
 *		- Mouse, buttons pressed & position.
 *
 * Original @author Dr Paul Robertson.
 * Updated by @author D. Green.
 *
 * � D. Green. 2020.
 */

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////

// INCLUDES.
#include "Input.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// CONSTRUCTORS & DESTRUCTOR.
Input::Input()
{
	// set default values
	mouse.left = false;
	mouse.right = false;
	mouse.x = 0;
	mouse.y = 0;
}

Input::~Input()
{
	std::cout << "Input object destroyed!\n";
}


void Input::setKeyDown(int key)
{
	if (key >= 0)
	{
		keys[key] = true;
	}
}

void Input::setKeyUp(int key)
{
	if (key >= 0)
	{
		keys[key] = false;
	}
}

bool Input::isKeyDown(int key)
{
	if (key >= 0)
	{
		return keys[key];
	}
	return false;
}

void Input::setMouseX(int lx)
{
	mouse.x = lx;
}

void Input::setMouseY(int ly)
{
	mouse.y = ly;
}

void Input::setMousePosition(int lx, int ly)
{
	setMouseX(lx);
	setMouseY(ly);
}

int Input::getMouseX()
{
	return mouse.x;
}

int Input::getMouseY()
{
	return mouse.y;
}

void Input::setMouseLDown(bool down)
{
	mouse.left = down;
}
bool Input::isMouseLDown()
{
	return mouse.left;
}

void Input::setMouseRDown(bool down)
{
	mouse.right = down;
}
bool Input::isMouseRDown()
{
	return mouse.right;
}

