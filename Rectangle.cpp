#include "Rectangle.h"
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>


Rectangle::Rectangle(int x, int y, int r, int c) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->c = c;
}

void Rectangle::read_inFile(string fileName, int& n, int& m, vector<Rectangle>& rectangles) {
    ifstream inFile(fileName);

    if (inFile.is_open()) {
        bool firstLine = true;
        string line;

        while (getline(inFile, line)) {
            istringstream iss(line);
            vector<string> parts((istream_iterator<string>(iss)), istream_iterator<string>());

            if (firstLine) {
                n = stoi(parts[1]);
                m = stoi(parts[2]);
                firstLine = false;
            } else if (parts[0] == "A") {
                int x = stoi(parts[1]);
                int y = stoi(parts[2]);
                int r = stoi(parts[3]);
                int c = stoi(parts[4]);

                rectangles.push_back(Rectangle(x, y, r, c));
            }
        }

        inFile.close();
    }
}

void Rectangle::write_outFile(string fileName, vector<Rectangle> rectangles) {
    ofstream outFile(fileName);

    if (outFile.is_open()) {
        for (Rectangle rectangle : rectangles) {
            outFile << "A " << rectangle.get_x() << " " << rectangle.get_y() << " "  << rectangle.get_r() << " "  << rectangle.get_c() << endl;
        }
    }

    outFile.close();
}

void Rectangle::filter_rectangles(vector<Rectangle> inRectangles, int n, int m, vector<Rectangle>& outRectangles) {
    for (Rectangle rectangle : inRectangles) {
        if (outRectangles.empty() || valid_rectangle(rectangle, n, m, outRectangles)) {
            outRectangles.push_back(rectangle);
        }
    }
}

bool Rectangle::valid_rectangle(Rectangle rectangle, int n, int m, vector<Rectangle> rectangles) {
    int x_begin = rectangle.get_x();
    int x_end = x_begin + rectangle.get_c() - 1;
    int y_begin = rectangle.get_y();
    int y_end = y_begin + rectangle.get_r() - 1;

    int n_valid = 0;

    for (Rectangle other_rectangle : rectangles) {
        int x_begin_other = other_rectangle.get_x();
        int x_end_other = x_begin_other + other_rectangle.get_c() - 1;
        int y_begin_other = other_rectangle.get_y();
        int y_end_other = y_begin_other + other_rectangle.get_r() - 1;

        bool inside_board = (x_end <= m && y_end <= n);
        bool inside_other = (x_begin >= x_begin_other && x_end <= x_end_other && y_begin >= y_begin_other && y_end <= y_end_other);
        bool right_or_below_other = (x_begin > x_end_other || y_begin > y_end_other);
        bool left_or_above_other = (x_end < x_begin_other || y_end < y_begin_other);

        if (inside_board && (inside_other || right_or_below_other || left_or_above_other)) {
            n_valid++;
        }
    }

    return (n_valid == rectangles.size());
}

int Rectangle::get_x() {
    return x;
}

int Rectangle::get_y() {
    return y;
}

int Rectangle::get_r() {
    return r;
}

int Rectangle::get_c() {
    return c;
}