#pragma once
#include "Figure.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class Set {
private:
    List<Figure^>^ items;

public:
    Set() {
        items = gcnew List<Figure^>();
    }

    void Add(Figure^ f) {
        if (f != nullptr) {
            items->Add(f);
        }
    }

    void ShowAll() {
        for each (Figure ^ f in items) {
            if (f != nullptr) f->SetVisible(true);
        }
    }

    void HideAll() {
        for each (Figure ^ f in items) {
            if (f != nullptr) f->SetVisible(false);
        }
    }

    void Replace(int nx, int ny) {
        for each (Figure ^ f in items) {
            if (f != nullptr) {
                f->Replace(nx, ny);
            }
        }
    }

    void Clear() {
        items->Clear();
    }

    int Count() {
        return items->Count;
    }
};
