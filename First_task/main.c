#include <stdio.h>
#include <stdlib.h>

int main() {
    // Отримуємо змінну оточення "environ" з бібліотеки "stdlib.h"
    extern char** environ;

    // Ітеруємося через всі змінні оточення та виводимо їх
    for (char** env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}
