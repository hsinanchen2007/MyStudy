### 解题思路
此处撰写解题思路
1. 选择两个指针，如果指针所指位置字符相等，则指针向左右移动，直到字符不相等或者超出边界
2. 需要注意回文串是奇数还是偶数
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def help(s, i, j):
            while i >= 0 and j < len(s) and s[i] == s[j]:
                i -= 1
                j += 1
            return j-i-1, s[i+1:j]
        if s == None or len(s) < 2:
            return s
        max_l = 1
        max_s = s[0]
        for i in range(len(s)):
            l, temp = help(s, i, i)
            if l > max_l:
                max_l = l
                max_s = temp
            l, temp = help(s, i, i+1)
            if l > max_l:
                max_l = l
                max_s = temp
            # print(max_s)
        return max_s

```