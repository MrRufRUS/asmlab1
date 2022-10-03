// asm1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <iostream>
//27 Вариант

#include <stdio.h>

void task1() {
    short int result;
    __asm {
        ; Первая часть
        ; (171 + (4 * 3 * 2)) / (((36 - 4) / 3) - 17)
        ; Числитель
        mov ax, 4
        mov bx, 3; ax = 4 * 3 = 12
        imul bx
        xor bx, bx
        mov bx, 2; ax = 12 * 2 = 24
        imul bx
        xor bx, bx
        add ax, 171; ax = 24 + 171 = 195
        mov dx, ax; dx = 195
        xor ax, ax; ax = 0
        ; Знаминатель
        mov ax, 36
        sub ax, 4; ax = 36 - 4 = 32
        mov bl, 3
        div bl; al = 32 / 3 = 10, ah = 2
        xor bx, bx
        xor ah, ah; ah = 0
        sub ax, 17; ax = 10 - 17 = -7;
        ; Деление
            mov bx, ax
            xor ax, ax
            mov ax, dx
            xor dx, dx
            idiv bx; ax = -27
            xor bx, bx
            mov cx, ax; cx = -27
            xor ax, ax
            ; Вторая часть
            ; (5 + 6) * 8 * (17 / (5 + 2))
            mov ax, 17
            mov bl, 5
            add bl, 2;  bl = 5 + 2 = 7

            idiv bl; al = 17 / 7 = 2, ah = 3
            xor ah, ah
            mov bx, 8
            imul bx; ax = 2 * 8

            mov bx, 5
            add bx, 6
            imul bx
            xor bx, bx

            ; Сложение первой и второй частей
            mov bx, cx
            add bx, ax
            mov ax, bx
            mov result, ax
            xor ax, ax
            xor bx, bx
            xor cx, cx
            xor dx, dx
    }

    //int a = (171 + (4 * 3 * 2)) / (((36 - 4) / 3) - 17) + (5 + 6) * 8 * (17 / (5 + 2));
    //std::cout << "Check in C++: " << a << std::endl;
    std::cout << "Check in ASM: " << result << std::endl;

}


void task2() {
    short int result;
    
    __asm {
        mov al, 1111111b
        mov bl, 1111101b
        and al, bl; обнуление 2 разряда
        sub al, 4; обнуление 3 разряда
        or al, 0001000b; обнуление 4 разряда
        xor al, 0001000b
        cbw
        mov result, ax
    }
    
    std::cout << "Check in ASM: " << result << std::endl;
}
  
int main()
{
    task1();
    task2();
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
