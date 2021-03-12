#include "Player.hpp"

Player::Player(const sf::Vector2f size)
{
    player.setSize(size);
    player.setFillColor(sf::Color::Green);
}

void Player::Draw(sf::RenderTarget& target) const
{
    target.draw(player);
}

void Player::Move(const sf::Vector2f pos)
{
    player.setPosition(player.getPosition().x + pos.x, player.getPosition().y + pos.y);
}