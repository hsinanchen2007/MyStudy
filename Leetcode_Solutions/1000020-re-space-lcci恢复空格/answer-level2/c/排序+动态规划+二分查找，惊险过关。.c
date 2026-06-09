c语言
排序+动态规划+二分查找，惊险过关。
![image.png](https://pic.leetcode-cn.com/c256d6002b8c1c6a192a416bfed3c79703e7d22452689609946ec2e6b82240b7-image.png)


```
#define MIN(a, b) (a) < (b) ? (a) : (b)

int Cmp(void *a, void *b)
{
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;
    return strcmp(s1, s2);
}

bool IsWordExist(char** dictionary, int dictionarySize, char *str, int len)
{
    int left = 0;
    int right = dictionarySize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int ret = strncmp(dictionary[mid], str, len);
        if (ret == 0) {
            int ret2 = strlen(dictionary[mid]);
            if (ret2 == len) {
                return true;
            } else if (ret2 > len) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (ret > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int respace(char** dictionary, int dictionarySize, char* sentence)
{
    qsort(dictionary, dictionarySize, sizeof(char *), Cmp);
    int len = strlen(sentence);
    int *dp = (int *)malloc(sizeof(int) * (len + 1));
    dp[0] = 1;
    for (int i = 0; i <= len; i++) {
        if (i > 0) {
            dp[i] = dp[i - 1] + 1;
        }
        for (int j = 0; j <= i; j++) {
            if (IsWordExist(dictionary, dictionarySize, sentence + j, i - j + 1)) {
                if (j == 0) {
                    dp[i] = 0;
                } else {
                    dp[i] = MIN(dp[i], dp[j - 1]);
                }
            }
        }
    }
    int ans = dp[len] - 1;
    free(dp);
    return ans;
}
```

