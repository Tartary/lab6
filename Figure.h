#pragma once

public ref class Figure {
protected:
    int x, y;
    System::Drawing::Color color;
    bool visible;

public:
    ref class BorderException : public System::Exception {
    public:
        BorderException() : System::Exception("Form's border broken by someone figure") {}
    };

    Figure(int _x, int _y, System::Drawing::Color _c)
        : x(_x), y(_y), color(_c), visible(false) {
    }

    virtual void Draw(System::Drawing::Graphics^ g) {}

    virtual void SetVisible(bool v) {
        visible = v;
    }

    bool IsVisible() {
        return visible;
    }

    void Replace(int nx, int ny) {
        SetVisible(false);
        x = nx;
        y = ny;
        SetVisible(true);
    }
    int GetX() { return x; }
    int GetY() { return y; }
    System::Drawing::Color GetColor() { return color; }
};
