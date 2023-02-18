// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T11L
// Names: ISAIAH WONG TERJIE | JAVIER AUSTIN ANAK JAWA
// IDs: 1211101376 | 1211100857
// Emails: 1211101376@student.mmu.edu.my | 1211100857@student.mmu.edu.my
// Phones: 011-2327-1713 | 019-3669511
// *********************************************************

// TODO: Fill in the missing information above and delete this line.

#include "pf/helper.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

void helpCommand()
{
    cout << "Commands" << endl;
    cout << "1. up    - Move up." << endl;
    cout << "2. down  - Move down." << endl;
    cout << "3. left  - Move left." << endl;
    cout << "4. right - Move right." << endl;
    cout << "5. arrow - Change the direction of an arrow." << endl;
    cout << "6. help  - Display these user commands." << endl;
    cout << "7. save  - Save the game." << endl;
    cout << "8. load  - Load a game." << endl;
    cout << "9. quit  - Quit the game." << endl;
}

class Board
{
private:
    vector<vector<char>> map_;
    int Row_, Col_;
    int alienRow, alienCol;


public:
    Board();
    void init(int Row, int Col);
    void display() const;
};

Board::Board()
{
    Row_ = 15;
    Col_ = 5;
    init (Row_,Col_);
    alienRow = Col_ / 2;
    alienCol = Row_ / 2;
}

void Board::init(int Row, int Col)
{
    Row_ = Row;
    Col_ = Col;
    char objects[] = {' ', ' ', '^', 'v', '<', '>', 'h', 'p', 'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char zombie[] = {'Z'};
    int noOfObjects = 20; // number of objects in the objects array
    int noOfZombie = 20;
    // create dynamic 2D array using vector
    map_.resize(Col_); // create empty rows
    for (int i = 0; i < Col_; ++i)

    {
        map_[i].resize(Row_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < Col_; ++i)
    {
        for (int j = 0; j < Row_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
            int zomNo = rand() % noOfZombie;
            map_[i][j] = zombie[zomNo];
        }
    }
    map_[Col_/2][Row_/2] = 'A';
}


void Board::display() const
{
    cout << " --__--__--__--__--__--__--__--_--__--__--__--__--__--__--_ " << endl;
    cout << " = Hello Adventurer are you ready to kill some ZOMBIESS!!! =" << endl;
    cout << " __--__--__--__--__--__--__--__--__--__--__--__--__--__--__ " << endl;

    // for each row
    for (int i = 0; i < Col_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < Row_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (Col_ - i);
        // display cell content and border of each column
        for (int j = 0; j < Row_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << " ";
    for (int j = 0; j < Row_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << " ";
    for (int j = 0; j < Row_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < Row_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;

}
int main()
{
    int Row,Col;
    cout << "Assignment (Part 2)" << endl;
    cout << "Let's Get Started!" << endl;
    srand(time(NULL));
    cout << "Please Enter Your Desired Dimensions Of The Board"<<endl;
    cout << "Number of Rows: ";
    cin >> Row;
    cout << "Number of Columns: ";
    cin >> Col;
    
    Board board;
    board.init(Row,Col);
    board.display();

    string input;
    cout << "Enter a command: "; 
    cin >> input;

    if(input == "help")
    {
        helpCommand();
    }
    else
    {
        cout << "Invalid command. Type 'help' for available commands.\n";

    }

    pf::Pause();
}
