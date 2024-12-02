#include "hangman.h"
#include <algorithm>
#include <cctype>
#include <iostream>

int main() {


    std::vector<std::string> answers = { "YES", "NO" }; // Список возможных ответов
    while (true) {
        std::string word = get_word(word_list, 0); // Получение случайного слова
        play(word); // Начало игры
        std::string question; // Переменная для ответа на вопрос о продолжении игры
        while (true) {
            std::cout << "Сыграть ещё раз? (Yes/No): ";
            std::cin >> question;
            std::transform(question.begin(), question.end(), question.begin(), ::toupper); // Преобразование ответа в верхний регистр
            if (std::find(answers.begin(), answers.end(), question) != answers.end()) {
                break;
            }
            else {
                std::cout << "Неверный ввод!\n";
            }
        }
        if (question == "NO") break; // Если ответ "Нет", то выход из цикла
    }
    return 0;
}
