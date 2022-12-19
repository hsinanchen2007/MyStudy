### 解题思路
暴力解法，既然题目已经约定输入一定是一个段式回文，那么就可以用两个指针，一个指向头部left，一个指向尾部right。然后从长度len从1开始，从头截取一个长度为len的字符串a，从尾部指针往前截取一个长度为len的字符串b，判断a和b是不是相等的字符串。如果是，那么将left加上长度len，right减去长度len，然后递归去判断[left, right]的子串的段式回文长度，并且将返回结果加上2。

### 代码

```cpp
class Solution {
public:
    int dfs_longestDecomposition(int left, int right, string text) {
        if (left > right) return 0;
        if (left == right) return 1;
        int half_len = (right - left + 1) / 2;
        int len = 1;
        int res = 1;
        while (len <= half_len) {
            int i = 0;
            while (i < len && text[left + i] == text[right - len + 1 + i]) i++;
            if (i == len) {
                res = 2+dfs_longestDecomposition(left + len, right - len, text);
                break;
            }
            len++;
        } 
        return res;
    }

    int longestDecomposition(string text) {
        return dfs_longestDecomposition(0, text.size() - 1, text);
    }
};
```