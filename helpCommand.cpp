#include <iostream>
#include <conio.h>
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

int main()
{
    helpCommand();
    cout << "Press any key to continue...\n";
    getch();

    return 0;
}