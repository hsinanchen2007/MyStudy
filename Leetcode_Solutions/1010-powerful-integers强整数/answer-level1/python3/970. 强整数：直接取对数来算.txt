![image.png](https://pic.leetcode-cn.com/cb1a96a40fcdc5025a9d175fc55f3d4450535466e45081b9fb0f1492032128df-image.png)

28ms，仅供参考。

```python []
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        a = int(math.log(bound, x)) + 1 if x > 1 else 1
        b = int(math.log(bound, y)) + 1 if y > 1 else 1
        ans = set()
        for i in range(a):
            for j in range(b):
                k = x ** i + y ** j
                if k > bound:
                    break
                ans |= {k}
        return ans
```
