#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // Якщо не вказано ім'я змінної оточення, виводимо інформацію про використання програми
        printf("Usage: %s <environment_variable_name>\n", argv[0]);
        return 1;
    }

    // Отримуємо ім'я змінної оточення з аргументів командного рядка
    const char *env_var_name = argv[1];

    // Використовуємо getenv для отримання значення змінної оточення
    char *env_var_value = getenv(env_var_name);

    if (env_var_value != NULL) {
        // Якщо значення змінної оточення існує, виводимо його
        printf("%s=%s\n", env_var_name, env_var_value);
    } else {
        // Якщо змінна оточення не існує, виводимо відповідне повідомлення
        printf("Environment variable '%s' is not set.\n", env_var_name);
    }

    return 0;
}
