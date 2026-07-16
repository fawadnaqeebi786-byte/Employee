#include <iostream>
#include <vector>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char currentPlayer = 'X';

void showBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if(j < 2) cout << "|";
        }
        cout << endl;
        if(i < 2) cout << "---+---+---\n";
    }
    cout << endl;
}

bool isWin() {
    // Rows & Columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool isDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] >= '1' && board[i][j] <= '9')
                return false;
    return true;
}

void makeMove() {
    int choice;
    while(true) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> choice;
        
        if(choice < 1 || choice > 9) {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        
        if(board[row][col] >= '1' && board[row][col] <= '9') {
            board[row][col] = currentPlayer;
            break;
        } else {
            cout << "Position already taken! Try again.\n";
        }
    }
}

int main() {
    cout << "=== TIC TAC TOE GAME ===\n";
    cout << "Player X vs Player O\n";
    
    while(true) {
        showBoard();
        makeMove();
        
        if(isWin()) {
            showBoard();
            cout << "🎉 Player " << currentPlayer << " WINS! 🎉\n";
            break;
        }
        
        if(isDraw()) {
            showBoard();
            cout << "🤝 Game Draw!\n";
            break;
        }
        
        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    cout << "Thanks for playing!\n";
    return 0;
}