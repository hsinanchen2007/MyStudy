不用暴力法的话感觉还挺坑的，虽然AC了，但实际上是蒙的。

```python []
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort()
        n, s = len(arr), [0]
        if arr[0] > target / n:
            return round(target / n)
        for a in arr:
            s.append(a + s[-1])
        if s[-1] <= target:
            return arr[-1]
        f = lambda t: min(t - 1, t, t + 1, key=lambda x: abs(target - x * (n - i - 1) - s[i + 1]))
        for i in reversed(range(n - 1)):
            t = (target - s[i + 1]) // (n - i - 1)
            if t > arr[i]:
                return f(t)
        return f(arr[0])
```

![image.png](https://pic.leetcode-cn.com/ffe08cb5c68cc1503060271f090f4f71b893403c0b7c7aea103df97877039e71-image.png)
