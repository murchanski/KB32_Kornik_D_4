#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    char hostname[256];
    struct utsname uts;

    // Отримуємо ім'я хоста (мережі)
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Ім'я комп'ютера (мережі): %s\n", hostname);
    } else {
        perror("Помилка отримання імені мережі");
    }

    // Отримуємо додаткову інформацію про систему
    if (uname(&uts) == 0) {
        printf("Ім'я операційної системи: %s\n", uts.sysname);
        printf("Версія операційної системи: %s\n", uts.release);
        printf("Версія ядра: %s\n", uts.version);
        printf("Архітектура: %s\n", uts.machine);
    } else {
        perror("Помилка отримання інформації про систему");
    }

    return 0;
}
