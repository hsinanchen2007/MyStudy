### 解题思路
由等差数列求和公式可得 target最多可以分成 `int((2*target)**0.5)` 个数的和。那么我们只需要把target可以拆分的所有情况枚举一下。

如果可以拆分为奇数份，那么target肯定是中间那个数（也就是中位数）的倍数；如果可以拆分为偶数份，那么target肯定是中间两个数的倍数。由此可以得到target能否拆分的条件，以及拆分后中位数的数值。然后向左右延伸就可以了。

### 代码

```python
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        for i in range(2, int((2*target)**0.5)+1):
            if i%2 != 0:
                if target%i == 0:
                    mid = target//i
                    res.append(list(range(mid - i//2, mid + i//2+1)))
            else:
                if target%i == i//2:
                    mid = target//i
                    res.append(list(range(mid - i//2 + 1, mid + i//2 + 1)))
        return sorted(res, key = lambda x: x[0])
            
```