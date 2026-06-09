### 解题思路
字符串索引 

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        a = str(x)
        if x>=0:
            y = int(a[::-1])#从后向前索引 每次索引一位
        else:
            y = -int(a[:0:-1])#从后向0位索引；但不包括0位每次索引一位
        if -2**31<y<2**31-1:
            return y
        else:
            return 0
```