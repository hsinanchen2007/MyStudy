嘚瑟下：

![1.png](https://pic.leetcode-cn.com/f756a121d04699d5d8ba331bd7a636292017e9c9de9ea6b130e08e7476aec549-1.png)

```python
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        if n <= 10:
            return [1, n - 1]
        for i in range(1, n):
            if '0' not in (str(i) + str(n - i)):
                return [i, n - i]
```
