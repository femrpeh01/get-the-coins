#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <random>
#include "Player.hpp"

int main()
{
    srand(time(NULL));

    //Windowing Stuff
    sf::RenderWindow window;
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445,
     (sf::VideoMode::getDesktopMode().height / 2) - 480);
    window.create(sf::VideoMode(900, 900), "SFML PROJECT", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);

    //Variables
    Player player({40, 50});
    player.setPos({50, 700});

    Coin coin({50, 50});
    coin.SetPos({rand()%int(window.getSize().x - coin.getGB().width), rand()%int(window.getSize().y - (coin.getGB().height + 200))});
    std::cout << coin.getPos().x << " " << coin.getPos().y << std::endl;

    sf::RectangleShape playButton;
    playButton.setFillColor(sf::Color::Cyan);
    playButton.setSize({200, 100});
    playButton.setPosition({window.getSize().x / 2 - 100, window.getSize().y / 2 - 70});

    sf::Font arial;
    arial.loadFromFile("assets/fonts/arial.ttf");

    sf::Text playLabel;
    playLabel.setCharacterSize(50);
    playLabel.setPosition({playButton.getPosition().x + 40, playButton.getPosition().y + 20});
    playLabel.setFont(arial);
    playLabel.setString("PLAY");

    int score = 0;
    int state = 0; // 0 - Main Menu State 1 - Playing State

    std::ostringstream ssScore;
    ssScore << "Score: " << score;

    sf::Text lblScore;
    lblScore.setCharacterSize(30);
    lblScore.setPosition({10, 10});
    lblScore.setFont(arial);
    lblScore.setString(ssScore.str());

    const int groundHeight = 700;
    const float gravitySpeed = 0.3;
    bool isJumping = false;
    const float moveSpeed = 0.2;

    //Main Loop
    while (window.isOpen())
    {
        //Event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                
                if (state == 1)
                {
                    case sf::Event::KeyReleased:
                        if (event.key.code == sf::Keyboard::W)
                        {
                            isJumping = false;
                        }
                }
            }
        }
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (state == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && playButton.getGlobalBounds().contains((sf::Vector2f)mousePos))
        {
            state = 1;
        }

        //Keyboard handling
        if (state == 1)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                state = 0;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.GetY() >= 0)
            {
                player.Move({0, -moveSpeed});
                isJumping = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player.getPos().x <= 850)
            {
                player.Move({moveSpeed, 0});
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player.getPos().x >= 0)
            {
                player.Move({-moveSpeed, 0});
            }

            //Gravity
            if (player.GetY() < groundHeight && isJumping == false)
            {
                player.Move({0, gravitySpeed});
            }

            //Coin logic for the scoring system
            if (player.getGB().intersects(coin.getGB()))
            {
                coin.SetPos({rand()%int(window.getSize().x - coin.getGB().width), rand()%int(window.getSize().y - (coin.getGB().height + 200))});
                std::cout << coin.getPos().x << " " << coin.getPos().y << std::endl;
                score++;
                ssScore.str("");
                ssScore << "Score: " << score;
                lblScore.setString(ssScore.str());
            }
        }

        window.clear();

        if (state == 1)
        {
            coin.Render(window);
            window.draw(lblScore);
            player.Draw(window);
        }
        if (state == 0)
        {
            window.draw(playButton);
            window.draw(playLabel);
        }

        window.display();
    }

    return EXIT_SUCCESS;
}