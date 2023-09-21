#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio> // ����������� ���������� ��� ������ � ������-�������
#include <cstdlib> // ����������� ���������� ��� ������ � ������� � ��������������� �����
#include <cstring> // ����������� ���������� ��� ������ �� ��������
#include <locale.h> // ����������� ���������� ��� ������ � �������

// ����������� ��������� Node ��� ����� �����
struct Node {
	char inf[256]; // ������ ��� �������� ������
	Node* next; // ��������� �� ��������� ���� �����
};

Node* head = nullptr; // ��������� �� ������� �����

// ������� ��� �������� ������ ���� �����
Node* createNode() {
	Node* newNode = new Node; // �������� ������ ��� ����� ����
	char s[256];
	printf("������� �������� ��������: ");
	scanf("%s", s);

	// �������� �� ������ ������
	if (strlen(s) == 0) {
		printf("������� �� ��������\n");
		return nullptr;
	}

	// ����������� ������ � ����� ����
	strcpy(newNode->inf, s);
	newNode->next = nullptr;
	return newNode;
}

// ������� ��� ���������� ���� �� ������� �����
void push() {
	Node* newNode = createNode();
	if (newNode == nullptr) return;
	newNode->next = head;
	head = newNode;
}

// ������� ��� �������� ���� � ������� �����
void pop() {
	if (head == nullptr) {
		printf("���� ����\n");
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
}

// ������� ��� ��������� ������ �� ������� �����
void peek() {
	if (head == nullptr) {
		printf("���� ����\n");
		return;
	}
	printf("������� ������� �����: %s\n", head->inf);
}

// ������� ��� ��������� ���� ����� �����
void review() {
	Node* temp = head;
	if (head == nullptr) {
		printf("���� ����\n");
		return;
	}
	while (temp) {
		printf("������� �����: %s\n", temp->inf);
		temp = temp->next;
	}
}

// ������� ������� ���������
int main() {
	setlocale(LC_ALL, "RUS"); // ��������� ������� ������
	int choice; // ���������� ��� �������� ������ ������������

	// ���� ��� ������ � ����
	do {
		printf("-------------------------------------------------\n");
		printf("1. �������� ������� � ���� \n2. ������� ������� �� �����\n3. ���������� ������� ������� �����\n4. ����������� ���� ����\n5. �����\n");
		printf("��� �����: ");
		scanf("%d", &choice);

		// ��������� ������ ������������
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
			printf("�����\n");
			break;
		default:
			printf("������������ �����. ���������� ��� ���.\n");
			break;
		}
	} while (choice != 5); // ���� ������������, ���� �� ������� ����� "�����"

	return 0; 
}