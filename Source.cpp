#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <locale.h>

// ��������� Node ��� �������� ��������� �������
struct Node {
	int data; // ������
	int priority; // ���������
	Node* next; // ��������� �� ��������� ������� � �������
};

// ����� PriorityQueue ��� ���������� ������� � �����������
class PriorityQueue {
private:
	Node* head; // ��������� �� ������ (����� ������� ���������)

public:
	// ����������� ��� ������������� head ��� nullptr
	PriorityQueue() : head(nullptr) {}

	// ������� ���������� �������� � �������
	void push(int data, int priority) {
		Node* temp = new Node(); // �������� ������ ����
		temp->data = data; // ���������� ������
		temp->priority = priority; // ���������� ����������
		temp->next = nullptr; // ��������� ���������� ��������� ��� nullptr

		// ������� ������ ���� � ��������������� ����� �� ����������
		if (head == nullptr || head->priority < priority) {
			temp->next = head;
			head = temp;
		}
		else {
			Node* current = head; // ������� ���� ��� ��������
			// ���� ���������� ����� ��� �������
			while (current->next != nullptr && current->next->priority >= priority) {
				current = current->next;
			}
			// ��������� ����� ����
			temp->next = current->next;
			current->next = temp;
		}
	}

	// �������� �������� � ��������� �����������
	int popHighestPriority() {
		if (head == nullptr) {
			printf("������� �����.\n");
			return -1;
		}
		Node* temp = head; // ��������� ���� ��� �������� ������
		head = head->next; // ����������� ������ �� ��������� ����
		int data = temp->data; // ���������� ������ �� ����
		delete temp; // �������� ���������� ����
		return data; // ������� ������
	}

	// �������� �������� � ���������� �����������
	int popLowestPriority() {
		if (head == nullptr) {
			printf("������� �����.\n");
			return -1;
		}
		Node* current = head; // ������� ���� ��� ��������
		Node* prev = nullptr; // ���������� ���� ��� ��������

		// �������� �� ���������� ����
		while (current->next != nullptr) {
			prev = current;
			current = current->next;
		}
		// �������� ���������� ����
		if (prev == nullptr) {
			head = nullptr;
		}
		else {
			prev->next = nullptr;
		}
		int data = current->data; // ���������� ������ �� ����
		delete current; // �������� ����
		return data; // ������� ������
	}
	// �������� �������� � �������� �����������
	int popSpecificPriority(int targetPriority) {
		Node* current = head; // ������� ���� ��� ��������
		Node* prev = nullptr; // ���������� ���� ��� ��������

		// �������� �� ���� ����� ��� ������ ���� � �������� �����������
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
		printf("������� � ����������� %d �� ������.\n", targetPriority);
		return -1;
	}

	// ����������� ���� ��������� �������
	void display() {
		Node* current = head; // ������� ���� ��� ��������
		while (current != nullptr) {
			printf("������: %d, ���������: %d\n", current->data, current->priority);
			current = current->next;
		}
	}
};


int main() {
	setlocale(LC_ALL, "RUS");
	PriorityQueue pq; // ������ ������� � �����������
	int choice; // ����� ������������
	int data; // ������ ��� ���������� ��� ��������
	int priority; // ��������� ��� ����������

	// �������� ����
	while (true) {
		printf("-------------------------------------------------\n");
		printf("1. �������� �������\n2. ������� ������� � ��������� �����������\n3. ������� ������� � ���������� �����������\n4. ������� ������� � ��������� �����������\n5 �������� �������\n6. �����\n");
		printf("�������� ��������: ");
		scanf("%d", &choice);

		// ��������� ������ ������������
		switch (choice) {
		case 1:
			printf("������� �����: ");
			scanf("%d", &data);
			printf("������� ���������: ");
			scanf("%d", &priority);
			pq.push(data, priority);
			break;
		case 2:
			data = pq.popHighestPriority();
			if (data != -1) {
				printf("��������� ������� � ��������� �����������: %d\n", data);
			}
			break;
		case 3:
			data = pq.popLowestPriority();
			if (data != -1) {
				printf("��������� ������� � ���������� �����������: %d\n", data);
			}
			break;
		case 4:
			printf("������� ���������: ");
			scanf("%d", &priority);
			data = pq.popSpecificPriority(priority);
			if (data != -1) {
				printf("��������� ������� � �������� �����������: %d\n", data);
			}
			break;
		case 5:
			pq.display();
			break;
		case 6:
			return 0;
		default:
			printf("�������� �����. ����������, ���������� �����.\n");
		}
	}

	return 0;
}