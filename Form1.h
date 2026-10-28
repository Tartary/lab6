#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

#include "Rhomb.h"
#include "Rectangl.h"
#include "AgrFigure.h"
#include"Set.h"

public ref class Form1 : public Form {
private:
    Panel^ drawingPanel;
    Button^ btnShowAll;
    Button^ btnHideAll;
    Button^ btnMoveAll;

    Label^ lblX;
    Label^ lblY;
    TextBox^ txtX;
    TextBox^ txtY;

    Rhomb^ rhomb1;
    Rectangl^ rect1;
    AgrFigure^ agrFigure1;
    Set^ figures;

    void drawingPanel_Paint(Object^ sender, PaintEventArgs^ e);
    void InitializeFigures();

private:
    void OnBtnShowAllClick(Object^ sender, EventArgs^ e);
    void OnBtnHideAllClick(Object^ sender, EventArgs^ e);
    void OnBtnMoveAllClick(Object^ sender, EventArgs^ e);

public:
    Form1(void);

private:
    void InitializeComponent(void);
};
