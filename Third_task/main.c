#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        // Вивести рекомендацію щодо використання програми
        printf("Використання: %s <ім'я_змінної> <значення_змінної>\n", argv[0]);
        return 1;
    }

    const char *variable_name = argv[1];
    const char *variable_value = argv[2];

    // Встановлюємо змінну оточення
    if (setenv(variable_name, variable_value, 1) == 0) {
        // Зчитуємо змінну оточення та виводимо її значення
        const char *env_value = getenv(variable_name);
        if (env_value != NULL) {
            printf("Змінна оточення '%s' має значення '%s'\n", variable_name, env_value);
        } else {
            printf("Змінна оточення '%s' не знайдена після встановлення\n", variable_name);
        }
    } else {
        printf("Помилка встановлення змінної оточення\n");
        return 1;
    }

    return 0;
}
