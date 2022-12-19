### 解题思路
比较字符串 a + b  和 b + a的大小

### 代码

```c
#define MAX_LEN 1000
#define CHARS_LEN 100

int intCmp(const void *a, const void *b)
{
    int tmpA = *((int *)a);
    int tmpB = *((int *)b);
    int index;
    char str1[CHARS_LEN] = { 0 };
    char str2[CHARS_LEN] = { 0 };
    char tmp[CHARS_LEN] = { 0 };

    sprintf(str1, "%d", tmpA);
    strcpy(tmp, str1);
    sprintf(str2, "%d", tmpB);
    strncat(str1, str2, strlen(str2));
    strncat(str2, tmp, strlen(tmp));

    return strcmp(str1, str2);
}

char *minNumber(int *nums, int numsSize)
{
    if ((nums == NULL) || (numsSize == 0)) {
        return NULL;
    }

    char *ans = (char *)malloc(sizeof(char) * MAX_LEN);
    char tmp[CHARS_LEN];
    if (ans == NULL) {
        return NULL;
    }

    memset(ans, 0x0, sizeof(char) * MAX_LEN);
    qsort(nums, numsSize, sizeof(int), intCmp);

    for (int i = 0; i < numsSize; i++) {
        memset(tmp, 0x0, sizeof(char) * CHARS_LEN);
        sprintf(tmp, "%d", nums[i]);
        strncat(ans, tmp, strlen(tmp));
    }

    return ans;
}
```