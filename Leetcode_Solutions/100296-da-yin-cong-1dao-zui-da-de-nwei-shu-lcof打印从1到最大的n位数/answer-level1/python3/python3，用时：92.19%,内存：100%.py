### 解题思路
使用列表生成器。基本语法[exp for x in iterable if True]

### 代码

```python3
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        return [x for x in range(pow(10,n)) if x!=0]
```