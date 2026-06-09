**思路：**

本题数据范围是`20000`，直接加的暴力方法会超时，需要优化到线性时间才行，考虑前缀和或者线性扫描，本质是一样的。题目中`bookings`每一项给出了一个区间，包含区间的开始位置、结束位置和区间值，当我们从左到右遍历答案数组时，进入这个区间就要加上这个区间的值，出这个区间就要减去这个区间的值，所以我们只需要用字典或者在数组中记录一下区间端点和相应的值，再从左到右扫描一遍数组即可。

**图解：**

![前缀和法](https://pic.leetcode-cn.com/7a21990026deb4155c10bb22e1929b6f0aa8fa5f97cf2a469f9199fdd7ded53a-1109-1.gif)
![扫描线法](https://pic.leetcode-cn.com/1117f6da86884bd4a7c132c6252f11e080fbe748cf7640f8271a1307807b5e71-1109-2.gif)


**代码：**
```python
# 前缀和解法
class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        ans = [0] * n
        for start, end, val in bookings:
            ans[start - 1] += val
            if end < n: ans[end] -= val
        for i in range(1, n):
            ans[i] += ans[i - 1]
        return ans
```

```python
# 扫描线解法
class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        ans = [0] * n
        d = dict()
        for start, end, val in bookings:
            d[start - 1] = d.get(start - 1, 0) + val
            d[end] = d.get(end, 0) - val
        s = 0
        for i in range(n):
            if i in d:
                s += d[i]
            ans[i] = s
        return ans
```