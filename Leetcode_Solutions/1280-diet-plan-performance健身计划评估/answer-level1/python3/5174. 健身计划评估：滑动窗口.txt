原本以为是切割数组，但其实第一个官方用例就是不切割的。

140ms仅供参考。

```py
class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        f = lambda t: (t > upper) - (t < lower)
        s = sum(calories[: k])
        ans = f(s)
        for i in range(k, len(calories)):
            s += calories[i] - calories[i - k]
            ans += f(s)
        return ans
```

