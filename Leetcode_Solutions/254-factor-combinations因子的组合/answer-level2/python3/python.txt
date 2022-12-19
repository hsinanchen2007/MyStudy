### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getFactors(self, n: int) -> List[List[int]]:
        res = []
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                comb = sorted([i, n // i])
                if comb not in res:#去重
                    res.append(comb)
                for item in self.getFactors(n // i) :
                    comb = sorted([i] + item)
                    if comb not in res:#去重
                        res.append(comb)
        return res
```