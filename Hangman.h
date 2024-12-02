#ifndef HANGMAN_H
#define HANGMAN_H

#include <vector>
#include <string>

// Объявление глобального списка слов
extern std::vector<std::string> word_list;

// Функция для получения случайного слова из списка
// Параметр seed позволяет задавать зерно для генератора случайных чисел (для тестирования)
std::string get_word(const std::vector<std::string>& lst, int seed = 0);

// Функция для отображения текущего состояния виселицы
std::string display_hangman(int tries);

// Функция для запуска игры
void play(const std::string& word);

#endif // HANGMAN_H
