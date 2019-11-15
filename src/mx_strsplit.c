#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }
    int k = mx_count_words(s, c);
    char **arr = NULL;
    arr = (char **) malloc(sizeof(char* ) * (k + 1));
    for (int i = 0; i < k; i++) {
        int len_word = 0;
        char *count = (char *) s;
        while (len_word == 0 && *count != '\0') {
            count = (char *) s;
            if (*count != c) {
                for(; *(count + len_word) != c && *(count + len_word) != '\0'; len_word++);
            }
            else {
                s++;
            }
        }
        arr[i] = mx_strnew(len_word);
        arr[i] = mx_strncpy(arr[i], s, len_word);
        s += len_word;
    }
    arr[k] = NULL;
    return arr;
}
