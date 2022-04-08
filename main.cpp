#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

// Assignment 8
void create_shapes(std::vector<std::unique_ptr<sf::Drawable>> &shapes_vec)
{
    std::unique_ptr<sf::CircleShape> circle = std::make_unique<sf::CircleShape>(100.0);
    circle->setPosition(100.0, 300.0);
    circle->setFillColor(sf::Color(100, 250, 50));

    std::unique_ptr<sf::RectangleShape> rectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f(120.0, 60.0));
    rectangle->setPosition(500.0, 400.0);
//    (*rectangle).setPosition(500.0, 400.0); // Same as using ->
    rectangle->setFillColor(sf::Color(100, 50, 250));

    auto triangle = std::make_unique<sf::ConvexShape>(); // Use auto to make things simpler
    triangle->setPointCount(3);
    triangle->setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle->setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle->setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle->setOutlineColor(sf::Color::Red);
    triangle->setOutlineThickness(5);
    triangle->setPosition(600.0, 100.0);

    // emplace shapes to vector
    shapes_vec.emplace_back(std::move(circle));
    shapes_vec.emplace_back(std::move(rectangle));
    shapes_vec.emplace_back(std::move(triangle));
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes
    // Assignment 8 - Vector of sf::Drawable
    std::vector<std::unique_ptr<sf::Drawable>> shapes;
    create_shapes(shapes);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // Assignment 8
        for(auto &s : shapes)
        {
            window.draw(*s);
        }

        // end the current frame
        window.display();
    }

    return 0;
}
