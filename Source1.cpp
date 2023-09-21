//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale.h>
//
//// Определение структуры для хранения элементов очереди
//struct Node {
//	char inf[256]; // Информационное поле (название объекта)
//	struct Node* next; // Указатель на следующий элемент в очереди
//};
//
//int main() {
//	setlocale(LC_ALL, "RUS"); // Установка русской локализации для консоли
//
//	int numQueues; // Количество очередей
//	printf("Введите количество очередей: ");
//	scanf("%d", &numQueues);
//
//	// Выделение памяти для массива указателей на головы очередей
//	struct Node** heads = (struct Node**)malloc(numQueues * sizeof(struct Node*));
//	// Выделение памяти для массива указателей на хвосты очередей
//	struct Node** lasts = (struct Node**)malloc(numQueues * sizeof(struct Node*));
//
//	// Инициализация указателей на головы и хвосты всех очередей как NULL
//	for (int i = 0; i < numQueues; ++i) {
//		heads[i] = NULL;
//		lasts[i] = NULL;
//	}
//
//	// Главный цикл программы
//	while (1) {
//		int choice, queueNum; // choice для хранения выбранного действия, queueNum для номера очереди
//		printf("-------------------------------------------------\n");
//		printf("1. Добавить элемент в очередь\n2. Удалить элемент из очереди\n3. Просмотреть очередь\n4. Выйти\n");
//		printf("Выберите действие: ");
//		scanf("%d", &choice);
//
//		// Условие для выхода из цикла
//		if (choice == 4) break;
//
//		printf("Выберите номер очереди (от 1 до %d): ", numQueues);
//		scanf("%d", &queueNum);
//		queueNum--; // Переход к индексации с 0
//
//		// Проверка корректности номера очереди
//		if (queueNum < 0 || queueNum >= numQueues) {
//			printf("Неверный номер очереди.\n");
//			continue;
//		}
//
//		// Добавление элемента в очередь
//		if (choice == 1) {
//			struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Выделение памяти для нового узла
//			printf("Введите название объекта: ");
//			scanf("%s", newNode->inf); // Считывание информации
//			newNode->next = NULL; // Установка указателя next как NULL
//
//			// Если очередь пуста, добавить элемент как первый и последний
//			if (heads[queueNum] == NULL && lasts[queueNum] == NULL) {
//				heads[queueNum] = lasts[queueNum] = newNode;
//			}
//			else {
//				// Если не пуста, добавить элемент в конец и обновить указатель на последний элемент
//				lasts[queueNum]->next = newNode;
//				lasts[queueNum] = newNode;
//			}
//
//		}
//		else if (choice == 2) {
//			// Удаление элемента из очереди
//			if (heads[queueNum] == NULL) { // Если очередь пуста, вывод сообщения
//				printf("Очередь пуста.\n");
//				continue;
//			}
//			struct Node* temp = heads[queueNum]; // Временный указатель для удаления
//			heads[queueNum] = heads[queueNum]->next; // Сдвиг головы на следующий элемент
//			free(temp); // Освобождение памяти
//
//		}
//		else if (choice == 3) {
//			// Просмотр содержимого очереди
//			struct Node* current = heads[queueNum]; // Начало с головы
//			if (current == NULL) { // Если очередь пуста
//				printf("Очередь пуста.\n");
//				continue;
//			}
//			// Проход по всей очереди и вывод каждого элемента
//			while (current) {
//				printf("Имя - %s\n", current->inf);
//				current = current->next;
//			}
//		}
//	}
//
//	// Освобождение памяти, выделенной для массивов heads и lasts
//	free(heads);
//	free(lasts);
//
//	return 0;
//}