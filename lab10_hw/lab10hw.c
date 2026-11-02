#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

// ввод радиуса вписанной окружности
int get_r()
{
	int radius;

	printf("Введите радиус вписанной окружности: ");
	scanf("%d", &radius);
	while (radius <= 0)
	{
		printf("Радиус должен быть больше 0, введите ещё раз: ");
		scanf("%d", &radius);
	}
	return radius;
}

// площадь квадрата, сторона = 2 * радиус
float area_square(float radius)
{
	float storona = 2 * radius;
	float ploshad = storona * storona;
	return ploshad;
}

// определение фигуры
void print_definition()
{
	printf("\nКвадрат - это правильный четырёхугольник, у него все стороны равны и все углы прямые.\n");
	printf("Сторона квадрата равна 2r, где r - радиус вписанной окружности.\n");
}

// рисование квадрата (повёрнутого на 45 градусов) символом
void draw_square(int radius, char simvol)
{
	int bolshoj_radius = (int)round(radius * sqrt(2.0));
	int stroka, stolbec;

	printf("\n");
	for (stroka = -bolshoj_radius; stroka <= bolshoj_radius; stroka++)
	{
		for (stolbec = -bolshoj_radius; stolbec <= bolshoj_radius; stolbec++)
		{
			if (abs(stolbec) + abs(stroka) <= bolshoj_radius)
				printf("%c ", simvol);
			else
				printf("  ");
		}
		printf("\n");
	}
}

// разница площадей двух квадратов
int compare_square(int radius1, int radius2)
{
	int raznica = (int)(area_square(radius1) - area_square(radius2));
	return raznica;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int radius, radius2, vybor, raznica;
	char simvol;

	printf("Введите символ для рисования: ");
	scanf(" %c", &simvol);
	radius = get_r();

	do
	{
		printf("\nМеню:\n");
		printf("1. Рассчитать площадь\n");
		printf("2. Вывести определение фигуры\n");
		printf("3. Нарисовать фигуру\n");
		printf("4. Сравнить с другим квадратом по площади\n");
		printf("0. Выход\n");
		printf("Ваш выбор: ");
		scanf("%d", &vybor);

		switch (vybor)
		{
		case 1:
			printf("Площадь квадрата = %.2f\n", area_square(radius));
			break;
		case 2:
			print_definition();
			break;
		case 3:
			draw_square(radius, simvol);
			break;
		case 4:
			printf("Второй квадрат. ");
			radius2 = get_r();
			raznica = compare_square(radius, radius2);
			if (raznica > 0)
				printf("Первый квадрат больше на %d\n", raznica);
			else if (raznica < 0)
				printf("Второй квадрат больше на %d\n", -raznica);
			else
				printf("Площади равны\n");
			break;
		case 0:
			break;
		default:
			printf("Неверный выбор\n");
		}
	} while (vybor != 0);

	system("pause");
	return 0;
}