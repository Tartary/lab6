#pragma once
#include "Rhomb.h"
#include "Rectangl.h"

public ref class AgrFigure : public Figure {
private:
    Rhomb^ rh;
    Rectangl^ re;

public:
    ref class InscribException : public System::Exception {
    public:
        InscribException() : System::Exception("Rectangle not inscribed in rhomb") {}
    };

    AgrFigure(Rhomb^ _rh, Rectangl^ _re)
        : Figure(_rh->GetX(), _rh->GetY(), _rh->GetColor()),
        rh(_rh), re(_re)
    {
        if (_rh->GetR()!=0.75*_re->GetA()||(_rh->GetX()!=_re->GetX())||(_rh->GetY()!=_re->GetY())) {
            throw gcnew InscribException();
        }
    }

    virtual void Draw(System::Drawing::Graphics^ g) override {
        rh->Draw(g);
        re->Draw(g);
    }

    void Replace(int nx, int ny) {
        rh->Replace(nx, ny);
        re->Replace(nx, ny);
    }
};
