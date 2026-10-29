#pragma once
#include "Figure.h"
#include<cmath>

public ref class Rectangl : public Figure {
private:
    int a;

public:
    Rectangl(int _x, int _y, int _a, System::Drawing::Color c)
        : Figure(_x, _y, c), a(_a) {
    }

    int GetA() { return a; }

    virtual void Draw(System::Drawing::Graphics^ g) override {
        int dx = a / 2;
        int x3 = x - dx, x4 = x + dx;
        int dy = tan(3.14 / 4) * (a / 4);
        int y3 = y - dy, y4 = y + dy;
        if ((x3 < 1) || (y3 < 1) || (x4 > 799) || (y4 > 649)) {
            throw gcnew BorderException();
        }
        System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(color, 2);
        array<System::Drawing::Point>^ points = gcnew array<System::Drawing::Point>(4) {
            System::Drawing::Point(x3, y3),
            System::Drawing::Point(x4, y3),
            System::Drawing::Point(x4, y4),
            System::Drawing::Point(x3, y4)
        };
        g->DrawPolygon(pen, points);
    }
    virtual void SetVisible(bool v) override {
        if (((x - a / 2) < 1) || ((y - tan(3.14 / 4) * (a / 4)) < 1) || ((x + a / 2) > 799) || ((y + tan(3.14 / 4) * (a / 4)) > 649)) {
            throw gcnew BorderException();
            return;
        }
        visible = v;
    }
};
