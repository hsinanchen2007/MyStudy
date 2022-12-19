思路比较清晰，排序后分段，只要首尾跨度小于这段长度，就应该在一段之内。

比如，`[1,2,2,3,5]`，前面`[1,2,2,3,5]`的长度为5，那么首尾的跨度在小于5-1=4时，都应该归在一段之内。
```
sorted_a[j] - sorted_a[i] < j - i + 1
```
需要进行的操作数也就容易计算了，是这段等差数列的和，减去这段的和。
```
res += (a+b)*(j-i) // 2 - sum(sorted_a[i:j])
```
代码如下

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        sorted_a = sorted(A)
        res = 0
        n = len(sorted_a)
        i = 0
        j = 0
        while j < n - 1:
            while sorted_a[j] - sorted_a[i] < j - i + 1:
                j += 1
                if j == n:  # 边界条件
                    break
            if j - i > 1:
                a = sorted_a[i]
                b = a + j - i - 1
                res += (a+b)*(j-i) // 2 - sum(sorted_a[i:j])
            i = j
            j = i
        return res

```
