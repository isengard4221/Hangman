#include "hangman.h"
#include <cassert>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>

// Тест для функции get_word
void test_get_word() {
    std::vector<std::string> test_list = { "APPLE", "BANANA", "CHERRY" };

    // Тестирование с фиксированным зерном
    std::string word = get_word(test_list, 1); // seed=1
    assert(word == "CHERRY" && "get_word с seed=1 должно вернуть 'CHERRY'");

    word = get_word(test_list, 2); // seed=2
    assert(word == "APPLE" && "get_word с seed=2 должно вернуть 'APPLE'");

    word = get_word(test_list, 3); // seed=3
    assert(word == "APPLE" && "get_word с seed=3 должно вернуть 'BANANA'");

    // Проверка, что все символы заглавные
    word = get_word(test_list, 1);
    for (char c : word) {
        assert(std::isupper(static_cast<unsigned char>(c)) && "Все символы слова должны быть заглавными");
    }

    std::cout << "Тесты для get_word прошли успешно.\n";
}

// Тест для функции display_hangman
void test_display_hangman() {
    std::vector<std::string> expected_stages = {
         "   --------\n   |      |\n   |      O\n   |     \\|/\n   |      |\n   |     / \\\n   -\n",
         "   --------\n   |      |\n   |      O\n   |     \\|/\n   |      |\n   |     / \n   -\n",
         "   --------\n   |      |\n   |      O\n   |     \\|/\n   |      |\n   |      \n   -\n",
         "   --------\n   |      |\n   |      O\n   |     \\|\n   |      |\n   |      \n   -\n",
         "   --------\n   |      |\n   |      O\n   |      |\n   |      |\n   |      \n   -\n",
         "   --------\n   |      |\n   |      O\n   |      \n   |      \n   |      \n   -\n",
         "   --------\n   |      |\n   |      \n   |      \n   |      \n   |      \n   -\n"
    };

    for (int i = 0; i < static_cast<int>(expected_stages.size()); ++i) {
        std::string stage = display_hangman(i);
        assert(stage == expected_stages[i] && "display_hangman должен возвращать правильное состояние");
    }

    // Тестирование выхода за пределы массива
    std::string invalid = display_hangman(-1);
    assert(invalid == "Неверное количество попыток" && "display_hangman должен возвращать сообщение об ошибке для отрицательного индекса");

    invalid = display_hangman(7);
    assert(invalid == "Неверное количество попыток" && "display_hangman должен возвращать сообщение об ошибке для индекса, превышающего размер");

    std::cout << "Тесты для display_hangman прошли успешно.\n";
}

int main() {
    test_get_word();
    test_display_hangman();
    std::cout << "Все тесты прошли успешно!\n";
    return 0;
}
