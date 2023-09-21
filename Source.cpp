#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <locale.h>

// Структура Node для хранения элементов очереди
struct Node {
	int data; // Данные
	int priority; // Приоритет
	Node* next; // Указатель на следующий элемент в очереди
};

// Класс PriorityQueue для реализации очереди с приоритетом
class PriorityQueue {
private:
	Node* head; // Указатель на голову (самый высокий приоритет)

public:
	// Конструктор для инициализации head как nullptr
	PriorityQueue() : head(nullptr) {}

	// Функция добавления элемента в очередь
	void push(int data, int priority) {
		Node* temp = new Node(); // Создание нового узла
		temp->data = data; // Заполнение данных
		temp->priority = priority; // Заполнение приоритета
		temp->next = nullptr; // Установка следующего указателя как nullptr

		// Вставка нового узла в соответствующее место по приоритету
		if (head == nullptr || head->priority < priority) {
			temp->next = head;
			head = temp;
		}
		else {
			Node* current = head; // Текущий узел для итерации
			// Ищем подходящее место для вставки
			while (current->next != nullptr && current->next->priority >= priority) {
				current = current->next;
			}
			// Вставляем новый узел
			temp->next = current->next;
			current->next = temp;
		}
	}

	// Удаление элемента с наивысшим приоритетом
	int popHighestPriority() {
		if (head == nullptr) {
			printf("Очередь пуста.\n");
			return -1;
		}
		Node* temp = head; // Временный узел для хранения головы
		head = head->next; // Перемещение головы на следующий узел
		int data = temp->data; // Извлечение данных из узла
		delete temp; // Удаление временного узла
		return data; // Возврат данных
	}

	// Удаление элемента с наименьшим приоритетом
	int popLowestPriority() {
		if (head == nullptr) {
			printf("Очередь пуста.\n");
			return -1;
		}
		Node* current = head; // Текущий узел для итерации
		Node* prev = nullptr; // Предыдущий узел для итерации

		// Итерация до последнего узла
		while (current->next != nullptr) {
			prev = current;
			current = current->next;
		}
		// Удаление последнего узла
		if (prev == nullptr) {
			head = nullptr;
		}
		else {
			prev->next = nullptr;
		}
		int data = current->data; // Извлечение данных из узла
		delete current; // Удаление узла
		return data; // Возврат данных
	}
	// Удаление элемента с заданным приоритетом
	int popSpecificPriority(int targetPriority) {
		Node* current = head; // Текущий узел для итерации
		Node* prev = nullptr; // Предыдущий узел для итерации

		// Итерация по всем узлам для поиска узла с заданным приоритетом
		while (current != nullptr) {
			if (current->priority == targetPriority) {
				if (prev == nullptr) {
					head = current->next;
				}
				else {
					prev->next = current->next;
				}
				int data = current->data;
				delete current;
				return data;
			}
			prev = current;
			current = current->next;
		}
		printf("Элемент с приоритетом %d не найден.\n", targetPriority);
		return -1;
	}

	// Отображение всех элементов очереди
	void display() {
		Node* current = head; // Текущий узел для итерации
		while (current != nullptr) {
			printf("Данные: %d, Приоритет: %d\n", current->data, current->priority);
			current = current->next;
		}
	}
};


int main() {
	setlocale(LC_ALL, "RUS");
	PriorityQueue pq; // Объект очереди с приоритетом
	int choice; // Выбор пользователя
	int data; // Данные для добавления или удаления
	int priority; // Приоритет для добавления

	// Основной цикл
	while (true) {
		printf("-------------------------------------------------\n");
		printf("1. Добавить элемент\n2. Удалить элемент с наивысшим приоритетом\n3. Удалить элемент с наименьшим приоритетом\n4. Удалить элемент с выбранным приоритетом\n5 Показать очередь\n6. Выход\n");
		printf("Выберите действие: ");
		scanf("%d", &choice);

		// Обработка выбора пользователя
		switch (choice) {
		case 1:
			printf("Введите число: ");
			scanf("%d", &data);
			printf("Введите приоритет: ");
			scanf("%d", &priority);
			pq.push(data, priority);
			break;
		case 2:
			data = pq.popHighestPriority();
			if (data != -1) {
				printf("Удаленный элемент с наивысшим приоритетом: %d\n", data);
			}
			break;
		case 3:
			data = pq.popLowestPriority();
			if (data != -1) {
				printf("Удаленный элемент с наименьшим приоритетом: %d\n", data);
			}
			break;
		case 4:
			printf("Введите приоритет: ");
			scanf("%d", &priority);
			data = pq.popSpecificPriority(priority);
			if (data != -1) {
				printf("Удаленный элемент с заданным приоритетом: %d\n", data);
			}
			break;
		case 5:
			pq.display();
			break;
		case 6:
			return 0;
		default:
			printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
		}
	}

	return 0;
}