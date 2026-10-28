#include "pch.h"
#include "Form1.h"

Form1::Form1(void) {
    InitializeComponent();
    InitializeFigures();

    if (drawingPanel != nullptr) {
        drawingPanel->Paint += gcnew PaintEventHandler(this, &Form1::drawingPanel_Paint);
    }

    figures = gcnew Set();
    figures->Add(rhomb1);
    figures->Add(rect1);
    if (agrFigure1 != nullptr) {
        figures->Add(agrFigure1);
    }
}

void Form1::InitializeComponent(void) {
    this->SuspendLayout();

    this->ClientSize = System::Drawing::Size(800, 650);
    this->Text = L"25VP1_21";
    this->StartPosition = FormStartPosition::CenterScreen;

    drawingPanel = gcnew Panel();
    drawingPanel->Dock = DockStyle::Fill;
    drawingPanel->BackColor = Color::White;

    int btnHeight = 40;
    int gap = 15;
    int startY = this->ClientSize.Height - btnHeight - 10;

    btnShowAll = gcnew Button();
    btnShowAll->Text = L"Show All";
    btnShowAll->Location = Point(20, startY);
    btnShowAll->Size = System::Drawing::Size(100, btnHeight);
    btnShowAll->BackColor = Color::LightGreen;

    btnHideAll = gcnew Button();
    btnHideAll->Text = L"Hide All";
    btnHideAll->Location = Point(btnShowAll->Right + gap, startY);
    btnHideAll->Size = System::Drawing::Size(100, btnHeight);
    btnHideAll->BackColor = Color::Salmon;

    btnMoveAll = gcnew Button();
    btnMoveAll->Text = L"Move All";
    btnMoveAll->Location = Point(btnHideAll->Right + gap, startY);
    btnMoveAll->Size = System::Drawing::Size(100, btnHeight);
    btnMoveAll->BackColor = Color::LightBlue;

    lblX = gcnew Label();
    lblX->Text = L"newX:";
    lblX->Location = Point(btnHideAll->Right + gap, startY - 60);
    lblX->AutoSize = true;

    txtX = gcnew TextBox();
    txtX->Text = L"444";
    txtX->Location = Point(lblX->Right, startY - 60);
    txtX->Size = System::Drawing::Size(60, 24);

    lblY = gcnew Label();
    lblY->Text = L"newY:";
    lblY->Location = Point(btnHideAll->Right + gap, startY - 35);
    lblY->AutoSize = true;

    txtY = gcnew TextBox();
    txtY->Text = L"444";
    txtY->Location = Point(lblY->Right, startY - 35);
    txtY->Size = System::Drawing::Size(60, 24);

    btnShowAll->Click += gcnew EventHandler(this, &Form1::OnBtnShowAllClick);
    btnHideAll->Click += gcnew EventHandler(this, &Form1::OnBtnHideAllClick);
    btnMoveAll->Click += gcnew EventHandler(this, &Form1::OnBtnMoveAllClick);

    this->Controls->Add(drawingPanel);
    this->Controls->Add(lblX);
    this->Controls->Add(txtX);
    this->Controls->Add(lblY);
    this->Controls->Add(txtY);
    this->Controls->Add(btnShowAll);
    this->Controls->Add(btnHideAll);
    this->Controls->Add(btnMoveAll);

    btnShowAll->BringToFront();
    btnHideAll->BringToFront();
    btnMoveAll->BringToFront();
    lblX->BringToFront();
    txtX->BringToFront();
    lblY->BringToFront();
    txtY->BringToFront();

    this->ResumeLayout(false);
}

void Form1::InitializeFigures() {
    try {
        rhomb1 = gcnew Rhomb(200, 200, 75, Color::Red);
        rect1 = gcnew Rectangl(200, 200, 100, Color::Blue);
        agrFigure1 = gcnew AgrFigure(rhomb1, rect1);
    }
    catch (AgrFigure::InscribException^ ex) {
        MessageBox::Show(ex->Message, L"Ошибка создания сложной фигуры",
            MessageBoxButtons::OK, MessageBoxIcon::Error);
        agrFigure1 = nullptr;
    }
}

void Form1::drawingPanel_Paint(Object^ sender, PaintEventArgs^ e) {
    Graphics^ g = e->Graphics;
    if (rhomb1 && rhomb1->IsVisible()) rhomb1->Draw(g);
    if (rect1 && rect1->IsVisible()) rect1->Draw(g);
    if (agrFigure1 && agrFigure1->IsVisible()) agrFigure1->Draw(g);
}

void Form1::OnBtnShowAllClick(Object^ sender, EventArgs^ e) {
    try {
        if (rhomb1) rhomb1->SetVisible(true);
        if (rect1) rect1->SetVisible(true);
        if (agrFigure1) agrFigure1->SetVisible(true);
        figures->ShowAll();
    }
    catch (Figure::BorderException^ ex) {
        MessageBox::Show(ex->Message, L"Ошибка рисовки фигуры",
            MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    drawingPanel->Invalidate();
}

void Form1::OnBtnHideAllClick(Object^ sender, EventArgs^ e) {
    if (rhomb1) rhomb1->SetVisible(false);
    if (rect1) rect1->SetVisible(false);
    if (agrFigure1) agrFigure1->SetVisible(false);
    figures->HideAll();
    drawingPanel->Invalidate();
}

void Form1::OnBtnMoveAllClick(Object^ sender, EventArgs^ e) {
    int newX, newY;

    if (!Int32::TryParse(txtX->Text, newX)) {
        MessageBox::Show(L"В поле X нужно ввести целое число", L"Ошибка ввода",
            MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    if (!Int32::TryParse(txtY->Text, newY)) {
        MessageBox::Show(L"В поле Y нужно ввести целое число", L"Ошибка ввода",
            MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    try {
        if (rhomb1) rhomb1->Replace(newX, newY);
        if (rect1) rect1->Replace(newX, newY);
        if (agrFigure1) agrFigure1->Replace(newX, newY);
        figures->Replace(newX, newY);
    }
    catch (Figure::BorderException^ ex) {
        MessageBox::Show(ex->Message, L"Ошибка рисовки фигуры",
            MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    drawingPanel->Invalidate();
}