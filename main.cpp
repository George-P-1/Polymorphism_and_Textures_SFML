#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>

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

    // Practice 9 - Textures/Sprite
    // Grass
    sf::Texture texture_grass;
    if (!texture_grass.loadFromFile("grass.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Sprite sprite_grass;
    sprite_grass.setTexture(texture_grass);

    // Assignment 9
    // Wall
    sf::Texture texture_wall;
    if (!texture_wall.loadFromFile("wall.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Sprite sprite_wall;
    sprite_wall.setTexture(texture_wall);
//    sprite_wall.setScale(2.0, 2.0);
    sprite_wall.setScale(1.0, 1.0);
    sprite_wall.setPosition(400.0, 300.0);
    // Guy
    sf::Texture texture_guy;
    if (!texture_guy.loadFromFile("guy.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Sprite sprite_guy;
    sprite_guy.setTexture(texture_guy);
    sprite_guy.setPosition(150.0, 400.0);

    // Practice 10 - Fragment of Texture
//    sf::Texture texture_guy;
//    if(!texture_guy.loadFromFile("guy.png")) { return 1; }
    sf::Sprite guy;
    guy.setTexture(texture_guy);
    guy.setTextureRect(sf::IntRect(10, 20, 20, 15)); //left, top, width, height
    guy.setPosition(50.0, 50.0);

    // Practice 10 - Repeated Property
//    sf::Texture texture_wall;
//    if(!texture_wall.loadFromFile("wall.png")) { return 1; }
    texture_wall.setRepeated(true);
    sf::Sprite wall;
    wall.setTexture(texture_wall);
    wall.setScale(0.3, 0.3);
    wall.setTextureRect(sf::IntRect(0, 0, 1000, 1000));
    wall.setPosition(400.0, 100.0);

    // Assignment 10
    texture_grass.setRepeated(true);
    sf::Sprite grass;
    grass.setTexture(texture_grass);
//    grass.setScale(1.0, 1.0);
    grass.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // Assignment 8
//        for(auto &s : shapes)
//        {
//            window.draw(*s);
//        }
        // Practice 9 - Texture/Sprite
//        window.draw(sprite_grass);

        // Assignment 10
        window.draw(grass); // Draw grass background first

        // Assignment 9
        window.draw(sprite_wall);
        window.draw(sprite_guy);
        // Practice 10
        window.draw(guy);
        window.draw(wall);

        // end the current frame
        window.display();
    }

    std::cout << "\nDone!!\n\n";

    return 0;
}
