### 解题思路
> 双下标划窗找出不含重复字符的子串; 详见代码

### 代码

```c [groups1-c直观双指针]
#define MAX_CHAR_TYPES 256

int lengthOfLongestSubstring(char *s)
{
    int count[MAX_CHAR_TYPES] = {0};
    int left, right;
    int len = strlen(s);
    int longest = 0;
    int subStrLen = 0;
    left = 0;
    right = 0;
    while (right < len) {
        // 右侧移动, 找到第一个重复字符;
        while (right < len) {
            count[s[right]]++;
            if (count[s[right]] > 1) {
                break;
            }
            subStrLen += 1;
            right += 1;
        }

        if (longest < subStrLen) {
            longest = subStrLen;
        }
        if (right == len) {
            // 已经检查完整个字符串
            break;
        }

        // 左侧移动, 保证记录的是不含重复字符的子串;
        while (left < right) {
            count[s[left]]--;
            if (count[s[left]] == 1) {
                left += 1;
                break;
            }
            left += 1;
            subStrLen -= 1;
        }
        right += 1;
    }
    return longest;
}

```

```c [groups1-优化后只记录每个字母上一次出现的位置]
#define MAX_CHAR_TYPES 256

int lengthOfLongestSubstring(char *s)
{
    int index[MAX_CHAR_TYPES] = {0};
    int left, right;
    int len = strlen(s);
    int longest = 0;
    int subStrLen = 0;
    left = 0;
    right = 0;
    while (right < len) {
        if (index[s[right]] > left) {
            // 该字符之前出现, 从上一次出现位置+1记为新起点
            left = index[s[right]];
        }

        subStrLen = right - left + 1;
        if (longest < subStrLen) {
            longest = subStrLen;
        }
        index[s[right]] = right+1; // 位置+1, 记录该字符再次出现时下一次的新起点;
        right += 1;
    }
    return longest;
}
```

### 运行情况
```
执行用时 :8 ms, 在所有 C 提交中击败了68.70%的用户
内存消耗 :5.6 MB, 在所有 C 提交中击败了100.00%的用户
```