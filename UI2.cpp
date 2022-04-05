#include "TXLib.h"


struct Data
    {
    int Reset;
    int Set;
    int Quit;
    int Quit1;
    };

struct Button
    {
    int x, y;
    int width, height;
    char name[10];

    void Draw_Button ();

    };

struct RS
    {
    int x, y;

    void Draw_lineRS  (Data current);
    void Draw_lineQQ1 (Data current);
    void Draw_trigger();
    void Draw_line_response (Data current);


    };

void Acting();
int ButtonCheckClick (int x, int y, int mouse_x, int mouse_y);
void Title_name      (int x, int y, int size, int high, COLORREF color_title, char name[]);
void CheckButton (Button buttonSet0, Button buttonSet1, Button buttonReset0, Button buttonReset1, Button buttonClear, Button buttonStart, Data* current);
//void  Draw_lineRS  (Data current, int x, int y);
//void Draw_trigger (int x, int y);
//void Draw_lineQQ1 (Data current, int x, int y);
//void Draw_line_response (Data current, int x, int y);
//void Draw_Button ();
//void Update(Data current);

int main()
    {
    txCreateWindow (800, 900);
    Acting();

    return 0;
    }

void Acting()
    {
    Data current = {0, 0, 0, 0};

    Button buttonSet0 = {40, 105, 30, 40, "1"};
    Button buttonSet1 = {40, 155, 30, 40, "0"};

    Button buttonReset0 = {40, 350, 30, 40, "1"};
    Button buttonReset1 = {40, 400, 30, 40, "0"};

    Button buttonStart = {170, 500, 100, 50, "Start"};
    Button buttonClear = {370, 500, 100, 50, "Clear"};


    Button result = {};
    RS trigger = {150, 150};

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        trigger.Draw_lineRS  (current);
        trigger.Draw_trigger ();
        trigger.Draw_lineQQ1 (current);
        trigger.Draw_line_response (current);
        buttonSet0.Draw_Button();
        buttonSet1.Draw_Button();
        buttonReset0.Draw_Button();
        buttonReset1.Draw_Button();
        buttonStart.Draw_Button();
        buttonClear.Draw_Button();
        CheckButton (buttonSet0, buttonSet1, buttonReset0, buttonReset1, buttonClear, buttonStart, &current);
        txSleep(10);
        }



    }



void RS::Draw_lineRS  (Data current)
    {
    if (current.Reset == 0)
        {
        txSetColor (TX_CYAN, 3);
        txLine (x, y, x + 130, y);
        }
    else
        {
        txSetColor (TX_GREEN, 3);
        txLine (x, y, x + 130, y);
        }
    if (current.Set == 0)
        {
        txSetColor (TX_CYAN, 3);
        txLine (x, y + 240, x + 130, y + 240);
        }
    else
        {
        txSetColor (TX_GREEN, 3);
        txLine (x, y + 240, x + 130, y + 240);
        }
    }

void RS::Draw_trigger ()
    {
    txSetColor (RGB(0, 0, 255), 3);
    txSetFillColor(TX_GREY);
    txRectangle (x + 130, y - 40, x + 210, y + 70);
    Title_name  (x + 135, y - 35, 20, 15, RGB(0, 0, 255), "1");
    txRectangle (x + 130, y + 170, x + 210, y + 280);
    Title_name  (x + 135, y + 175, 20, 15, RGB(0, 0, 255), "1");
    txSetColor (TX_BLUE, 3);
    txCircle (x + 213, y + 20, 6);
    txCircle (x + 213, y + 220, 6);
    Title_name (x + 10, y - 25, 20, 15, RGB(100, 255, 20), "S");
    Title_name (x + 10, y + 215, 20, 15, RGB(100, 255, 20), "R");

    Title_name (x + 410,       y, 20, 15, RGB(255, 255, 20), "not Q");
    Title_name (x + 410, y + 200, 20, 15, RGB(255, 255, 20), "Q");

//    txSetColor (TX_BLUE, 3);
//    txCircle(x + 380, y +  20, 20);
//    txCircle(x + 380, y + 220, 20);


//    txSetColor(TX_BLUE, 3);
//    txSetFillColor(TX_GREY);
//    txRectangle(170, 500, 270, 550);
//    Title_name(187,515,20,15, RGB(0, 0, 255), "start" );
//
//
//    txSetColor(TX_BLUE, 3);
//    txSetFillColor(TX_GREY);
//    txRectangle(370, 500, 470, 550);
//    Title_name(387,515,20,15, RGB(0, 0, 255), "clear" );

    }


void RS::Draw_lineQQ1 (Data current)
    {
    if (current.Quit == 0)
        {
        txSetColor (TX_CYAN, 3);
        txLine (x + 220, y + 20, x + 360, y + 20);
        txSetColor (TX_BLUE, 3);
        txSetFillColor (TX_GREY);
        txCircle(x + 380, y + 220, 20);
        }
    else
        {
        txSetColor (TX_GREEN, 3);
        txLine (x + 220, y + 20, x + 360, y + 20);
        txSetColor (TX_RED, 3);
        txSetFillColor (TX_YELLOW);
        txCircle(x + 380, y + 220, 20);
        }
    if (current.Quit1 == 0)
        {
        txSetColor (TX_CYAN, 3);
        txLine (x + 220, y + 220, x + 360, y + 220);
        txSetColor (TX_BLUE, 3);
        txSetFillColor (TX_GREY);
        txCircle(x + 380, y +  20, 20);
        }
    else
        {
        txSetColor (TX_GREEN, 3);
        txLine (x + 220, y + 220, x + 360, y + 220);
        txSetColor (TX_RED, 3);
        txSetFillColor (TX_YELLOW);
        txCircle(x + 380, y +  20, 20);
        }
    }

void RS:: Draw_line_response (Data current)
    {
    if (current.Quit == 0)
        {
        txSetColor (TX_CYAN, 3);
        txLine (x + 280, y + 20,x + 280, y + 100);
        txLine (x + 280, y + 100, x + 90, y + 140);
        txLine (x + 90, y + 140, x + 90, y + 210);
        txLine (x + 90, y + 210, x + 130, y + 210);
        }
    else
        {
        txSetColor (TX_GREEN, 3);
        txLine (x + 280, y + 20,x + 280, y + 100);
        txLine (x + 280, y + 100, x + 90, y + 140);
        txLine (x + 90, y + 140, x + 90, y + 210);
        txLine (x + 90, y + 210, x + 130, y + 210);
        }

    if (current.Quit1 == 0)
        {
        txSetColor (TX_CYAN, 3);
        txLine (x + 130, y + 40, x + 90, y + 40);
        txLine (x + 90, y + 40, x + 90, y + 100);
        txLine (x + 90, y + 100, x + 280, y + 140);
        txLine (x + 280, y + 140, x + 280, y + 220);
        }
    else
        {
        txSetColor (TX_GREEN, 3);
        txLine (x + 130, y + 40, x + 90, y + 40);
        txLine (x + 90, y + 40, x + 90, y + 100);
        txLine (x + 90, y + 100, x + 280, y + 140);
        txLine (x + 280, y + 140, x + 280, y + 220);
        }
    }


int ButtonCheckClick ( int x, int y, int width, int height, int mouse_x, int mouse_y)
    {
    if (fabs (x - mouse_x) <= width)
        if (fabs (y - mouse_y) <= height)
            if (GetAsyncKeyState (VK_LBUTTON))
                {
                return 1;
                };
    return 0;
    };

void Button::Draw_Button ()
    {
    txSetColor (TX_PINK);
    txRectangle (x, y, x + width, y + height);
    Title_name  (x + 5, y + 5, 20, 10, RGB(0, 100, 200), name);

    }

void Title_name (int x, int y, int size, int high, COLORREF color_title, char name[])
    {
    txSetColor    (color_title);
    txSelectFont  ("Arial", size, high);
    char str [20] = "";
    sprintf (str, "%s", name);
    txTextOut (x, y, str);
    }


void CheckButton (Button buttonSet0, Button buttonSet1, Button buttonReset0, Button buttonReset1, Button buttonClear, Button buttonStart, Data* current)
    {

    if (ButtonCheckClick (buttonSet0.x, buttonSet0.y, buttonSet0.width, buttonSet0.height, txMouseX(), txMouseY()) == true)
        {
        Title_name (buttonSet0.x + 180, buttonSet0.y + 15, 20, 15, RGB(255, 25, 20), "1");
        (*current).Set = 1;
        //printf("%d\n",(*current).Set);
        }
    else if (ButtonCheckClick (buttonSet1.x, buttonSet1.y, buttonSet1.width, buttonSet1.height, txMouseX(), txMouseY()) == true)
        {
        Title_name (buttonSet0.x + 180, buttonSet0.y + 15, 20, 15, RGB(0, 200, 200), "0");
        (*current).Set = 0;
        }
    if (ButtonCheckClick (buttonReset0.x, buttonReset0.y, buttonReset0.width, buttonReset0.height, txMouseX(), txMouseY()) == true)
        {
         Title_name (buttonReset0.x + 180, buttonReset0.y + 15, 20, 15, RGB(100, 255, 20), "1");
        (*current).Reset = 1;
        }
    else if (ButtonCheckClick (buttonReset1.x, buttonReset1.y, buttonReset1.width, buttonReset1.height, txMouseX(), txMouseY()) == true)
        {
        Title_name (buttonReset0.x + 180, buttonReset0.y + 15, 20, 15, RGB(0, 200, 200), "0");
        (*current).Reset = 0;
        }
    if (ButtonCheckClick (buttonStart.x, buttonStart.y, buttonStart.width, buttonStart.height, txMouseX(), txMouseY()) == true)
        {
        //printf("%d\n",(*current).Quit1);
        if ((*current).Set == 0 && (*current).Reset ==1)
            {
            (*current).Quit = 0;
            (*current).Quit1 = 1;
            //printf("%d\n",(*current).Quit1);

            }
        if ((*current).Set == 1 && (*current).Reset ==0)
            {
            (*current).Quit = 1;
            (*current).Quit1 = 0;
            //printf("%d\n",(*current).Quit1);

            }

        }
    if (ButtonCheckClick (buttonClear.x, buttonClear.y, buttonClear.width, buttonClear.height, txMouseX(), txMouseY()) == true)
        {

        (*current).Reset = 0;
        (*current).Set = 0;
        (*current).Quit = 0;
        (*current).Quit1 = 0;
        printf("%d\n",(*current).Set);

        }
    }



void Draw_Start()
{
txSetColor(TX_BLUE, 3);
txSetFillColor(TX_GREY);
txRectangle(170, 500, 270, 550);
Title_name(187,515,20,15, RGB(0, 0, 255), "start" );
}
