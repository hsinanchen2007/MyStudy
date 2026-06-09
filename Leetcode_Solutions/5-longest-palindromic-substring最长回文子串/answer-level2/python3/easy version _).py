### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        result = ""
        length = 0
        for i in range(len(s)):
            temp1 = ""
            temp2 = ""
            for str1 in s[i:]:
                temp1 = temp1 + str1
                temp2 = str1 + temp2
                if temp1 == temp2 and len(temp1) > len(result):
                    result = temp1
                else:
                    continue
        return result
```