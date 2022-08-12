 #include <iostream>
 #include <ctime>


void PrintIntroduction(int DifficultyLevel)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << DifficultyLevel;
    std::cout << " secure server room...Enter the correct code to continue...";
}


bool PlayGame(int DifficultyLevel)
{
    PrintIntroduction(DifficultyLevel);

    const int CodeA = rand() % DifficultyLevel + DifficultyLevel;
    const int CodeB = rand() % DifficultyLevel + DifficultyLevel;
    const int CodeC = rand() % DifficultyLevel + DifficultyLevel;
    // const makes that the variable declared or initialized isnt changed

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

   
    std::cout << "\n + The sum is: " << CodeSum ;
    std::cout <<"\n + The product is: " << CodeProduct << std::endl; 
    
    int GuessA, GuessB, GuessC;

    // Store player's guess 
    std::cin >> GuessA >> GuessB >> GuessC;

    /*std::cin >> GuessB;
      std::cin >> GuessC; 
    */

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player's guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou win!";
        return true;
    }
    else
    {
        std::cout << "\nYou fucked up!";
        return false;
    }
}


int main()
{
    srand(time(NULL));

    int LevelDiff =1;
    int const MaxLevel = 5;

    while (LevelDiff <= MaxLevel)// loop game till completed
     {
        bool bLevelComplete = PlayGame(LevelDiff);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if(bLevelComplete){
            //increase level
            ++LevelDiff;
        }
     }

    std::cout << "\n***Great work, agent! You got all the files! Now get out of here! ***\n"; 
    return 0;
}