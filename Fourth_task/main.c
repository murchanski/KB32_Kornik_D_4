#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // Якщо не вказано жодної змінної, очистимо всі змінні оточення
        if (clearenv() != 0) {
            perror("Помилка очищення оточення");
            return 1;
        }
    } else {
        // Видаляємо вказану змінну оточення
        for (int i = 1; i < argc; i++) {
            if (unsetenv(argv[i]) != 0) {
                perror("Помилка видалення змінної з оточення");
                return 1;
            }
        }
    }

    // Виводимо поточне оточення
    extern char **environ;
    for (char **env = environ; *env; env++) {
        printf("%s\n", *env);
    }

    return 0;
}
