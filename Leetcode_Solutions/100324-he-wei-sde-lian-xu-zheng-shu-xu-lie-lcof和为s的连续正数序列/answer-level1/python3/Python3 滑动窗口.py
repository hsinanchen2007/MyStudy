一眼就能看出来是滑动窗口，但是确实之前没怎么做过，所以在错误的道路上一路到黑。

正确的思路应该是从 *low* [1, 2] *high* 开始滑动，如果和小了，那就把 high 向右移，如果和大了，那就把 low 向左移。可以通过一些简单的推演知道 high 最大可以等于 targer/2，由这个限制条件可以缩短计算时间。

```py
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        #考虑特殊情况
        if target <= 2:
            return []

        low = 1
        high = 2
        total = 3
        res = []
        
        while high < target//2 + 2 and low < high:
            if total == target:
                res.append(list(range(low, high+1)))
                total -= low
                low += 1
            elif total > target:
                total -= low
                low += 1
            else:
                high += 1
                total += high
        return res
```