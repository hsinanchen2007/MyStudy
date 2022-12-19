### 解题思路
> 核心在于高效找到最短的包含T中所有字符的子串; 划窗计算,只针对差异的单个字符进行计算避免重复计算,效率很高;

- 注意事项: 不存在要返回空字符串, C中要申请一个专门放``` '\0' ``` 的内存;比较蛋疼; 没有直接返回原字符串某个匹配上字符的地址,而是申请了一个新内存放结果,操作起来各种麻烦事情; C语言在于折腾; 特别注意如果是在原字符串上找到子串, 结果拷贝到申请的内存时(为了方便调用者释放),拷贝时候要用 ```strncpy``` , 而不是直接用```strcpy```, 后者会一直拷贝到遇到结束符; 在我们不行原字符串的基础上, 匹配的可能是中间部分, 会导致拷贝时越界访问呢.

### 代码

```c [group1-C双下标]
#define MAX_CHAR_TYPES 128

void UpdateCounters(int sCounters[MAX_CHAR_TYPES], char *s, int maxLen)
{
    int i = 0;
    while (i < maxLen && *s != '\0') {
        sCounters[*s] += 1;
        i++;
        s++;
    }
}

int GetTypesNum(int tCounters[MAX_CHAR_TYPES])
{
    int count = 0;
    for (int i = 0; i < MAX_CHAR_TYPES; i++) {
        if (tCounters[i]) {
            count += 1;
        }
    }
    return count;
}

char *GetMinWindowMatchTargetCounters(int tCounters[MAX_CHAR_TYPES], char *s, char *t, int *minLen, int tLen)
{
    int sLen = strlen(s);
    if (sLen < tLen) {
        return NULL;
    }

    int sCounters[MAX_CHAR_TYPES] = {0};
    int start = 0;
    int end = 0;
    int bestStart = 0;
    int currLen = 0;
    int need = GetTypesNum(tCounters);
    int matched = 0;
    char c;
    int min = INT_MAX;

    while (end < sLen) {
        c = s[end];
        if (tCounters[c]) {
            sCounters[c] += 1;
            if (sCounters[c] == tCounters[c]) {
                matched += 1;
            }
        }
        end += 1;

        while (matched == need) {
            currLen = end - start;
            if (currLen < min) {
                min = currLen;
                bestStart = start;
            }
            c = s[start];
            if (tCounters[c]) {
                sCounters[c] -= 1;
                if (sCounters[c] < tCounters[c]) {
                    matched -= 1;
                }
            }
            start += 1;
        }
    }
    if (min == INT_MAX) {
        return NULL;
    }
    *minLen = min;
    return s + bestStart;
}

char *minWindow(char *s, char *t)
{
    if (s == NULL || t == NULL) {
        return NULL;
    }

    int tCounters[MAX_CHAR_TYPES] = {0};
    int tLen = strlen(t);
    UpdateCounters(tCounters, t, tLen);

    int minLen = 0;
    char *start = GetMinWindowMatchTargetCounters(tCounters, s, t, &minLen, tLen);
    if (start == NULL) {
        // 未找到匹配的, 要返回空字符串, 不是空指针;
        minLen = 0;
    }
    char *result = (char *)malloc(minLen + 1);
    if (result == NULL) {
        return NULL; // 这个只能返回空指针!!!
    }
    if (start != NULL) {
        strncpy(result, start, minLen);
    }
    result[minLen] = '\0';
    return result;
}
```

``` python3 [group1-Python3]
from collections import Counter, defaultdict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        s_counter = defaultdict(int)
        t_counter = Counter(t)
        if len(s) < len(t):
            return ""

        left, right = 0, 0
        matched = 0
        needed = len(t_counter)
        min_win_len = float("inf")
        best_start = 0
        while right < len(s):
            c = s[right]
            if c in t_counter:
                s_counter[c] += 1
                if s_counter[c] == t_counter[c]:
                    matched += 1
            right += 1

            # 移动left直到不能匹配
            while matched == needed:
                c = s[left]
                if min_win_len > right - left:
                    min_win_len = right - left
                    best_start = left
                if c in t_counter:
                    s_counter[c] -= 1
                    if s_counter[c] < t_counter[c]:
                        matched -= 1
                left += 1

        return "" if min_win_len == float("inf") else s[best_start:best_start + min_win_len]
```

# 运行情况
```
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.3 MB, 在所有 C 提交中击败了100.00%的用户

执行用时 :108 ms, 在所有 Python3 提交中击败了84.00%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了8.11%的用户
```