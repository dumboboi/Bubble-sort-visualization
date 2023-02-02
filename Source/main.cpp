#include <time.h>
#include <vector>
#include <Headers/Global.hpp>
#include <SFML/Graphics.hpp>
#include <Headers/Bars.hpp>


int main()
{
    srand((int) time(NULL));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Bubble sort Visualization");
    sf::Event event;
    Bars bars;
    int i = 0;unsigned short time = 1200;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        bars.Draw(window);
        if(!bars.sorted())
        {
            bars.bubble_sort(i);
            bars.Fix_Position();
        }else
        {
            bars.bubble_wins();
            if(Exit(time))
            {
                window.close();
            }
        }
        window.display();
    }

    return EXIT_SUCCESS;
}
