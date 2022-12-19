### 解题思路
此处撰写解题思路

### 代码

```c
char * longestPalindrome(char * s){
    if (!s) {
        return NULL;
    }

    int length = strlen(s);
    if (length <= 1) {
        return s;
    }

    int middleIdx = 0, maxOffset = 0, maxLength = 0, flag = 0;
    for (int i = 1; i < length; i++) {
        if (s[i] == s[i - 1]) {
            int curLength = 2;
            int offset = 1;
            while (i + offset < length && i - 1 - offset >= 0) {
                if (s[i + offset] != s[i - 1 - offset]) {
                    break;
                }
                curLength += 2;
                offset++;
            }
            if (maxLength < curLength) {
                maxLength = curLength;
                maxOffset = offset;
                middleIdx = i;
                flag = 1;
            }
        }
        if (i > 1 && s[i] == s[i - 2]) {
            int curLength = 3;
            int offset = 1;
            while (i + offset < length && i - 2 - offset >= 0) {
                if (s[i + offset] != s[i - 2 - offset]) {
                    break;
                }
                curLength += 2;
                offset++;
            }
            if (maxLength < curLength) {
                maxLength = curLength;
                maxOffset = offset;
                middleIdx = i;
                flag = 0;
            }
        }
    }
    if (middleIdx == 0 || maxOffset == 0) {
        char* result = malloc(2 * sizeof(char));
        result[0] = s[0];
        result[1] = '\0';
        return result;
    }

    char* result = malloc((maxLength + 1) * sizeof(char));
    if (flag) {
        for (int i = middleIdx - maxOffset, j = 0; i < middleIdx + maxOffset; i++, j++) {
            result[j] = s[i];
        }
    } else {
        for (int i = middleIdx - 1 - maxOffset, j = 0; i < middleIdx + maxOffset; i++, j++) {
            result[j] = s[i];
        }
    }
    result[maxLength] = '\0';
    return result;
}
```