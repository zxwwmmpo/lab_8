#include <stdio.h>
#include <windows.h>

void aboutMe() {
	printf("�����\n");
	printf("��������\n");
	printf("��������\n");
	printf("\n");
	printf("������: ����-13\n");
	printf("����: 06.10.2023\n");
	printf("�������: ������ ����������������\n");
	printf("������������ ������ �8\n");
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	aboutMe();
}