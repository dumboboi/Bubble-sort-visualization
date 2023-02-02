#include "Headers/Bars.hpp"
#include <Headers/Global.hpp>
Bars::Bars()
{
    Load_bars();
}

void Bars::Load_bars()
{
    float xpos=BAR_WIDTH;
    sz.x = BAR_WIDTH;
    for(int i = 0 ; i < n; i++)
    {
        sz.y = rand()%(HEIGHT - 100);
        sf::Vector2f temp(xpos,sz.y);
        cordsvect.push_back(temp);
        sf::RectangleShape rectangle(sz);
        rectangle.setPosition(xpos,HEIGHT - cordsvect[i].y);
        rectangles.push_back(rectangle);
        xpos+= (BAR_WIDTH*1.5f);
    }
}



void Bars::Draw(sf::RenderWindow& window)
{
    for(auto &b:rectangles)
    {
        window.draw(b);
    }
}
Bars::~Bars()
{
    //dtor
}

void Bars::Fix_Position()
{
    for (int i = 0; i < n; i++)
    {
        rectangles[i].setPosition(cordsvect[i].x,HEIGHT - cordsvect[i].y);
    }
}

void Bars::bubble_sort(int &i)
{
        if (i   >=  n-1)
        {
            i = 0;
        }
        else
        {
            if((cordsvect[i].y)>(cordsvect[i+1].y))
            {
                std::swap(rectangles[i],rectangles[i+1]  );
                std::swap(cordsvect[i].y,cordsvect[i +1].y);
            }
            i++;
        }
}
bool Bars::sorted()
{
    if(n==1 || n==0)
        return true;
    for (int b = 1 ; b < n ;b++)
    {
        if((cordsvect[b].y)< (cordsvect[b-1].y))
        {
            return false;
        }
    }
return true;
}

void Bars::bubble_wins()
{
    if(d<n)
    {
        rectangles[d].setFillColor(sf::Color::Green);
        d++;
    }
}
