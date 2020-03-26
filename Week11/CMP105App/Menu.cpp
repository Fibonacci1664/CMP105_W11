#include "Menu.h"


Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud) : Screen(hwnd, in, gs, aud)
{
	setGameState(State::MENU);
}

Menu::~Menu()
{

}

void Menu::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::P))
	{
		setGameState(State::LEVEL);
	}
}

void Menu::update(float dt)
{

}

void Menu::render()
{
	beginDraw();

	endDraw();
}

void Menu::beginDraw()
{
	window->clear(sf::Color(0, 255, 0));
}

void Menu::endDraw()
{
	window->display();
}