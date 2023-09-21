#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio> // Подключение библиотеки для работы с вводом-выводом
#include <cstdlib> // Подключение библиотеки для работы с памятью и преобразованием типов
#include <cstring> // Подключение библиотеки для работы со строками
#include <locale.h> // Подключение библиотеки для работы с локалью

// Определение структуры Node для узлов стека
struct Node {
	char inf[256]; // Массив для хранения данных
	Node* next; // Указатель на следующий узел стека
};

Node* head = nullptr; // Указатель на вершину стека

// Функция для создания нового узла стека
Node* createNode() {
	Node* newNode = new Node; // Выделяем память под новый узел
	char s[256];
	printf("Введите название элемента: ");
	scanf("%s", s);

	// Проверка на пустую строку
	if (strlen(s) == 0) {
		printf("Элемент не добавлен\n");
		return nullptr;
	}

	// Копирование данных в новый узел
	strcpy(newNode->inf, s);
	newNode->next = nullptr;
	return newNode;
}

// Функция для добавления узла на вершину стека
void push() {
	Node* newNode = createNode();
	if (newNode == nullptr) return;
	newNode->next = head;
	head = newNode;
}

// Функция для удаления узла с вершины стека
void pop() {
	if (head == nullptr) {
		printf("Стек пуст\n");
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
}

// Функция для просмотра данных на вершине стека
void peek() {
	if (head == nullptr) {
		printf("Стек пуст\n");
		return;
	}
	printf("Верхний элемент стека: %s\n", head->inf);
}

// Функция для просмотра всех узлов стека
void review() {
	Node* temp = head;
	if (head == nullptr) {
		printf("Стек пуст\n");
		return;
	}
	while (temp) {
		printf("Элемент стека: %s\n", temp->inf);
		temp = temp->next;
	}
}

// Главная функция программы
int main() {
	setlocale(LC_ALL, "RUS"); // Установка русской локали
	int choice; // Переменная для хранения выбора пользователя

	// Цикл для работы с меню
	do {
		printf("-------------------------------------------------\n");
		printf("1. Добавить элемент в стек \n2. Удалить элемент из стека\n3. Посмотреть верхний элемент стека\n4. Просмотреть весь стек\n5. Выйти\n");
		printf("Ваш выбор: ");
		scanf("%d", &choice);

		// Обработка выбора пользователя
		switch (choice) {
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			peek();
			break;
		case 4:
			review();
			break;
		case 5:
			printf("Выход\n");
			break;
		default:
			printf("Неправильный выбор. Попробуйте еще раз.\n");
			break;
		}
	} while (choice != 5); // Цикл продолжается, пока не выбрана опция "Выйти"

	return 0; 
}