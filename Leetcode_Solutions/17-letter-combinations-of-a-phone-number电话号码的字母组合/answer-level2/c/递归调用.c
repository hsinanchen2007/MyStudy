### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/47befeba95e7b1ff1f339e07bd8d93ded85e8227d0c7c17c883c62754d43b10d-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct letter {
    int n;
    char c[4];
};

const static struct letter g_map[8] = {
    {3, {'a', 'b', 'c', '\0'}},
    {3, {'d', 'e', 'f', '\0'}},
    {3, {'g', 'h', 'i', '\0'}},
    {3, {'j', 'k', 'l', '\0'}},
    {3, {'m', 'n', 'o', '\0'}},
    {4, {'p', 'q', 'r', 's'}},
    {3, {'t', 'u', 'v', '\0'}},
    {4, {'w', 'x', 'y', 'z'}},
};

static int GetResCnt(char *digits, int len)
{
    int cnt = 1;
    for (int i = 0; i < len; i++) {
        cnt *= g_map[digits[i] - '2'].n;
    }
    return (cnt == 1 ? 0 : cnt);
}

static void GetResult(const char *digits, char *buff, int pos, char **res, int *index)
{
    if (*digits == '\0') {
        strcpy(res[*index], buff);
        *index = *index + 1;
        return;
    }

    const struct letter *ptr = &g_map[*digits - '2'];
    for (int i = 0; i < ptr->n; i++) {
        buff[pos] = ptr->c[i];
        GetResult(digits + 1, buff, pos + 1, res, index);
    }
}

char **letterCombinations(char *digits, int *returnSize)
{
    int len = strlen(digits);
    *returnSize = GetResCnt(digits, len);
    if (*returnSize == 0) {
        return NULL;
    }

    char **res = NULL;
    res = (char **)malloc(*returnSize * sizeof(char *));
    for (int i = 0; i < *returnSize; i++) {
        res[i] = malloc(len + 1);
        memset(res[i], 0, len + 1);
    }

    char buf[len + 1];
    memset(buf, 0, len + 1);
    int index = 0;
    GetResult(digits, buf, 0, res, &index);
    return res;
}
```