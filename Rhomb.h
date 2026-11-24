#pragma once
#include "Figure.h"

public ref class Rhomb : public Figure {
private:
    int R;

public:
    Rhomb(int _x, int _y, int _R, System::Drawing::Color c)
        : Figure(_x, _y, c), R(_R) {
    }

    int GetR() { return R; }

    virtual void Draw(System::Drawing::Graphics^ g) override {
        int x1 = x - R, x2 = x + R;
        int y1 = y - R, y2 = y + R;
        
        System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(color, 2);
        array<System::Drawing::Point>^ points = gcnew array<System::Drawing::Point>(4) {
            System::Drawing::Point(x1, y),
            System::Drawing::Point(x, y1),
            System::Drawing::Point(x2, y),
            System::Drawing::Point(x, y2)
        };
        g->DrawPolygon(pen, points);
    }
    virtual void SetVisible(bool v) override {
        if (((x - R) < 1) || ((y - R) < 1) || ((x + R) > 799) || ((y + R) > 649)) {
            throw gcnew BorderException();
            return;
        }
        visible = v;
    }
};
