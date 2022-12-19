与leetcode 56合并区间是一模一样的问题
```
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if len(timeSeries) == 0:
            return 0
        
        if len(timeSeries) == 1:
            return duration
        
        total_time = 0
        x_left, x_right = timeSeries[0], timeSeries[0] + duration

        for i in range(1, len(timeSeries)):
            if x_left <= timeSeries[i] <= x_right and timeSeries[i] + duration > x_right:
                x_right = timeSeries[i] + duration
            elif x_left <= timeSeries[i] <= x_right:
                continue
            else:
                total_time += x_right - x_left
                x_left = timeSeries[i]
                x_right = x_left + duration
        
        return total_time + x_right - x_left
```
