#ifndef PC3_B_RECTANGLE_H
#define PC3_B_RECTANGLE_H

#include <iostream>
#include <vector>

using namespace std;

class Rectangle {
private:
    int x;
    int y;
    int r;
    int c;

public:
    Rectangle(int x, int y, int r, int c);

    static void read_inFile(string fileName, int& n, int& m, vector<Rectangle>& rectangles);

    static void write_outFile(string fileName, vector<Rectangle> rectangles);

    static void filter_rectangles(vector<Rectangle> inRectangles, int n, int m, vector<Rectangle>& outRectangles);

    static bool valid_rectangle(Rectangle rectangle, int n, int m, vector<Rectangle> rectangles);

    int get_x();
    int get_y();
    int get_r();
    int get_c();


};


#endif //PC3_B_RECTANGLE_H
