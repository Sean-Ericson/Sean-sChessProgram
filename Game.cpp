#include "ChessGame.hpp"

//////////////////////////////////////////////////////////////////////
// Piece Classes Methods
//////////////////////////////////////////////////////////////////////

Empty::Empty()
{
    type = EMPTY_TYPE;
    color = EMPTY_COLOR;
}

Pawn::Pawn(Color c)
{
    color = c;
    type = PAWN;
}

bool Pawn::legalMove(const Board& board, int file1, int rank1, int file2, int rank2)
{
    //move rules for pawn
    if (board.getPieceType(file1, rank1) == WHITE)
    {
        if (rank1 == 1)
        {
            
        }
    }
    
    return true;
}

bool Pawn::legalMove(const Board& board, Square square1, Square square2)
{
    return legalMove(square1.file, square1.rank, square2.file, square2.rank);
}

Rook::Rook(Color c)
{
    color = c;
    type = ROOK;
}

bool Rook::legalMove(const Board& board, int file1, int rank1, int file2, int rank2)
{
    return true;
}

bool Rook::legalMove(const Board& board, Square square1, Square square2)
{
    return legalMove(square1.file, square1.rank, square2.file, square2.rank);
}

Knight::Knight(Color c)
{
    color = c;
    type = KNIGHT;
}

bool Knight::legalMove(const Board& board, int file1, int rank1, int file2, int rank2)
{
    return true;
}

bool Knight::legalMove(const Board& board, Square square1, Square square2)
{
    return legalMove(square1.file, square1.rank, square2.file, square2.rank);
}

Bishop::Bishop(Color c)
{
    color = c;
    type = BISHOP;
}

bool Bishop::legalMove(const Board& board, int file1, int rank1, int file2, int rank2)
{
    return true;
}

bool Bishop::legalMove(const Board& board, Square square1, Square square2)
{
    return legalMove(square1.file, square1.rank, square2.file, square2.rank);
}

Queen::Queen(Color c)
{
    color = c;
    type = QUEEN;
}

bool Queen::legalMove(const Board& board, int file1, int rank1, int file2, int rank2)
{
    return true;
}

bool Queen::legalMove(const Board& board, Square square1, Square square2)
{
    return legalMove(square1.file, square1.rank, square2.file, square2.rank);
}

King::King(Color c)
{
    color = c;
    type = KING;
}

bool King::legalMove(const Board& board, int file1, int rank1, int file2, int rank2)
{
    return true;
}

bool King::legalMove(const Board& board, Square square1, Square square2)
{
    return legalMove(square1.file, square1.rank, square2.file, square2.rank);
}

//////////////////////////////////////////////////////////////////////
// Board Class Methods
//////////////////////////////////////////////////////////////////////

Board::Board()
{
    std::cout << "Constructing board" << std::endl;
    for (short int i = MIN_FILE; i <= MAX_FILE; ++i)
    {
        for (short int j = MIN_RANK; j <= MAX_RANK; ++j)
        {
            board[i][j] = new Empty;
            if (board[i][j] == 0)
                std::cout << "Uhh, did board[" << i << "][" << j << "] not allocate?" << std::endl;
        }
    }
    isEmpty = true;
    std::cout << "Board constructed" << std::endl;
}

Board::Board(const Board& original)
{
    for (register short int i = MIN_FILE; i <= MAX_FILE; ++i)
    {
        for (register short int j = MIN_FILE; j <= MAX_FILE; ++j)
        {
            switch (original.board[i][j]->type)
            {
                case EMPTY_TYPE:
                    board[i][j] = new Empty;
                    break;
                case PAWN:
                    board[i][j] = new Pawn(original.board[i][j]->color);
                    break;
                case ROOK:
                    board[i][j] = new Rook(original.board[i][j]->color);
                    break;
                case KNIGHT:
                    board[i][j] = new Knight(original.board[i][j]->color);
                    break;
                case BISHOP:
                    board[i][j] = new Bishop(original.board[i][j]->color);
                    break;
                case QUEEN:
                    board[i][j] = new Queen(original.board[i][j]->color);
                    break;
                case KING:
                    board[i][j] = new King(original.board[i][j]->color);
            }
        }
    }
    if (original.isEmpty)
        isEmpty = true;
    else
        isEmpty = false;
}

Board::~Board()
{
    std::cout << "Deconstructing board" << std::endl;
    for (short int i = MIN_FILE; i <= MAX_FILE; ++i)
    {
        for (short int j = MIN_RANK; j <= MAX_RANK; ++j)
        {
            if (board[i][j] != 0)
            {
                delete board[i][j];
            }
        }
    }
    std::cout << "Board deconstructed" << std::endl;
}

bool Board::clear()
{
    for (register char i = MIN_FILE; i <= MAX_FILE; ++i)
    {
        for (register char j = MIN_RANK; j < MAX_RANK; ++j)
        {
            if (board[i][j] != 0)
            {
                delete board[i][j];
                board[i][j] = new Empty;
            }
            else
            {
                board[i][j] = new Empty;
            }
        }
    }
    
    return true;
}

PieceType Board::getPieceType(int file, int rank) const
{
    //Throw error if out of bound
    
    return board[file][rank]->type;
}

PieceType Board::getPieceType(Square square) const
{
    //Throw error if out of bound
    
    return board[square.file][square.rank]->type;
}

Color Board::getPieceColor(int file, int rank) const
{
    //Throw error if out of bound
    
    return board[file][rank]->color;
}

Color Board::getPieceColor(Square square) const
{
    //Throw error if out of bound
    
    return board[square.file][square.rank]->color;
}

bool Board::movePiece(int file1, int rank1, int file2, int rank2)
{
    // Throw error for out of bound
    
    setPiece(file2, rank2, board[file1][rank1]->type, board[file1][rank1]->color);
    setPiece(file1, rank1, EMPTY_TYPE, EMPTY_COLOR);
    
    return true;
}

bool Board::movePiece(Square square1, Square square2)
{
    return movePiece(square1.file, square1.rank, square2.file, square2.rank);
}

bool Board::setPiece(int file, int rank, PieceType type, Color color)
{
    //Error for out of bound
    
    if (board[file][rank] != 0 )
        delete board[file][rank];
    
    switch (type)
    {
        case EMPTY_TYPE:
            board[file][rank] = new Empty;
            break;
        case PAWN:
            board[file][rank] = new Pawn(color);
            break;
        case ROOK:
            board[file][rank] = new Rook(color);
            break;
        case KNIGHT:
            board[file][rank] = new Knight(color);
            break;
        case BISHOP:
            board[file][rank] = new Bishop(color);
            break;
        case QUEEN:
            board[file][rank] = new Queen(color);
            break;
        case KING:
            board[file][rank] = new King(color);
            break;
    }
    
    return true;
}

bool Board::setPiece(Square square, PieceType type, Color color)
{
    //Error stuffz
    
    return setPiece(square.file, square.rank, type, color);
}

bool Board::switchPiece(int file1, int rank1, int file2, int rank2)
{
    //Error gayz
    
    Piece* tempPiece = board[file1][rank1];
    board[file1][rank1] = board[file2][rank2];
    board[file2][rank2] = tempPiece;
    
    return true;
}

bool Board::switchPiece(Square square1, Square square2)
{
    //Error bounds
    
    return switchPiece(square1.file, square1.rank, square2.file, square2.rank);
}

Board& Board::operator= (const Board& original)
{
    if (this != &original) // protection against copy into self
    {
        for (register char i = MIN_FILE; i <= MAX_FILE; ++i)
    {
        for (register char j = MIN_FILE; j <= MAX_FILE; ++j)
        {
            if (board[i][j] != 0)
                delete board[i][j];
            
            switch (original.board[i][j]->type)
            {
                case PAWN:
                    board[i][j] = new Pawn(original.board[i][j]->color);
                    break;
                case ROOK:
                    board[i][j] = new Rook(original.board[i][j]->color);
                    break;
                case KNIGHT:
                    board[i][j] = new Knight(original.board[i][j]->color);
                    break;
                case BISHOP:
                    board[i][j] = new Bishop(original.board[i][j]->color);
                    break;
                case QUEEN:
                    board[i][j] = new Queen(original.board[i][j]->color);
                    break;
                case KING:
                    board[i][j] = new King(original.board[i][j]->color);
            }
        }
    }
    if (original.isEmpty)
        isEmpty = true;
    else
        isEmpty = false;
    }
    return *this;
}

bool Board::operator ==(const Board& comparedTo)
{
    if (isEmpty != comparedTo.isEmpty)
        return false;
    
    for (register char i = MIN_FILE; i <= MAX_FILE; ++i)
    {
        for (register char j = MIN_FILE; j <= MAX_FILE; ++j)
        {
            if (board[i][j]->type != comparedTo.board[i][j]->type)
                return false;
            
            if (board[i][j]->color != comparedTo.board[i][j]->color)
                return false;
        }
    }
    
    return true;
}

bool Board::operator !=(const Board& comparedTo)
{
    return !(*this == comparedTo);
}

//////////////////////////////////////////////////////////////////////
// ChessGame Class Methods
//////////////////////////////////////////////////////////////////////

ChessGame::ChessGame()
{
    std::cout << "ChessGame constructed" << std::endl;
}

const Board& ChessGame::getBoard(void)
{
    return board;
}

bool ChessGame::move(int file1, int rank1, int file2, int rank2)
{
    // STEPS FOR CHECKING LEGAL MOVE
    // 1. Make sure the game isn't over
    // 2. Make sure an empty piece is not being moved
    // 3. Make sure it's the correct player's turn
    // 4. Make sure the piece can do that move
    // 5. Make sure the player is not capturing their own piece?
    // 6. Make sure the move doesn't result in the player being in check 
    // 7. If the move is a capture...do stuff...
    
    if (board.getPieceType(file1, rank1) == EMPTY_TYPE)
        return false;
    
    return board.movePiece(file1, rank1, file2, rank2);
}

bool ChessGame::move(Square square1, Square square2)
{
    return move(square1.file, square1.rank, square2.file, square2.rank);
}

bool ChessGame::newGame(GameType newType)
{
    if (newType == STANDARD)
    {
        type = STANDARD;
        activePlayer = WHITE;
        winner = EMPTY_COLOR;
        gameActive = true;
        setBoard(newType);
    }
}

void ChessGame::setBoard(GameType type)
{
    if (type == STANDARD)
    {
        for (short int i = MIN_FILE; i <= MAX_FILE; ++i)
        {
            board.setPiece(i, 1, PAWN, WHITE);
            board.setPiece(i, 6, PAWN, BLACK);
        }
        
        board.setPiece(0, 0, ROOK, WHITE);
        board.setPiece(7, 0, ROOK, WHITE);
        board.setPiece(0, 7, ROOK, BLACK);
        board.setPiece(7, 7, ROOK, BLACK);
        board.setPiece(1, 0, KNIGHT, WHITE);
        board.setPiece(6, 0, KNIGHT, WHITE);
        board.setPiece(1, 7, KNIGHT, BLACK);
        board.setPiece(6, 7, KNIGHT, BLACK);
        board.setPiece(2, 0, BISHOP, WHITE);
        board.setPiece(5, 0, BISHOP, WHITE);
        board.setPiece(2, 7, BISHOP, BLACK);
        board.setPiece(5, 7, BISHOP, BLACK);
        board.setPiece(3, 0, QUEEN, WHITE);
        board.setPiece(3, 7, QUEEN, BLACK);
        board.setPiece(4, 0, KING, WHITE);
        board.setPiece(4, 7, KING, BLACK);
    }
}