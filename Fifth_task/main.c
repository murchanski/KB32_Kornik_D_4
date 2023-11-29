#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    // Отримати інформацію про користувача за UID
    uid_t target_uid = getuid(); // Отримуємо UID поточного користувача
    struct passwd *user_info_uid = getpwuid(target_uid);

    if (user_info_uid != NULL) {
        printf("Інформація про користувача за UID %d:\n", target_uid);
        printf("Ім'я користувача: %s\n", user_info_uid->pw_name);
        printf("Повне ім'я користувача: %s\n", user_info_uid->pw_gecos);
        printf("Домашня директорія: %s\n", user_info_uid->pw_dir);
    } else {
        perror("Помилка отримання інформації за UID");
    }

    // Отримати інформацію про користувача "root" за його реєстраційним ім'ям
    const char *target_username = "root";
    struct passwd *user_info_name = getpwnam(target_username);

    if (user_info_name != NULL) {
        printf("\nІнформація про користувача з ім'ям '%s':\n", target_username);
        printf("UID користувача: %d\n", user_info_name->pw_uid);
        printf("Повне ім'я користувача: %s\n", user_info_name->pw_gecos);
        printf("Домашня директорія: %s\n", user_info_name->pw_dir);
    } else {
        perror("Помилка отримання інформації за ім'ям користувача");
    }

    return 0;
}
