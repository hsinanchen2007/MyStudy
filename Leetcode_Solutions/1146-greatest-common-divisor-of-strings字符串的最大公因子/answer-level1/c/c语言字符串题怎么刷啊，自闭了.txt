### 解题思路

### 代码

```c
#define MAX_LEN 10000
#define MIN(x, y) x < y ? x : y

void strSub(char *dest, char *str, int i, int j)
{
    int index = 0;
    for (int k = i; k < j; k++) {
        dest[index++] = str[k];
    }

    dest[index] = '\0';
    return;
}

int check(char *str1, char *str2)
{
    int lenx = strlen(str1) / strlen(str2);
    int len = strlen(str1);
    char *tmp = malloc(sizeof(char) * MAX_LEN);
    memset(tmp, 0x0, sizeof(char)  * MAX_LEN);

    for (int i = 0; i < lenx; i++) {
        strncat(tmp, str2, strlen(str2));
        // printf("%s\n", tmp);
    }
    // printf("%d\n", strcmp(str1, tmp));
    return strcmp(str1, tmp);
}

char * gcdOfStrings(char * str1, char * str2)
{
    if ((str1 == NULL) || (str2 == NULL)) {
        return "";
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min = MIN(len1, len2);
    char *tmp = malloc(sizeof(char) * MAX_LEN);
    memset(tmp, 0x0, sizeof(char) * MAX_LEN);

    for (int i = min; i >= 1; i--) {
        if ((len1 % i == 0) && (len2 % i == 0)) {
             strSub(tmp, str1, 0, i);
             if (check(str1, tmp) == 0 && check(str2, tmp) == 0) {
                 return tmp;
             }
        }
    }

    return "";
}


```