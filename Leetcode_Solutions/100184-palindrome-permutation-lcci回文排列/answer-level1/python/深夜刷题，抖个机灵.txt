### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        if not s:return False
        lens = 0
        dict = collections.Counter(s)
        for i in dict:
            lens += dict[i] // 2 * 2
            if lens % 2 == 0 and dict[i] % 2 == 1:
                lens += 1
        return True if lens == len(s) else False
        
```