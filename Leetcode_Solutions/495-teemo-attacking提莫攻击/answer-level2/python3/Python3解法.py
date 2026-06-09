### 解题思路
每次攻击的时候把收益给预算进去，如果下次攻击的间隔比中毒时间长，那上次的收益是有效的，否则上次的收益会打折，打折的收益正好是上次到现在的时间间隔。
![image.png](https://pic.leetcode-cn.com/5a1ef93cb7b8b4e90ae221bd59fc83516e369a7adec7698fbca4e487dd9ef684-image.png)

### 代码

```python3
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if not timeSeries or duration == 0:
            return 0

        timeSeries.sort()
        total_duration = duration
        for i in range(1, len(timeSeries)):
            if timeSeries[i] - timeSeries[i-1] + 1> duration:
                total_duration += duration
            else:
                total_duration += timeSeries[i] - timeSeries[i-1]
        return total_duration
                
            
```