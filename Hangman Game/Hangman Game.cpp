#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <string>

#define WRONGTRIES 5

void DrawMan(int tries)
{
    std::cout << std::endl << std::endl;
    std::cout << "  -----" << std::endl;
    std::cout << "  |   |" << std::endl;
    std::cout << "  |"; if (tries >= 1) std::cout << "   O   "; std::cout << std::endl;
    std::cout << "  |"; if (tries >= 3) std::cout << "  /|\\   "; std::cout << std::endl;
    std::cout << "  |"; if (tries >= 5) std::cout << "  / \\   "; std::cout << std::endl;
    std::cout << "  |" << std::endl;
    std::cout << "__|__" << std::endl;
}

int main()
{
    srand (time(NULL));
    std::string wordList[5] = { "apple", "peach", "banana", "strawberry", "mango" };
    std::string word;
    std::string guessed;

    word = wordList[rand() % 5];

    int wordLength = word.length();
    std::string dispWord(wordLength, '_');

    int found = 0;
    char guess = ' ';
    int tries = 5; //No of wrong tries
    int flagFound = 0;

    while (tries >= 0)
    {
        system("cls");
        std::cout << "Guess Fruit Name: " << std::endl << std::endl;

        for (int i = 0; i < wordLength; i++)
            std::cout << " " << dispWord[i] << " ";
        std::cout << std::endl << std::endl << std::endl;

        std::cout << "Wrong Attempts: " << tries << " / " << WRONGTRIES << std::endl;
        std::cout << "Guessed Letters: " << guessed << std::endl;

        DrawMan(tries);

        if (found == wordLength)
        {
            std::cout << std::endl;
            std::cout << "*******************" << std::endl;
            std::cout << "***** You Win *****" << std::endl;
            std::cout << "*******************" << std::endl;
            break;
        }

        if (tries == 0) break;

        std::cout << "Pick a letter:";
        guess = _getche();

        guessed = guessed + " " + guess;

        if (dispWord.find(guess) != std::string::npos) tries++;

        flagFound = 0;
        for (int i = 0; i < wordLength; i++)
        {
            if (word[i] == guess && dispWord[i] == '_')
            {
                dispWord[i] = guess;
                found++;
                flagFound = 1;
            }
        }

        if (!flagFound)
            tries--;
    }
    if (found != wordLength)
    {
        std::cout << std::endl;
        std::cout << "*******************" << std::endl;
        std::cout << "***** You Lose *****" << std::endl;
        std::cout << "*******************" << std::endl;
    }

    _getch();
    return 0;   
}

