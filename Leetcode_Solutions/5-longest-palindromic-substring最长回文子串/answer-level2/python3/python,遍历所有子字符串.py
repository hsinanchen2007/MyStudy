### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        longest_str = ""
        max_count = 0
        # for each length
        for i in range(1,l+1):
            # for each string
            for j in range(l-i+1):
                temp = s[j:j+i]
                if temp == temp[::-1]:
                    if i > max_count:
                        max_count = i
                        longest_str = temp
                        break
        return longest_str


```