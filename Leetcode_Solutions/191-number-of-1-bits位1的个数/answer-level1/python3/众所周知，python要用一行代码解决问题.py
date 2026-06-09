### 解题思路
str中count()函数的应用

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        return bin(n).count('1')
```