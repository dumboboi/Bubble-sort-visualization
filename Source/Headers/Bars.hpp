#ifndef BARS_HPP
#define BARS_HPP
#include <SFML/Graphics.hpp>

class Bars
{
    public:
        //Constructor/destructor
        Bars();
        virtual ~Bars();

    public:
        //Functions
        void Load_bars();
        void Draw(sf::RenderWindow& window);
        void bubble_sort(int &i);
        void Fix_Position();
        //check if bars are sorted
        bool sorted();

    private:
        //Variables
        sf::Vector2f sz;
        std::vector<sf::RectangleShape> rectangles;
        std::vector<sf::Vector2f> cordsvect;
        int n = 105;
        int d = 0
};

#endif // BARS_HPP
