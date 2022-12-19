### 解题思路
所有5的次数的商求和
其实转化成5进制也很好求，但是因为没有直接转化的函数，实际执行时间比这个要高

### 代码

```python3
class Solution:
    def trailingZeroes(self, n: int) -> int: 
        if n<5: return 0
        x=5
        y=0
        while x <= n: 
            y+=n// x
            x*=5
        return y
```