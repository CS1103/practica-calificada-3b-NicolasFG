#include <iostream>
#include <vector>
#include "Rectangle.cpp"


using namespace std;

int main() {
    int n, m;
    vector<Rectangle> inRectangles;
    vector<Rectangle> outRectangles;

    Rectangle::read_inFile("rectangulos.in", n, m, inRectangles);
    Rectangle::filter_rectangles(inRectangles, n, m, outRectangles);
    Rectangle::write_outFile("rectangulos.out", outRectangles);

    return 0;
}