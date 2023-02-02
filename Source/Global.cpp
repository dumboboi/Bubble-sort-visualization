#include "Headers/Global.hpp"


bool Exit(unsigned short &timer)
{
    if (timer > 0)
    {
        timer--;
        return false;
    }
return true;
}
