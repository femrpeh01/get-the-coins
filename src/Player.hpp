#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Coin.hpp"

class Player
{
    public:
        Player(const sf::Vector2f size);

        void Draw(sf::RenderTarget& target) const;
        inline sf::FloatRect getGB() const noexcept { return player.getGlobalBounds(); }
        inline void setPos(const sf::Vector2f newPos) { player.setPosition(newPos); }
        inline sf::Vector2f getPos() const { return player.getPosition(); };
        void Move(const sf::Vector2f pos);
        inline const int GetY() const noexcept { return player.getPosition().y; }

    private:
        sf::RectangleShape player;
};

#endif