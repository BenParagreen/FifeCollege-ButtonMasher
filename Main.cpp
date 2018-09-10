// Included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



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
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

    //Create Music
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	//gameMusic.play();

	// Create Text
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");
	
	// Create Title
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Button Masher!");
	titleText.setPosition(
		gameWindow.getSize().x / 2 - titleText.getLocalBounds().width / 2,30);


	// Game Loop
	// Runs every frame until the game window is closed
	while (gameWindow.isOpen())
	{
		// Check for input
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			// Process events

			// Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				// Close the game window
				gameWindow.close();
			}
		}

		// TODO: Update game state

		// TODO: Draw graphics
		// Clear window to a single color
		gameWindow.clear(sf::Color::Black);

		// Draw Everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);

		// Display window contents on the screen
		gameWindow.display();
	}

	// exit point for the program
	return 0;
}