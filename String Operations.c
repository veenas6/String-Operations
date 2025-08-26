#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string in-place
void reverseString(char str[]) {
    int len = strlen(str);
    int i = 0, j = len - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to check if a string is palindrome (ignoring case and spaces)
int isPalindrome(const char str[]) {
    int left = 0, right = strlen(str) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;

        if (tolower(str[left]) != tolower(str[right]))
            return 0; // Not palindrome

        left++;
        right--;
    }
    return 1; // Palindrome
}

// Function to concatenate str2 to the end of str1 (assuming str1 has enough space)
void concatenate(char str1[], const char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    for (int i = 0; i <= len2; i++) {  // including null terminator
        str1[len1 + i] = str2[i];
    }
}

// Function to count words in a string
int wordCount(const char str[]) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            if (inWord) {
                count++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }

    // If string ends with a word (not space)
    if (inWord) count++;

    return count;
}

int main() {
    char str1[100], str2[100];

    // Reverse
    printf("Enter a string to reverse: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;  // remove newline
    reverseString(str1);
    printf("Reversed string: %s\n", str1);

    // Palindrome check
    printf("Enter a string to check palindrome: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    if (isPalindrome(str1))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    // Concatenation
    printf("Enter first string for concatenation: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter second string for concatenation: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    concatenate(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // Word count
    printf("Enter a string to count words: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    printf("Word count: %d\n", wordCount(str1));

    return 0;
}