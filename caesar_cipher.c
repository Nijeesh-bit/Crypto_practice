#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plain[100], cipher[100];  // Increased buffer size for larger input
    int key, i, length;

    // Get the plain text
    printf("\nEnter the plain text: ");
    scanf("%s", plain);

    // Get the key value
    printf("\nEnter the key value: ");
    scanf("%d", &key);

    // Display the plain text
    printf("\n\n\tPLAIN TEXT: %s", plain);

    // Encrypt the plain text
    printf("\n\n\tENCRYPTED TEXT: ");
    for (i = 0, length = strlen(plain); i < length; i++) {
        cipher[i] = plain[i] + key;

        // Handle uppercase letters
        if (isupper(plain[i]) && (cipher[i] > 'Z')) {
            cipher[i] = cipher[i] - 26;
        }
        // Handle lowercase letters
        if (islower(plain[i]) && (cipher[i] > 'z')) {
            cipher[i] = cipher[i] - 26;
        }
        printf("%c", cipher[i]);
    }

    // Decrypt the cipher text
    printf("\n\n\tAFTER DECRYPTION: ");
    for (i = 0; i < length; i++) {
        plain[i] = cipher[i] - key;

        // Handle uppercase letters
        if (isupper(cipher[i]) && (plain[i] < 'A')) {
            plain[i] = plain[i] + 26;
        }
        // Handle lowercase letters
        if (islower(cipher[i]) && (plain[i] < 'a')) {
            plain[i] = plain[i] + 26;
        }
        printf("%c", plain[i]);
    }

    printf("\n");
    getchar(); // Wait for a key press (replaces getch)
    return 0;
}
