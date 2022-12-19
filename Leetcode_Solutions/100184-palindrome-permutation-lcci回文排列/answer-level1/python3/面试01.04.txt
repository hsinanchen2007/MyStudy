### 解题思路
把非重复的字符放到数组中，若字符数大于1则非回文数

### 代码

```python3
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        res = 0
        lis = []
        for i in s:
            if i not in lis:
                lis.append(i)
                res += 1
            else:
                res -= 1
                lis.remove(i)
        if res <= 1:
            return True
        else:
            return False
```