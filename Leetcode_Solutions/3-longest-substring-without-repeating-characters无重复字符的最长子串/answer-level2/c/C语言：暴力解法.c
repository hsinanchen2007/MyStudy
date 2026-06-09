### 解题思路
暴力解法

### 代码

```c
#define MAX(a, b) (a) > (b) ? (a) : (b)

bool IsStrHasSameChar(char *s, int start, int end)
{
    for (int i = start; i < end; i++) {
        if (s[i] == s[end]) {
            return true;
        }
    }

    return false;
}

int lengthOfLongestSubstring(char * s)
{
    int ans = 0;
    int size = strlen(s);

    /* 使用双层循环，好像算不得双指针？ */
    for (int left = 0; left < size; left++) {
        for (int right = left; right < size; right++) {
            if (IsStrHasSameChar(s, left, right) == false) {
                /* 如果从左位置到右位置不存在相同的字符，那么认为当前长度可以+1 */
                ans = MAX(ans, (right - left + 1));
            } else {
                /* 如果从左位置到右位置的这段字符串存在相同字符，则跳出，左指针前移 */
                break;
            } 
        }
    }

    return ans;
}
```