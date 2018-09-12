// Included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>


// entry point for the program
int main()
{

	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", 
		sf::Style::Titlebar | sf::Style::Close);

	// Create Button Sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	

	// Center the button sprite on the screen
	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2);

    //Create Music
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	//gameMusic.play();

	// Create Text
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");
	
	// Create Title
	sf::Text titleText;
	(titleText).setFont(gameFont);
	titleText.setString("Button Masher!");
	titleText.setCharacterSize(50);
	titleText.setFillColor(sf::Color::Cyan);
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);
	titleText.setPosition(
		gameWindow.getSize().x / 2 - titleText.getLocalBounds().width / 2,30);
	
	sf::Text authorText;
	(authorText).setFont(gameFont);
	authorText.setString("By Ben Paragreen");
	authorText.setPosition(
		gameWindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, 75);

	// Score
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setPosition(20, 30);

	//Timer Text
	sf::Text timerText;
	timerText.setFont(gameFont);
	timerText.setString("Time Remaining: 0");
	timerText.setFillColor(sf::Color::White);
	timerText.setPosition(gameWindow.getSize().x -30 - timerText.getLocalBounds().width , 30);

	//Timer Functionality
	sf::Time timeLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;

	// Game Loop
	// Runs every frame until the game window is closed
	while (gameWindow.isOpen())
	{
		// Check for input
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			// Process events

			//check if mouse button is pressed
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y);

				score = score + 1;

			}

			// Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				// Close the game window
				gameWindow.close();
			}
		}

		// Update game state
		sf::Time frameTime = gameClock.restart();
		timeRemaining = timeRemaining - frameTime;
		timerText.setString("Time Remaining: " + std::to_string((int)std::ceilf(timeRemaining.asSeconds())));

		scoreText.setString("Score: " + std::to_string(score));

	
		// Clear window to a single color
		gameWindow.clear(sf::Color::Black);

		// Draw Everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		gameWindow.draw(scoreText);
		gameWindow.draw(timerText);

		// Display window contents on the screen
		gameWindow.display();
	}

	// exit point for the program
	return 0;
}