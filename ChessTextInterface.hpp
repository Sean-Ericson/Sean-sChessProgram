/* 
 * File:   ChessTextInterface.hpp
 * Author: Sean
 *
 * Created on February 25, 2015, 9:39 PM
 */

#ifndef CHESSTEXTINTERFACE_HPP
#define	CHESSTEXTINTERFACE_HPP

#include "ChessGame.hpp"

#include <string>

class TextInterface
{
private:
    
    bool gameRunning = true;
    ChessGame game;

public:
    
    TextInterface()
    {
        std::cout << "TextInterface constructed" << std::endl;
    }
    
    ~TextInterface()
    {
        std::cout << "TextInterface destructed" << std::endl;
    }
    
    void run(void)
    {   
        std::string input;
        
        printWelcome();
        game.setBoard(STANDARD);
        
        while (gameRunning)
        {
            std::cout << "Input: ";
            std::cin >> input;
            std::cout << std::endl;
            
            parseInput(input);
        }
    }
    
    void parseInput(std::string str)
    {
        if (str == "new")
        {
            newGame();
        }
        else if (str == "help")
        {
            printHelp();
        }
        else if (str == "board")
        {
            printBoard();
        }
        else if (str == "move")
        {
            promptMove();
        }
        else if (str == "promote")
        {
            promptPromote();
        }
        else if (str == "castle")
        {
            promptCastle();
        }
        else if (str == "quit")
        {
            quit();
        }
        else
        {
            std::cout << "unknown command" << std::endl << std::endl;
        }
    }
    
    void quit(void)
    {
        std::cout << "you quite" << std::endl << std::endl;
        gameRunning = false;
    }
    
    void promptMove(void)
    {
        int f1, r1, f2, r2;
        
        std::cout << "File 1: ";
        std::cin >> f1;
        std::cout << "Rank 1: ";
        std::cin >> r1;
        std::cout << "File 2: ";
        std::cin >> f2;
        std::cout << "Rank 2: ";
        std::cin >> r2;
        
        if (game.move(f1, r1, f2, r2))
            std::cout << std::endl << "Move success" << std::endl << std::endl;
        else
            std::cout << std::endl << "Move fail" << std::endl << std::endl;
    }
    
    void promptPromote(void)
    {
        std::cout << "you promoted" << std::endl << std::endl;
    }
    
    void promptCastle(void)
    {
        std::cout << "you castled" << std::endl << std::endl;
    }
    
    void newGame(void)
    {
        std::cout << "you started a new game" << std::endl << std::endl;
    }
    
    void printBoard(void)
    {
        std::string pieceName;
        
        for (short int i = MAX_RANK; i >= MIN_RANK; --i)
        {
            std::cout << std::endl << i + 1 << "    ";
            
            for (short int j = MIN_FILE; j <= MAX_FILE; ++j)
            {
                switch (game.getBoard().getPieceType(j, i))
                {
                    case EMPTY_TYPE:
                        std::cout << "_ ";
                        break;
                    case PAWN:
                        std::cout << "p ";
                        break;
                    case ROOK:
                        std::cout << "r ";
                        break;
                    case KNIGHT:
                        std::cout << "n ";
                        break;
                    case BISHOP:
                        std::cout << "b ";
                        break;
                    case QUEEN:
                        std::cout << "q ";
                        break;
                    case KING:
                        std::cout << "k ";
                        break;
                }
            }
        }
        
        std::cout << std::endl << std::endl << "     A B C D E F G H" << std::endl << std::endl;
        std::cout << std::endl << std::endl;
    }
    
    void printWelcome(void)
    {
        std::cout << "This is a chess game. Type help for help." << std::endl << std::endl;
    }
    
    void printHelp(void)
    {
        std::cout << "Commands:" << std::endl;
        std::cout << "\"new\"     starts a new game" << std::endl;
        std::cout << "\"board\"   displays the board" << std::endl;
        std::cout << "\"move\"    prompts you to move a piece" << std::endl;
        std::cout << "\"promote\" prompts you to promote a pawn" << std::endl;
        std::cout << "\"castle\"  prompts you to castle" << std::endl;
        std::cout << "\"quit\"  quits the game" << std::endl;
        std::cout << std::endl;
    }
        
};

#endif	/* CHESSTEXTINTERFACE_HPP */

