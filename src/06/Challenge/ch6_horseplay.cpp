// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>


bool invalid_move(int x_pos, int y_pos) {
    return x_pos < 0 || x_pos > 7 || y_pos < 0 || y_pos > 7;
}
// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;

    int delim_pos = knight.find(",");
    if(delim_pos != 1 || knight.length() != 3) {
        return moves;
    }
    int x = std::stoi(knight.substr(0,1));
    int y = std::stoi(knight.substr(2,1));
    if (invalid_move(x,y)){
        return moves;
    }

    int x_mods[8] = {-2,-2,-1,1,2,2,1,-1};
    int y_mods[8] = {-1,1,2,2,1,-1,-2,-2};
    for (int i = 0; i < 8; ++i) {
        int x_pos = x + x_mods[i];
        int y_pos = y + y_mods[i];
        if (!invalid_move(x_pos,y_pos)){
            moves.push_back(std::to_string(x_pos)+","+std::to_string(y_pos));
        }
    }

    return moves;
}



// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}