### 解题思路
两层循环，外层循环从头到尾逐字符遍历字符串。第二层循环从字符串尾部开始遍历，直到第一层循环当前遍历到的字符，当满足回文字串时则和当前最长回文字串对比并更新。然后跳出当前二层循环，因为二层循环是从外往内遍历，不可能再遇到比当前字串更长的回文字串。如此类推，直到外层循环把所有字符遍历完毕。


### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        max_substr = ""
        for i in range(0,len(s)):
            for j in range(len(s)-1,i-1,-1):
                if s[i] != s[j]:
                    continue
                if s[i:j] == s[j:i:-1]:
                    sub_len = j - i + 1
                    if sub_len > len(max_substr):
                        max_substr = s[i:j+1]
                    break   
        return max_substr
```