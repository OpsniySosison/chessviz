#include "lib/chessviz.h"

int main()
{
    char arena[ARENA_SIZE][ARENA_SIZE] // game arena
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    ifstream data("./inputdata");
    string line;
    turn turn;
    int num__line = 1;

    print_arena(arena);
    if (data.is_open()) {
        while (getline(data, line)) {
            if (parser(line, turn) != 0) {
                cout << "input data error in " << num__line << " line" << endl;
                return 1;
            }
            if (make_a_turn(turn, &arena[0], num__line) != 0) {
                return 1;
            }
            num__line++;
        }
    } else {
        cout << "error, file is not open" << endl;
        return 3;
    }

    data.close();

    return 0;
}
