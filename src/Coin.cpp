#include "Coin.hpp"

Coin::Coin(sf::Vector2f size)
{
    coin.setSize(size);
    coin.setFillColor(sf::Color::Yellow);
}

void Coin::Render(sf::RenderTarget& target) const
{
    target.draw(coin);
}