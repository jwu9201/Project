#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

int findFibonnaciNumber(int);

void drawShape(int, double);

void drawGraph();

int initialx = 11;
double initialradius = 1;

int scale = 4;

int windowsize = 720;

sf::RenderWindow window(sf::VideoMode(windowsize, windowsize), "Problem 4.1");
sf::CircleShape circle;
sf::VertexArray lines(sf::LineStrip, 11);

int main()
{
    circle.setOutlineThickness(2);
    circle.setOutlineColor(sf::Color::Black);
    circle.setFillColor(sf::Color::Black);
    circle.setPosition(-initialradius * scale, -initialradius * scale);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        drawGraph();
        //because of how the draw function in this library works my x axis needs to be inverse, function is effectively drawShape(x,y,radius)
        drawShape(-initialx, initialradius);
        window.draw(lines);
        window.display();
    }
    return 0;
}

int findFibonnaciNumber(int n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else {
        return findFibonnaciNumber(n - 2) + findFibonnaciNumber(n - 1);
    }
}


void drawShape(int x, double radius) {
    int y = findFibonnaciNumber(-x);
    circle.setOrigin(x * scale * 10 - (windowsize / 6), y * scale - (5 * windowsize / 6));
    //moves the origin to the center of the window then adds the x,y components
    //function is effectively position = (x,y)
    circle.setRadius(radius);
    window.draw(circle);
    lines[-x - 1].position = sf::Vector2f(windowsize / 6 - x * scale * 10 - radius * scale, 5 * windowsize / 6 - y * scale - radius * scale);
    lines[-x - 1].color = sf::Color::Black;
    int newx = x + 1;
    if (newx < 0) {
        drawShape(newx, radius);
    }
    return;
}

//This entire function below only serves to create the layout of the graph and the axises for the image

void drawGraph() {
    sf::RectangleShape graph(sf::Vector2f(windowsize * 0.8, windowsize * 0.8));
    graph.setOutlineThickness(2);
    graph.setOutlineColor(sf::Color::Black);
    graph.setFillColor(sf::Color::Transparent);
    graph.setOrigin(-(windowsize / 2 - windowsize * 0.4), -(windowsize / 2 - windowsize * 0.4));
    window.draw(graph);
}