### 解题思路
服不服!

### 代码

```python3
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n in [3 ** i for i in range(30)]
```