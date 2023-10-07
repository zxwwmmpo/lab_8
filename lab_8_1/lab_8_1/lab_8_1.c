#include <stdio.h>
#include <windows.h>

void aboutMe() {
	printf("Кобин\n");
	printf("Владимир\n");
	printf("Олегович\n");
	printf("\n");
	printf("Группа: ПИбд-13\n");
	printf("Дата: 06.10.2023\n");
	printf("Предмет: Основы программирования\n");
	printf("Лабароторная работа №8\n");
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	aboutMe();
}