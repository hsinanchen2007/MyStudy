### 解题思路
1 利用内置指数函数求等差数列之和，
2 右移一位除2

### 代码

```python3
class Solution:
    def sumNums(self, n: int) -> int:
        return int(math.pow(n,2)+n)>>1
    
```