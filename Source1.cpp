//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale.h>
//
//// ����������� ��������� ��� �������� ��������� �������
//struct Node {
//	char inf[256]; // �������������� ���� (�������� �������)
//	struct Node* next; // ��������� �� ��������� ������� � �������
//};
//
//int main() {
//	setlocale(LC_ALL, "RUS"); // ��������� ������� ����������� ��� �������
//
//	int numQueues; // ���������� ��������
//	printf("������� ���������� ��������: ");
//	scanf("%d", &numQueues);
//
//	// ��������� ������ ��� ������� ���������� �� ������ ��������
//	struct Node** heads = (struct Node**)malloc(numQueues * sizeof(struct Node*));
//	// ��������� ������ ��� ������� ���������� �� ������ ��������
//	struct Node** lasts = (struct Node**)malloc(numQueues * sizeof(struct Node*));
//
//	// ������������� ���������� �� ������ � ������ ���� �������� ��� NULL
//	for (int i = 0; i < numQueues; ++i) {
//		heads[i] = NULL;
//		lasts[i] = NULL;
//	}
//
//	// ������� ���� ���������
//	while (1) {
//		int choice, queueNum; // choice ��� �������� ���������� ��������, queueNum ��� ������ �������
//		printf("-------------------------------------------------\n");
//		printf("1. �������� ������� � �������\n2. ������� ������� �� �������\n3. ����������� �������\n4. �����\n");
//		printf("�������� ��������: ");
//		scanf("%d", &choice);
//
//		// ������� ��� ������ �� �����
//		if (choice == 4) break;
//
//		printf("�������� ����� ������� (�� 1 �� %d): ", numQueues);
//		scanf("%d", &queueNum);
//		queueNum--; // ������� � ���������� � 0
//
//		// �������� ������������ ������ �������
//		if (queueNum < 0 || queueNum >= numQueues) {
//			printf("�������� ����� �������.\n");
//			continue;
//		}
//
//		// ���������� �������� � �������
//		if (choice == 1) {
//			struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // ��������� ������ ��� ������ ����
//			printf("������� �������� �������: ");
//			scanf("%s", newNode->inf); // ���������� ����������
//			newNode->next = NULL; // ��������� ��������� next ��� NULL
//
//			// ���� ������� �����, �������� ������� ��� ������ � ���������
//			if (heads[queueNum] == NULL && lasts[queueNum] == NULL) {
//				heads[queueNum] = lasts[queueNum] = newNode;
//			}
//			else {
//				// ���� �� �����, �������� ������� � ����� � �������� ��������� �� ��������� �������
//				lasts[queueNum]->next = newNode;
//				lasts[queueNum] = newNode;
//			}
//
//		}
//		else if (choice == 2) {
//			// �������� �������� �� �������
//			if (heads[queueNum] == NULL) { // ���� ������� �����, ����� ���������
//				printf("������� �����.\n");
//				continue;
//			}
//			struct Node* temp = heads[queueNum]; // ��������� ��������� ��� ��������
//			heads[queueNum] = heads[queueNum]->next; // ����� ������ �� ��������� �������
//			free(temp); // ������������ ������
//
//		}
//		else if (choice == 3) {
//			// �������� ����������� �������
//			struct Node* current = heads[queueNum]; // ������ � ������
//			if (current == NULL) { // ���� ������� �����
//				printf("������� �����.\n");
//				continue;
//			}
//			// ������ �� ���� ������� � ����� ������� ��������
//			while (current) {
//				printf("��� - %s\n", current->inf);
//				current = current->next;
//			}
//		}
//	}
//
//	// ������������ ������, ���������� ��� �������� heads � lasts
//	free(heads);
//	free(lasts);
//
//	return 0;
//}