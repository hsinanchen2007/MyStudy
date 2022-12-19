### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        z = x^y
        k = [2**a for a in range(31)]
        sum = 0
        for i in k:
            if i&z !=0:
                sum = sum + 1
        return sum
```