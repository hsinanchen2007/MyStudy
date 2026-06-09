![image.png](https://pic.leetcode-cn.com/c24359a51a629c45b4770d43fff7fbcdafde54163c428bd40b2a1c8907d30ad2-image.png)

把四种相交情况讨论出来就可以了，时间仅供参考。

```python []
class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        slots1.sort()
        slots2.sort()
        def f(a, b, c, d):
            if a <= b <= c <= d and b + duration <= c:
                ans.extend([b, b + duration])
        ans, i, j, n1, n2 = [], 0, 0, len(slots1), len(slots2)
        while i < n1 and j < n2 and not ans:
            (a, b), (c, d) = slots1[i], slots2[j]
            f(a, c, b, d)
            f(a, c, d, b)
            f(c, a, d, b)
            f(c, a, b, d)
            if b < d:
                i += 1
            else:
                j += 1
        return ans[: 2]
```
