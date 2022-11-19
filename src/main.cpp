#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct vec2{
    int x;
    int y;
    vec2(){
        // Error Handling
    }
    vec2(int _x, int _y):x(_x), y(_y) {};
} typedef vec2;

enum PieceType{
    Pawn,
    Rook,
    Bishop,
    Knight,
    King,
    Queen
};

enum PieceColor{
    White,
    Black
};

struct Move{
    int srow;
    int scol;
    int nrow;
    int ncol;
};

class Piece{
    public:
        PieceType type;
        PieceColor color;
        Piece(){
            // Error Handling
        }
        Piece(PieceType _t, PieceColor _c):type(_t), color(_c) {};
        Piece(Piece* p):type(p->type), color(p->color) {};
};

// Returns Piece based on a given char
Piece cTP(char c){
    Piece result;
    if(65 <= (int)c && (int)c <= 90){
        result.color = White;
    }
    else if(97 <= (int)c && 122 >= (int)c){
        result.color = Black;
    }

    if(c == 'P' || c == 'p'){
        result.type = Pawn;
    }
    else if(c == 'R' || c == 'r'){
        result.type = Rook;
    }
    else if(c == 'B' || c == 'b'){
        result.type = Bishop;
    }
    else if(c == 'N' || c == 'n'){
        result.type = Knight;
    }
    else if(c == 'K' || c == 'k'){
        result.type = King;
    }
    else if(c == 'Q' || c == 'q'){
        result.type = Queen;
    }
    return result;
}

// returns true if given value between left and right bounds
bool between(int a, int lb, int rb, bool inclusive = true){
    if(!inclusive){
        return a > lb && a < rb;
    }
    else{
        return a >= lb && a <= rb;
    }
}

// Returns true if given piece is black
bool isBlack(int p){
    return between(p, 97, 122, true);
}

// Returns Given Position to Edge
vec2 pTE(int pos){
    vec2 result;
    result.x = std::abs(0 - pos);
    result.y = 7 - pos;
    return result;
}

std::vector<Move> getPossibleMoves(char board[8][8]){
    // 65 to 90 = white
    // 97 to 122 = black
    std::vector<Move> result;
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            Piece piece = cTP(board[r][c]);
            Move move;
            move.srow = r;
            move.scol = c;
            switch(piece.type){
                case Pawn:
                    // if(piece.color == White){
                    //     if(r != 7 && (board[r+1][c] == '-' || between((int)board[r+1][c], 97, 122, true))){
                    //         move.nrow = r+1;
                    //         move.ncol = c;
                    //         result.push_back(move);
                    //     }
                    // }
                    if(piece.color == Black){
                        if(r != 0 && (board[r-1][c] == '-' || between((int)board[r-1][c], 65, 90, true))){
                            move.nrow = r-1;
                            move.ncol = c;
                            result.push_back(move);
                        }
                    }
                    break;
                case Knight:
                    // if(piece.color == White){
                    //     if(r <= 5 && c != 7 && (board[r+2][c+1] == '-' || between((int)board[r+2][c+1], 97, 122, true))){
                    //         move.nrow = r+2;
                    //         move.ncol = c+1;
                    //         result.push_back(move);
                    //     }
                    //     if(r <= 5 && c != 0 && (board[r+2][c-1] == '-' || between((int)board[r+2][c-1], 97, 122, true))){
                    //         move.nrow = r+2;
                    //         move.ncol = c-1;
                    //         result.push_back(move);
                    //     }
                    //     if(r >= 2 && c != 7 && (board[r-2][c+1] == '-' || between((int)board[r-2][c+1], 97, 122, true))){
                    //         move.nrow = r-2;
                    //         move.ncol = c+1;
                    //         result.push_back(move);
                    //     }
                    //     if(r >= 2 && c != 0 && (board[r-2][c-1] == '-' || between((int)board[r-2][c-1], 97, 122, true))){
                    //         move.nrow = r-2;
                    //         move.ncol = c-1;
                    //         result.push_back(move);
                    //     }
                    //     if(r + 1 < 8 && c + 2 < 8 && (board[r+1][c+2] == '-' || between((int)board[r+1][c+2], 97, 122, true))){
                    //        move.nrow = r+1;
                    //        move.ncol = c+2;
                    //        result.push_back(move);
                    //     }
                    //     if(r - 1 > 0 && c + 2 < 8 && (board[r-1][c+2] == '-' || between((int)board[r-1][c+2], 97, 122, true))){
                    //         move.nrow = r-1;
                    //         move.ncol = c+2;
                    //         result.push_back(move);
                    //     }
                    //     if(r + 1 < 8 && c - 2 < 8 && (board[r+1][c-2] == '-' || between((int)board[r+1][c-2], 97, 122, true))){
                    //         move.nrow = r+1;
                    //         move.ncol = c-2;
                    //         result.push_back(move);
                    //     }
                    //     if(r - 1 > 0 && c - 2 < 8 && (board[r-1][c-2] == '-' || between((int)board[r-1][c-2], 97, 122, true))){
                    //         move.nrow = r-1;
                    //         move.ncol = c-2;
                    //     }
                    // }
                    if(piece.color == Black){
                        if(r <= 5 && c != 7 && (board[r+2][c+1] == '-' || between((int)board[r+2][c+1], 65, 90, true))){
                            move.nrow = r+2;
                            move.ncol = c+1;
                            result.push_back(move);
                        }
                        if(r <= 5 && c != 0 && (board[r+2][c-1] == '-' || between((int)board[r+2][c-1], 65, 90, true))){
                            move.nrow = r+2;
                            move.ncol = c-1;
                            result.push_back(move);
                        }
                        if(r >= 2 && c != 7 && (board[r-2][c+1] == '-' || between((int)board[r-2][c+1], 65, 90, true))){
                            move.nrow = r-2;
                            move.ncol = c+1;
                            result.push_back(move);
                        }
                        if(r >= 2 && c != 0 && (board[r-2][c-1] == '-' || between((int)board[r-2][c-1], 65, 90, true))){
                            move.nrow = r-2;
                            move.ncol = c-1;
                            result.push_back(move);
                        }
                        if(r + 1 < 8 && c + 2 < 8 && (board[r+1][c+2] == '-' || between((int)board[r+1][c+2], 65, 90, true))){
                           move.nrow = r+1;
                           move.ncol = c+2;
                           result.push_back(move);
                        }
                        if(r - 1 > 0 && c + 2 < 8 && (board[r-1][c+2] == '-' || between((int)board[r-1][c+2], 65, 90, true))){
                            move.nrow = r-1;
                            move.ncol = c+2;
                            result.push_back(move);
                        }
                        if(r + 1 < 8 && c - 2 < 8 && (board[r+1][c-2] == '-' || between((int)board[r+1][c-2], 65, 90, true))){
                            move.nrow = r+1;
                            move.ncol = c-2;
                            result.push_back(move);
                        }
                        if(r - 1 > 0 && c - 2 < 8 && (board[r-1][c-2] == '-' || between((int)board[r-1][c-2], 65, 90, true))){
                            move.nrow = r-1;
                            move.ncol = c-2;
                        }
                    }
                    break;
                case Rook:
                    // if(piece.color == White){
                    //     if(pTE(r).x != 0){
                    //         for(int i = 1; i <= pTE(r).x; i++){
                    //             if(board[r - i][c] == '-' || between((int)board[r+1][c], 97, 122, true)){
                    //                 move.nrow = r - i;
                    //                 move.ncol = c;
                    //             }
                    //         }
                    //     }
                    //     if(pTE(r).y != 0){
                    //         for(int i = 1; i <= pTE(r).y; i++){
                    //             if(board[r + i][c] == '-' || between((int)board[r+1][c], 97, 122, true)){
                    //                 move.nrow = r + i;
                    //                 move.ncol = c;
                    //             }
                    //         }
                    //     }
                    //     if(pTE(c).x != 0){
                    //         for(int i = 1; i<= pTE(c).x; i++){
                    //             if(board[r][c - i] == '-' || between((int)board[r+1][c], 97, 122, true)){
                    //                 move.nrow = r;
                    //                 move.ncol = c - i;
                    //             }
                    //         }
                    //     }
                    //     if(pTE(c).y != 0){
                    //         for(int i = 1; i <= pTE(c).y; i++){
                    //             if(board[r][c + i] == '-' || between((int)board[r+1][c], 97, 122, true)){
                    //                 move.nrow = r;
                    //                 move.ncol = c + i;
                    //             }
                    //         }
                    //     }
                    // }
                    if(piece.color == Black){
                        if(pTE(r).x != 0){
                            for(int i = 1; i <= pTE(r).x; i++){
                                if(board[r - i][c] == '-' || !isBlack((int)board[r - i][c])){
                                    move.nrow = r - i;
                                    move.ncol = c;
                                }
                            }
                        }
                        if(pTE(r).y != 0){
                            for(int i = 1; i <= pTE(r).y; i++){
                                if(board[r + i][c] == '-' || !isBlack((int)board[r + i][c])){
                                    move.nrow = r + i;
                                    move.ncol = c;
                                }
                            }
                        }
                        if(pTE(c).x != 0){
                            for(int i = 1; i<= pTE(c).x; i++){
                                if(board[r][c - i] == '-' || !isBlack((int)board[r][c - i])){
                                    move.nrow = r;
                                    move.ncol = c - i;
                                }
                            }
                        }
                        if(pTE(c).y != 0){
                            for(int i = 1; i <= pTE(c).y; i++){
                                if(board[r][c + i] == '-' || !isBlack((int)board[r][c + i])){
                                    move.nrow = r;
                                    move.ncol = c + i;
                                }
                            }
                        }
                    }
                    break;
                case King:
                    if(piece.color == Black){
                        if(r > 0 && (board[r-1][c] == '-' || !isBlack((int)board[r-1][c]))){
                            move.nrow = r - 1;
                            move.ncol = c;
                            result.push_back(move);
                        }
                        if(r < 7 && (board[r+1][c] == '-' || !isBlack((int)board[r+1][c]))){
                            move.nrow = r+1;
                            move.ncol = c;
                            result.push_back(move);
                        }
                        if(c > 0 && (board[r][c-1] == '-' || !isBlack((int)board[r][c-1]))){
                            move.nrow = r;
                            move.ncol = c-1;
                            result.push_back(move);
                        }
                        if(c < 7 && (board[r][c+1] == '-' || !isBlack((int)board[r][c+1]))){
                            move.nrow = r;
                            move.ncol = c+1;
                            result.push_back(move);
                        }
                    }
                    break;
                case Bishop:
                    if(piece.color == Black){
                        int fr = r;
                        int fc = c;
                        while(pTE(fr).x != 0 && pTE(fc).y != 0){
                            if(board[fr-1][fc+1] == '-' || !isBlack((int)board[fr-1][fc+1])){
                                move.nrow = fr-1;
                                move.ncol = fc+1;
                                result.push_back(move);
                            }
                            else if(isBlack((int)board[fr-1][fc+1])){
                                break;
                            }
                            fr--;
                            fc++;
                        }
                        fr = r;
                        fc = c;
                        while(pTE(fr).y != 0 && pTE(fc).y != 0){
                            if(board[fr+1][fc+1] == '-' || !isBlack((int)board[fr-1][fc+1])){
                                move.nrow = fr+1;
                                move.ncol = fc+1;
                                result.push_back(move);
                            }
                            else if(isBlack((int)board[fr+1][fc+1])){
                                break;
                            }
                            fr++;
                            fc++;
                        }
                        fr = r;
                        fc = c;
                        while(pTE(fr).x != 0 || pTE(fc).x != 0){
                            if(board[fr-1][fc-1] == '-' || !isBlack((int)board[fr-1][fc-1])){
                                move.nrow = fr-1;
                                move.ncol = fc-1;
                                result.push_back(move);
                            }
                            else if(isBlack((int)board[fr-1][fc-1])){
                                break;
                            }
                            fr--;
                            fc--;
                        }
                        fr = r;
                        fc = c;
                        while(pTE(fr).y != 0 || pTE(fc).x != 0){
                            if(board[fr+1][fc-1] == '-' || !isBlack((int)board[fr+1][fc-1])){
                                move.nrow = fr+1;
                                move.ncol = fc-1;
                                result.push_back(move);
                            }
                            fr++;
                            fc--;
                        }
                    }
                    break;
                case Queen:
                    if(piece.color == Black){
                        if(pTE(r).x != 0){
                            for(int i = 1; i <= pTE(r).x; i++){
                                if(board[r - i][c] == '-' || !isBlack((int)board[r - i][c])){
                                    move.nrow = r - i;
                                    move.ncol = c;
                                }
                            }
                        }
                        if(pTE(r).y != 0){
                            for(int i = 1; i <= pTE(r).y; i++){
                                if(board[r + i][c] == '-' || !isBlack((int)board[r + i][c])){
                                    move.nrow = r + i;
                                    move.ncol = c;
                                }
                            }
                        }
                        if(pTE(c).x != 0){
                            for(int i = 1; i<= pTE(c).x; i++){
                                if(board[r][c - i] == '-' || !isBlack((int)board[r][c - i])){
                                    move.nrow = r;
                                    move.ncol = c - i;
                                }
                            }
                        }
                        if(pTE(c).y != 0){
                            for(int i = 1; i <= pTE(c).y; i++){
                                if(board[r][c + i] == '-' || !isBlack((int)board[r][c + i])){
                                    move.nrow = r;
                                    move.ncol = c + i;
                                }
                            }
                        }
                        int fr = r;
                        int fc = c;
                        while(pTE(fr).x != 0 && pTE(fc).y != 0){
                            if(board[fr-1][fc+1] == '-' || !isBlack((int)board[fr-1][fc+1])){
                                move.nrow = fr-1;
                                move.ncol = fc+1;
                                result.push_back(move);
                            }
                            else if(isBlack((int)board[fr-1][fc+1])){
                                break;
                            }
                            fr--;
                            fc++;
                        }
                        fr = r;
                        fc = c;
                        while(pTE(fr).y != 0 && pTE(fc).y != 0){
                            if(board[fr+1][fc+1] == '-' || !isBlack((int)board[fr-1][fc+1])){
                                move.nrow = fr+1;
                                move.ncol = fc+1;
                                result.push_back(move);
                            }
                            else if(isBlack((int)board[fr+1][fc+1])){
                                break;
                            }
                            fr++;
                            fc++;
                        }
                        fr = r;
                        fc = c;
                        while(pTE(fr).x != 0 || pTE(fc).x != 0){
                            if(board[fr-1][fc-1] == '-' || !isBlack((int)board[fr-1][fc-1])){
                                move.nrow = fr-1;
                                move.ncol = fc-1;
                                result.push_back(move);
                            }
                            else if(isBlack((int)board[fr-1][fc-1])){
                                break;
                            }
                            fr--;
                            fc--;
                        }
                        fr = r;
                        fc = c;
                        while(pTE(fr).y != 0 || pTE(fc).x != 0){
                            if(board[fr+1][fc-1] == '-' || !isBlack((int)board[fr+1][fc-1])){
                                move.nrow = fr+1;
                                move.ncol = fc-1;
                                result.push_back(move);
                            }
                            fr++;
                            fc--;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return result;
}

int main(){
    char board[8][8] = {
        {'R', 'B', 'N', 'K', 'Q', 'N', 'B', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'b', 'n', 'k', 'q', 'n', 'b', 'r'}
    };

    std::vector<Move> moves = getPossibleMoves(board);

    std::string s;
    for(int i = 0; i < 8; i++){
        for(char c : board[i]){
            s.push_back(c);
        }
        std::cout << s << std::endl;
        s.clear();
    }

    return 0;
}
