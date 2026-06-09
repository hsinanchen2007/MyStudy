### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sumNums(self, n: int) -> int:

        return n and n+ self.sumNums(n-1)  
```