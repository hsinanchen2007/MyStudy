### 解题思路
循环交换前后顺序

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        for i in range(len(s)//2):
            temp = s[len(s)-i-1]
            s[len(s)-i-1] = s[i]
            s[i] = temp
```