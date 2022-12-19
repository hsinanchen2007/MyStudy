### 解题思路
![截图.PNG](https://pic.leetcode-cn.com/c9a6da0c4fe96622f144617b1a44173e8b58733ba23073fc5476d3ed8cbf9597-%E6%88%AA%E5%9B%BE.PNG)


### 代码

```c
#define MAX 100

int IsNum(char *str)
{
    if (strlen(str) > 1 && str[0] == '0') {
        return 0;
    }
    if (atoi(str) >= 0 && atoi(str) <= 255) {
        return 1;
    }
    return 0;
}

void Dfs(char *s, char *temp, int index, int step, char **ret, int *returnSize)
{
    if (index - step >= strlen(s)) {
        return;
    }
    if (step == 3) {
        strncpy(temp + index, s + index - 3, strlen(s) + 3 - index);
        if (IsNum(s + index - 3) == 1) {
            strcpy(ret[*returnSize], temp);
            *returnSize += 1;
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        char *sub = (char*)malloc(sizeof(char) * (i + 1));
        memset(sub, '\0', i + 1);
        strncpy(sub, s + index - step, i);
        if (IsNum(sub) == 0) {
            continue;
            free(sub);
        }
        strncpy(temp + index, sub, strlen(sub));
        temp[index + strlen(sub)] = '.';
        Dfs(s, temp, index + strlen(sub) + 1, step + 1, ret, returnSize);
        memset(temp + index, '\0', strlen(s) + 4 - index);
        free(sub);
    }

}

char** restoreIpAddresses(char *s, int *returnSize)
{
    int len = strlen(s);
    *returnSize = 0;
    if (s == NULL || len == 0 || len > 12) {
        return NULL;
    }
    char **vec = (char**)malloc(sizeof(char*) * MAX);
    char *tmp = (char*)malloc(sizeof(char) * MAX * (len + 4));
    memset(tmp, '\0', MAX * (len + 4));
    for (int m = 0; m < MAX; ++m) {
        vec[m] = tmp + m * sizeof(char) * (len + 4);
    }
    char *temp = (char*)malloc(sizeof(char) * (len + 4));
    memset(temp, '\0', len + 4);
    Dfs(s, temp, 0, 0, vec, returnSize);
    return vec;
}
```