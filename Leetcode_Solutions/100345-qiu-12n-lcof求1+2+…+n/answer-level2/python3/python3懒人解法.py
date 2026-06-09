### 解题思路
使用range来确定加法范围： 0, 1, 2... n。 由于是否+0对结果没有影响，在此直接使用了range(n+1)
然后使用sum直接求和
（好了这是个偷懒方法）

### 代码

```python3
class Solution:
    def sumNums(self, n: int) -> int:
        return sum(range(n+1))
```