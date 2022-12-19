### 解题思路
- 1. 第一步，需要根据效率排序，效率是短板， 所以排序后问题变为计算当前最低效率*k个最大速度和的问题；
- 2. 第二步， 计算数组中k个最大和的时候，需要注意性能， 直接排序取前K个最大求和会超时，建议使用heapq解决；

### 代码

```python3
from heapq import heappush, heappop


class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        ordered = list(zip(efficiency, speed))
        ordered.sort(key=lambda x: x[0], reverse=True) # 性能逆序排后面好遍历计算
        q = []
        total = 0
        best = 0
        for eff, spd in ordered:
            if len(q) < k:
                total += spd
                heappush(q, spd)
            else:
                last_min = heappop(q)
                total -= last_min
                total += max(last_min, spd)
                heappush(q, max(last_min, spd))

            best = max(best, eff * total)
        return best % 1000_000_007

    def maxPerformance2(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        ordered = list(zip(efficiency, speed))
        ordered.sort(key=lambda x: x[0])
        q = []
        total = 0
        last_min = 0
        best = 0
        # 此处由于是eff从小到大排列， 求最大K元素和从最右侧开始逐渐累加计算；
        for i in range(len(speed) - 1, -1, -1):
            eff, spd = ordered[i]
            if len(q) == k:
                last_min = heappop(q)
                total -= last_min
            else:
                last_min = 0
            heappush(q, max(last_min, spd))
            total += max(last_min, spd)
            temp = eff * total
            if temp > best:
                best = temp
        return best % (10 ** 9 + 7)

    def get_max_k_sum(self, eff_speed, k):
        arr = [x[1] for x in eff_speed]
        if k >= len(arr):
            return sum(arr)
        return sum(sorted(arr, reverse=True)[:k])

    def maxPerformance1(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        # 蛮力计算方法， 关键在于获取数组的前k个最大值的和， 大数组超时
        ordered = list(zip(efficiency, speed))
        ordered.sort(key=lambda x: x[0])
        best = 0
        for i, eff_speed in enumerate(ordered):
            temp = eff_speed[0] * self.get_max_k_sum(ordered[i:], k)
            if temp > best:
                best = temp
        return best % (10 ** 9 + 7)

```

# 运行情况
```
heapq堆排序的结果，暴力计算直接超时了。
执行用时 :176 ms, 在所有 Python3 提交中击败了100.00%的用户
内存消耗 :29.9 MB, 在所有 Python3 提交中击败了100.00%的用户
```