#include "pi.h"

// Считаем число Пи через ряд Лейбница с заданной точностью
double calculate_pi(double precision)
{
    // Ряд Лейбница сходится к pi/4, поэтому умножаем на 4

    double sum = 4; // Сумма членов ряда

    double prev = 0; // Предыдущая сумма

    double delta = sum - prev; // Разница между двумя шагами

    /* Вспомогательные переменные для ускорения счёта */
    double _odd = 1; // Нечётные числа в ряде
    double _minus_1_pow_n = 1; // (-1)^n

    // precision / 8 так как нам нужна большая точность из-за умножения (/4) и потерь отбрасывания (/2)
    while (delta > (precision / 8))
    {
        _minus_1_pow_n *= -1; // Получаем нужную степень -1
        _odd += 2; // Следующее нечётное число

        prev = sum; // Сохраняем старое значение

        sum += 4 * _minus_1_pow_n / _odd; // Добавляем новый член

        delta = sum - prev; // Новая разница

        // |delta|
        if (delta < 0) { delta *= -1; }
    }

    return sum;
}