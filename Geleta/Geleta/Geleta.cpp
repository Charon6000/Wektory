#include <iostream>
#include <cmath>

#define PI 3.141592653589793238462643383279502884

class Wektor
{
public:
    double x;
    double y;
    double ang;
    double mag;

    void Show(bool t)
    {
        if (!t)
            std::cout << "X:" << " " << ang << ", " << "Y:" << " " << mag<<std::endl;
        else
            std::cout << "X:" << " " << x << ", " << "Y:" << " " << y<<std::endl;
    }

    void UstawKart(double a, double b)
    {
        x = a;
        y = b;

        ang = atan2(y, x) * 180 / PI;
        mag = sqrt(pow(x, 2) + pow(y, 2));
    }

    void UstawBin(double a, double b)
    {
        ang = a;
        mag = b;
        x = mag * cos(ang);
        y = mag * sin(ang);
    }

    Wektor operator+(Wektor& v) const 
    {
        return {x + v.x, y + v.y};
    }

    Wektor operator-(Wektor& v) const
    {
        return {x - v.x, y-v.y};
    }

    Wektor operator*(Wektor& v) const 
    {
        return {x * v.x - y * v.y, x * v.y + y * v.x};
    }

    Wektor operator*(double& l) const
    {
        return { x * l, y * l };
    }
};

int main()
{
    double x, y;
    Wektor v1;
    std::cin >> x >> y;
    v1.UstawKart(x, y);
    v1.Show(true);
    Wektor v2;
    std::cin >> x >> y;
    v2.UstawKart(x, y);
    v2.Show(true);
    v1 = v1 * v2;
    v1.Show(true);
}