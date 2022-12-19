C语言暴力加速优化
![image.png](https://pic.leetcode-cn.com/265302dac8f799467cdbc5d61aa33b6a12e6ef3642b017b1bc37204ce46a04a8-image.png)

```c
#define MAX_SIZE 1005
int g_arr[MAX_SIZE];
int g_index;

int Cmp(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

bool canCoverString(char* str1, char* str2, int len)
{
    do {
        str1 = strstr(str1, str2);
        if (str1 == NULL) {
            return false;
        }

        if (strcmp(str1, str2) == 0) {
            return true;
        } 

        str1 += len;
    } while (true);

    return false;
}

char * gcdOfStrings(char * str1, char * str2){
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }
    char* longStr = str1;
    char* shortStr = str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 < len2) {
        longStr = str2;
        shortStr = str1;
        len1 ^= len2;
        len2 ^= len1;
        len1 ^= len2;
    }

    char* ret = (char*)malloc(sizeof(char) * (len2 + 1));
    ret[0] = '\0';
    if (!strstr(longStr, shortStr)) {
        return ret;
    }
    strcpy(ret, shortStr);

    int tmp, i;
    g_index = 0;
    for (i = 1; i * i <= len2; ++i) {
        if (len2 % i == 0) {
            g_arr[g_index++] = i;
            tmp = len2 / i;
            if (tmp != i) {
                g_arr[g_index++] = tmp;
            }
        }
    }
    qsort(g_arr, g_index, sizeof(int), Cmp);
    for (i = 0; i < g_index; ++i) {
        ret[g_arr[i]] = '\0';
        if (canCoverString(shortStr, ret, g_arr[i]) && canCoverString(longStr, ret, g_arr[i])) {
            break;
        }
    }

    if (i == g_index) {
        ret[0] = '\0';
    }
    return ret;
}
```