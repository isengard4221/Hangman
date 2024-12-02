# Makefile

# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Исходные файлы
SRCS = main.cpp hangman.cpp
TEST_SRCS = test.cpp hangman.cpp

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Целевые файлы
TARGET = hangman.exe
TEST_TARGET = test_hangman.exe

# По умолчанию
all: $(TARGET)

# Компиляция исходных файлов
%.o: %.cpp hangman.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Линковка основного приложения
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Линковка тестового приложения
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Цель для сборки и запуска тестов
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Очистка сборки
clean:
	del /Q *.o *.exe

.PHONY: all test clean
