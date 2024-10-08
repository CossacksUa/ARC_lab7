#include <iostream>  // для використання стандартного виведення

int main()  // початок програми мовою C++
{
    long n = 0;     // змінна для n
    long An = 0;    // змінна для збереження значення An
    long sum = 0;   // змінна для збереження суми

    _asm {  // початок асемблерної вставки
    m1:
        inc n                   // збільшення n
            mov EAX, n              // завантаження n в EAX
            imul EAX, EAX           // EAX = n^2
            imul EAX, 3             // EAX = 3 * n^2
            mov EBX, n              // завантаження n в EBX
            imul EBX, 2             // EBX = 2 * n
            sub EAX, EBX            // EAX = 3 * n^2 - 2 * n
            add EAX, 12             // EAX = 3 * n^2 - 2 * n + 12

            mov EBX, n              // завантаження n в EBX
            add EBX, 1              // EBX = n + 1
            cdq                     // розширення знаку EAX для ділення
            idiv EBX                // EAX = (3 * n^2 - 2 * n + 12) / (n + 1)

            mov An, EAX             // зберігання значення An
            add sum, EAX            // додавання An до суми

            cmp sum, 1500           // порівняння суми з 1500
            jle m1                  // перехід, якщо sum <= 1500
    }  // закінчення асемблерної вставки

    std::cout << "N: " << n << std::endl;  // виведення результату
    std::cout << "Сума прогресії: " << sum << std::endl;  // виведення суми
    return 0;
}
