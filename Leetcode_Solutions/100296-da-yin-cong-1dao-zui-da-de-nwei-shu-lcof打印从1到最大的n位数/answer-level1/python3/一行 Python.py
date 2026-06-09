### 解题思路
将 $1$ 到 $10^n-1$ 分别添加到数组中即可。

### 代码

```python
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        return [i for i in range(1,10**n)]
```