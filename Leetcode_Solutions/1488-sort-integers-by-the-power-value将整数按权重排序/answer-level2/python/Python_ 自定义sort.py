### 解题思路
根据题目自定义排序即可。

### 代码

```python
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        def getw(x):
            cnt = 0
            while x != 1:
                if x%2 == 0: x = x//2
                else:
                    x = x*3 + 1
                cnt +=1
            return cnt
        return sorted(list(range(lo, hi+1)), key = getw)[k-1]
```