```
char *longestPalindrome(char *str) {
    char *result = (char *) malloc(sizeof(char) * 1002);
    if (strlen(str) == 0) {
        result[0] = '\0';
        return result;
    }
    
    int maxLength = 0;
    for (int i = 0; i < strlen(str); i++) {
        int len = -1;
        for (int j = i, k = i; j >= 0 && k < strlen(str); j--, k++) {
            if (str[j] == str[k]) {
                len += 2;

                if (j == 0 || k == strlen(str) - 1) {
                    if (maxLength < len) {
                        maxLength = len;
                        int fig = 0;
                        for (int first = j; first <= k; first++) {
                            result[fig++] = str[first];
                        }
                        result[fig++] = '\0';
                    }
                    break;
                }
            } else {
                if (maxLength < len) {
                    maxLength = len;
                    int fig = 0;
                    for (int first = j + 1; first <= k - 1; first++) {
                        result[fig++] = str[first];
                    }
                    result[fig++] = '\0';
                }
                break;
            }
        }
    }

    for (int i = 0; i < strlen(str) - 1; i++) {
        int len = 0;
        for (int j = i, k = i + 1; j >= 0 && k < strlen(str); j--, k++) {
            if (str[j] == str[k]) {
                len += 2;

                if (j == 0 || k == strlen(str) - 1) {
                    if (maxLength < len) {
                        maxLength = len;
                        int fig = 0;
                        for (int first = j; first <= k; first++) {
                            result[fig++] = str[first];
                        }
                        result[fig++] = '\0';
                    }
                    break;
                }
            } else {
                if (j == k - 1) {
                    len = 0;
                }
                if (maxLength < len) {
                    maxLength = len;
                    int fig = 0;
                    for (int first = j + 1; first <= k - 1; first++) {
                        result[fig++] = str[first];
                    }
                    result[fig++] = '\0';
                }
                break;
            }
        }
    }

    return result;
}
```
