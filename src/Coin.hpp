#ifndef COIN_H
#define COIN_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Coin
{
    public:
        Coin(sf::Vector2f size);

        void Render(sf::RenderTarget& target) const;
        inline const sf::FloatRect getGB() const noexcept { return coin.getGlobalBounds(); }
        inline sf::Vector2f getPos() { return coin.getPosition(); }
        inline void SetPos(sf::Vector2f newPos) { coin.setPosition(newPos); }

    private:
        sf::RectangleShape coin;
};

#endif