/* 
 * File:   ChessGame.hpp
 * Author: Sean
 *
 * Created on February 24, 2015, 4:53 PM
 */
//file = column
#ifndef CHESSGAME_HPP
#define	CHESSGAME_HPP

#include <vector>
#include <iostream>
#include <string>

//////////////////////////////////////////////////////////////////////
// Constants
//////////////////////////////////////////////////////////////////////

const unsigned short int MIN_FILE = 0;
const unsigned short int MAX_FILE = 7;
const unsigned short int MIN_RANK = 0;
const unsigned short int MAX_RANK = 7;

enum PieceType
{
    EMPTY_TYPE,
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

enum Color
{
    EMPTY_COLOR,
    WHITE,
    BLACK
};

enum GameType
{
    STANDARD,
    TIMED,
    CHESS960
};

//////////////////////////////////////////////////////////////////////
// Square Class
//////////////////////////////////////////////////////////////////////

class Square
{
public:
    short int file, rank;
    
    Square(short int f, short int r)
    {
        //Set bounds on variables
        file = f;
        rank = r;
    }
};

//////////////////////////////////////////////////////////////////////
// Piece Classes
//////////////////////////////////////////////////////////////////////

class Piece
{
public:
    
    PieceType type;
    Color color;
    
    virtual ~Piece() {}
    
    virtual bool legalMove(const Board& board, int file1, int rank1, int file2, int rank2)  = 0;
    virtual bool legalMove(const Board& board, Square square1, Square square2) = 0;
};

class Empty : public Piece
{
public:
    
    Empty();
    bool legalMove(const Board& board, int file1, int rank1, int file2, int rank2)  {return false;}
    bool legalMove(const Board& board, Square square1, Square square2) {return false;}
};

class Pawn : public Piece
{
public:
    
    Pawn(Color c);
    
    bool legalMove(const Board& board, int file1, int rank1, int file2, int rank2) ;
    bool legalMove(const Board& board, Square square1, Square square2);
};

class Rook : public Piece
{
public:
    
    Rook(Color c);
    
    bool legalMove(const Board& board, int file1, int rank1, int file2, int rank2) ;
    bool legalMove(const Board& board, Square square1, Square square2);
};

class Knight : public Piece
{
public:
    
    Knight(Color c);
    
    bool legalMove(const Board& board, int file1, int rank1, int file2, int rank2) ;
    bool legalMove(const Board& board, Square square1, Square square2);
};

class Bishop : public Piece
{
public:
    
    Bishop(Color c);
    
    bool legalMove(const Board& board, int file1, int rank1, int file2, int rank2) ;
    bool legalMove(const Board& board, Square square1, Square square2);
};

class Queen : public Piece
{
public:
    
    Queen(Color c);
    
    bool legalMove(const Board& board, int file1, int rank1, int file2, int rank2) ;
    bool legalMove(const Board& board, Square square1, Square square2);
};

class King : public Piece
{
public:
    
    King(Color c);
    
    bool legalMove(const Board& board, int file1, int rank1, int file2, int rank2) ;
    bool legalMove(const Board& board, Square square1, Square square2);
};

//////////////////////////////////////////////////////////////////////
// Board Class
//////////////////////////////////////////////////////////////////////

class Board
{
private:
    
    Piece* board[MAX_FILE + 1][MAX_RANK + 1];
    bool isEmpty;
    
public:
    
    Board();
    Board(const Board& original);
    ~Board();
    
    bool        clear(void);
    PieceType   getPieceType(int file, int rank) const;
    PieceType   getPieceType(Square square) const;
    Color       getPieceColor(int file, int rank) const;
    Color       getPieceColor(Square square) const;
    bool        movePiece(int file1, int rank1, int file2, int rank2);
    bool        movePiece(Square square1, Square square2);
    bool        setPiece(int file, int rank, PieceType type, Color color);
    bool        setPiece(Square square, PieceType type, Color color);
    bool        switchPiece(int file1, int rank1, int file2, int rank2);
    bool        switchPiece(Square square1, Square square2);
    
    Board&  operator=   (const Board& original);
    bool    operator==  (const Board& comparedTo);
    bool    operator!=  (const Board& comparedTo);
};

//////////////////////////////////////////////////////////////////////
// Player Class
//////////////////////////////////////////////////////////////////////

class Player /* Is this class necessary? idk */
{
public:
    
    //Color color;
    std::vector<Piece*> activePieces;
    std::vector<Piece*> capturedPieces;
    bool inCheck;
};

//////////////////////////////////////////////////////////////////////
// ChessGame Class
//////////////////////////////////////////////////////////////////////

class ChessGame
{
private:
    
    Board board;
    Player blackPlayer, whitePlayer;
    Color activePlayer, winner;
    GameType type;
    std::vector<std::string> moveHistory;
    bool gameActive;
    
public:
    
    ChessGame();
    
    //bool            capture(int file1, int rank1, int file2, int rank2);
    //bool            capture(Square square1, Square square2);
    bool            castle(Color player, bool kingSide);
    bool            enPassant(Color player, int file1, int file2);
    const Board&    getBoard(void);
    bool            inCheck(Board& passedBoard = board, Color player);
    bool            inCheckMate(Board& passedBoard = board, Color player);
    bool            move(int file1, int rank1, int file2, int rank2);
    bool            move(Square square1, Square square2);
    bool            newGame(GameType newType);
    bool            promote(Color player, int file, PieceType newPiece);
    void            setBoard(GameType type); 
};

#endif	/* CHESSGAME_HPP */
