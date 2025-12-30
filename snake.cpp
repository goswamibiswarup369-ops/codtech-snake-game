#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(600, 600), "Snake Game");

    RectangleShape snake(Vector2f(20, 20));
    snake.setFillColor(Color::Green);
    snake.setPosition(300, 300);

    Vector2f direction(20, 0);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) direction = {0, -20};
        if (Keyboard::isKeyPressed(Keyboard::Down)) direction = {0, 20};
        if (Keyboard::isKeyPressed(Keyboard::Left)) direction = {-20, 0};
        if (Keyboard::isKeyPressed(Keyboard::Right)) direction = {20, 0};

        snake.move(direction);

        window.clear();
        window.draw(snake);
        window.display();

        sleep(milliseconds(150));
    }
    return 0;
}