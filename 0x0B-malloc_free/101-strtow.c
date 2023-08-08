#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

char **strtow(char *str) {
    if (str == NULL || *str == '\0') {
        return NULL; // Return NULL for invalid input
    }

    // Count the number of words first
    int word_count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            word_count++;
            while (str[i] != ' ' && str[i] != '\0') {
                i++;
            }
        }
    }

    // Allocate memory for an array of strings (words) and NULL terminator
    char **words = (char **)malloc((word_count + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }

    int word_index = 0;
    int word_start = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            word_start = i;
            while (str[i] != ' ' && str[i] != '\0') {
                i++;
            }
            
            int word_length = i - word_start;
            words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
            if (words[word_index] == NULL) {
                // Free memory allocated so far and return NULL if memory allocation fails
                for (int j = 0; j < word_index; j++) {
                    free(words[j]);
                }
                free(words);
                return NULL;
            }
            
            strncpy(words[word_index], str + word_start, word_length);
            words[word_index][word_length] = '\0';
            word_index++;
        }
    }
    
    words[word_count] = NULL; // Set the last element to NULL
    
    return words;
}

int main() {
    char str[] = "This is a test string";
    char **words = strtow(str);

    if (words != NULL) {
        for (int i = 0; words[i] != NULL; i++) {
            printf("Word %d: %s\n", i, words[i]);
            free(words[i]); // Free memory for each word
        }
        free(words); // Free memory for the array of words
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
