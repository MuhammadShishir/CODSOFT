#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;
    std::cout << "Hi & Welcome to the number guessing game.\n";
    std::cout << "I picked a number between 1 to 100. Guess the number.\n";
    std::cout << "I will let you know if too high or too low.\n";
    while (true) {
        std::cout << "\nYour guess: ";
        std::cin >> userGuess;

        if (userGuess < randomNumber) {
            std::cout << "Not quite! Go higher than that. Try again.";
        } else if (userGuess > randomNumber) {
            std::cout << "That is too high! Go lower.";
        } else {
            std::cout << "Yes! The number was " << randomNumber << ". Good Job.\n";
            break;
        }
    }
    return 0;
}
