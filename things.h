#ifndef THINGS_H
#define THINGS_H

#include"raylib.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int thickness;
    Color color;
}Pen;

typedef struct {
    Color color;
} pixel;

typedef struct
{
    Vector2 top_left;
    Vector2 bottom_right;
    void (*func)(void* a,void*b,void* c,void* d);
    char* texture_path;
    Texture2D texture;
}button;

typedef struct{
    int screenwidth;
    int screenheight;

    Vector2 CanvasTopLeft;
    Vector2 CanvasBottomRight;
    int CanvasBorderThickness;

    button* buttons;
    int num_buttons;
}Gui;

typedef struct{
    Vector2* arr;
    int len;
    int cap;
}vector;
// pixel.c
void MyDrawRectangle(pixel* screen,Vector2 top_left,Vector2 bottom_right,Color color);
void MyDrawPixelCanvas(pixel* screen,Vector2 pos,Color color);
void ClearScreen(pixel* screen,vector* qsplines,vector* lines,vector* points);
void DrawScreen(pixel* screen);
void AddGuiBase(pixel* screen);
void DrawQSplines(vector* qsplines);
void DrawLines(vector* lines);
void ClearCanvas(pixel* screen,vector* qsplines,vector* lines,vector* points);
void AddQSplines(pixel* screen,vector* qsplines);
void AddLines(pixel* screen,vector* lines);
void MyDrawCircle(pixel* screen,Vector2 center,int radius,Color color);

//vector.c

vector GiveVector();
void Vector_Grow50(vector* vec,int index);
void Vector_Add50(vector* vec,Vector2 point,int index);
void Vector_Add50e(vector* vec,Vector2 point);
void Vector_Grow(vector* vec,int index);
void Vector_Add(vector* vec,Vector2 point,int index);
Vector2 Vector_pop(vector* vec);
void Vector_Empty(vector* vec);

//buttons.c
Vector2 Vector2Sum(Vector2 a,Vector2 b);
void Button_LoadTextures();
void Button_Ifpressed(button but,Vector2 cur_pos,void* a,void* b,void* c,void* d);
void ScreenClearButton(void* a,void* b,void* c,void* d);

#endif