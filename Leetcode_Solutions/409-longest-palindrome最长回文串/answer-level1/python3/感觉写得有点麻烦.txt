### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dict = {}
        ans = 0
        for i in s:
            dict[i] = dict.get(i, 0) + 1
        for i in dict.keys():
            ans += dict[i] // 2 * 2
            dict[i] -= dict[i] // 2 * 2
        for i in dict.keys():
            if dict[i] % 2 == 1:
                ans += 1
                break
        return ans
        
```