#include "pi.h"

#define PI 3.14159265358979323846

#define TESTS_NUM 8

// 0 -> всё верно; 1xx -> ошибка в тесте xx
int test_pi(double tests[TESTS_NUM][2])
{
    for (unsigned i = 0; i < TESTS_NUM; ++i)
    {
        double expected = tests[i][0];
        double precision = tests[i][1];

        double pi = calculate_pi(precision);
        double delta = expected - pi; // Отклонение от ожидаемого результата

        // |delta|
        if (delta < 0) { delta *= -1;}

        if (delta > precision) { return 100 + i; }
    }
    return 0;
}

int main()
{
    // Значения полученные на калькуляторе
    double tests[TESTS_NUM][2] = {
        { 3,         1         },
        { 3.1,       0.1       },
        { 3.14,      0.01      },
        { 3.141,     0.001     },
        { 3.1415,    0.0001    },
        { 3.14159,   0.00001   },
        { 3.141592,  0.000001  },
        { 3.1415926, 0.0000001 }
    };

    double wrong_test[TESTS_NUM][2] = {
        { 3,         1         },
        { 3.1,       0.1       },
        { 3.14,      0.01      },
        { 3.141,     0.001     },
        { 3.1415,    0.0001    },
        { 3.14200,   0.00001   }, // Ошибка тут
        { 3.141592,  0.000001  },
        { 3.1415926, 0.0000001 }
    };

    return test_pi(tests);
}