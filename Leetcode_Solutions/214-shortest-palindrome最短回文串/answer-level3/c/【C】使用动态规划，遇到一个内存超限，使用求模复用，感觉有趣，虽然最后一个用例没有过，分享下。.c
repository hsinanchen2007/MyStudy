1.使用dp https://leetcode-cn.com/problems/longest-palindromic-substring
2.在1的基础上约束必须包含首字母
3.当字符串很大的时候，用例约40004长度，矩阵40004×40004×sizeof(bool)内存超限了，使用求模复用


```
const int MIN_ROW_NUM = 2;

bool ** mallocDpArray(size_t length)
{
    /* 由于内存的原因，这里修改为两行，内存复用，修改为2 */
    bool **dp = (bool**)malloc(sizeof(bool*) * MIN_ROW_NUM);
    if (dp == NULL) {
        return NULL;
    }
    memset(dp, 0, sizeof(bool*) * MIN_ROW_NUM/*sizeof(bool*) * length*/);
    for (int i = 0; i < MIN_ROW_NUM/*length*/; ++i) {
        bool *result = (bool*)malloc(sizeof(bool) * length);
        if (result == NULL) {
            free(dp);
            dp = NULL;
            return NULL;
        }
        memset(result, 0, sizeof(bool) * length);
        dp[i] = result;
    }
    return dp;
}

void freeDpArray(size_t length, bool **dp)
{
    for (int i = 0; i < MIN_ROW_NUM/*length*/; ++i) {
        if (dp[i] != NULL) {
            free(dp[i]);
            dp[i] = NULL;
        }
    }
    free(dp);
    dp = NULL;
}

bool includeFirstChar(int j)
{
    return (j == 0);
}

char * shortestPalindrome(char * s)
{
    if (s == NULL) {
        return NULL;
    }
    size_t length = strlen(s);
    if (length == 0) {
        return "";
    }
    if (length == 1) {
        return s;
    }

    bool **dp = mallocDpArray(length);
    if (dp == NULL) {
        return NULL;
    }

    char *maxPalindrome = NULL;
    int maxLength = 0;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (s[i] == s[j]) {
                if ((j + 1) <= (i - 1)) {
                    dp[i % MIN_ROW_NUM][j] = dp[(i - 1) % MIN_ROW_NUM][j + 1]; // 先行后列,则是下三角
                } else {
                    dp[i % MIN_ROW_NUM][j] = true;
                }
                if (dp[i % MIN_ROW_NUM][j]) {
                    int currentLenght = i - j + 1;
                    if (maxLength < currentLenght && includeFirstChar(j)) {
                        maxLength = currentLenght;
                        maxPalindrome = &s[j];
                        printf("%d (%d,%d),%s\r\n", maxLength, i, j, maxPalindrome);
                    }
                }
            } else {
                dp[i % MIN_ROW_NUM][j] = false;
            }
        }
    }

    freeDpArray(length, dp);
    dp = NULL;

    if (maxPalindrome == NULL) {
        return NULL;
    }

    int delta = length - maxLength;
    int outputSize = 2 * delta + maxLength + 1;
    char *output = (char*)malloc(sizeof(char) * outputSize);
    if (output == NULL) {
        return NULL;
    }
    memset(output, 0, outputSize);

    for (int i = 0; i < length - maxLength; ++i) {
        output[i] = s[length - 1 - i];
    }
    memcpy(output + delta, s, length);
    return output;
}
```
