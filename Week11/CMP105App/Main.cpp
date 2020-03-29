// Main
// Entry point of the application.
// Handles window creation and window events.
// Contains the game loop, updates input class and contains the level objects.
// @author Paul Robertson

#include <iostream>
#include "Screen.h"
#include "Menu.h"
#include "Level.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Pause.h"


void windowProcess(sf::RenderWindow* window, Input* in)
{
	// Handle window events.
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::Resized:
			window->setView(sf::View(sf::FloatRect(0.f, 0.f, (float)event.size.width, (float)event.size.height)));
			break;
		case sf::Event::KeyPressed:
			// update input class
			in->setKeyDown(event.key.code);
			break;
		case sf::Event::KeyReleased:
			//update input class
			in->setKeyUp(event.key.code);
			break;
		case sf::Event::MouseMoved:
			//update input class
			in->setMousePosition(event.mouseMove.x, event.mouseMove.y);
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//update input class
				in->setMouseLDown(true);
			}
			else if (event.mouseButton.button == sf::Mouse::Right)
			{
				in->setMouseRDown(true);
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//update input class
				in->setMouseLDown(false);
			}
			else if (event.mouseButton.button == sf::Mouse::Right)
			{
				in->setMouseRDown(false);
			}
			break;
		default:
			// don't handle other events
			break;
		}
	}
}

int main()
{
	//Create the window // Initialise input and level objects.
	sf::RenderWindow window(sf::VideoMode(960, 512), "CMP105_W11");
	Input input;
	GameState gameState;
	AudioManager audioManager;

	Menu menu(&window, &input, &gameState, &audioManager);
	Level level(&window, &input, &gameState, &audioManager);
	Pause pause(&window, &input, &gameState, &audioManager);

	// Initialise objects for delta time
	sf::Clock clock;
	float deltaTime;

	// Game Loop
	while (window.isOpen())
	{
		//Process window events
		windowProcess(&window, &input);

		// Calculate delta time. How much time has passed 
		// since it was last calculated (in seconds) and restart the clock.
		deltaTime = clock.restart().asSeconds();

		switch (gameState.getCurrentState())
		{
			case(State::MENU) :
				menu.handleInput(deltaTime);
				menu.update(deltaTime);
				menu.render();
				break;
			case(State::LEVEL) :
				level.handleInput(deltaTime);
				level.update(deltaTime);
				level.render();
				break;
			case(State::PAUSE):
				pause.handleInput(deltaTime);
				pause.update(deltaTime);
				pause.render();
				break;
		}
	}
}