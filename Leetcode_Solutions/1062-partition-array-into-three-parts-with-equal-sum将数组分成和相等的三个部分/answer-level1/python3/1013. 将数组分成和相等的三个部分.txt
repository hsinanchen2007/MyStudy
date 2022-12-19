### 解题思路

添加了新用例，原代码过不了了，重新写了一遍。

### 代码

```python []
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = t = sum(A) / 3
        c = 0
        for i in itertools.accumulate(A):
            if i == t:
                t += s
                c += 1
        return c >= 3 and i == s * 3
```