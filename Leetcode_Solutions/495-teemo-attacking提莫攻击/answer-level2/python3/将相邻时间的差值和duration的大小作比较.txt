# 将相邻时间的差值和duration的大小作比较
1. 将指针放在数组第二个元素，便于比较当前元素和前一个元素的差值与中毒持续时间，即判断
当前元素 - 前一元素 与 中毒持续时间 的大小：
    1. 如果 前一元素 + 中毒持续时间 >= 中毒持续时间，则将总中毒时间加上 当前元素 - 前一元素 的差值
    2. 如果 前一元素 + 中毒持续时间 < 中毒持续时间，则将总中毒时间加上 单次中毒持续时间 duration
2. 如果到达数组尾部，将 总中毒时间 + 单次中毒持续时间（duration）后返回即可

```
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        '''
        1.将指针放在数组第二个元素，便于比较当前元素和前一个元素的差值与中毒持续时间，即判断
        当前元素 - 前一元素 与 中毒持续时间 的大小：
            1.如果 前一元素 + 中毒持续时间 >= 中毒持续时间，则将总中毒时间加上 当前元素 - 前一元素 的差值
            2.如果 前一元素 + 中毒持续时间 < 中毒持续时间，则将总中毒时间加上 单次中毒持续时间 duration
        2.如果到达数组尾部，将 总中毒时间 + 单次中毒持续时间（duration）后返回即可
        '''
        res = 0
        n = len(timeSeries)
        left = 1
        if n == 1:
            return duration
        while left <= n - 1:
            if timeSeries[left - 1] + duration >= timeSeries[left]:
                res += timeSeries[left] - timeSeries[left - 1]
            else:
                res += duration
            # 在到达列表末尾时，刷新中毒持续时间
            if left == n - 1:
                res += duration
            left += 1
        return res
```
