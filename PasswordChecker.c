#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8

// Function to check if the password is strong
int isStrongPassword(const char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int length = strlen(password);

    if (length < MIN_LENGTH) {
        return 0;  // Too short
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else if (strchr("!@#$%^&*()-+", password[i])) hasSpecial = 1;
    }

    // Password is strong if all conditions are met
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);  // Caution: scanf doesn't handle spaces

    if (isStrongPassword(password)) {
        printf("Strong password!\n");
    } else {
        printf("Weak password. Must be at least 8 characters long and include uppercase, lowercase, digit, and special character.\n");
    }

    return 0;
}
