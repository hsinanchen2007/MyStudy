#### 心态很重要
比赛的时候被简单题的数据范围迷惑了，看这道题的时间不多，心急地找状态迁移方程……
附上最普通的解法：先逆序排列，随后记录初始元素到当前元素的和，若小于0则终止……
```
def maxSatisfaction(satisfaction):
    satisfaction.sort(reverse=True)
    ans = 0
    tmpsum = 0
    for i in satisfaction:
        tmpsum += i
        if tmpsum < 0:
            return ans
        ans += tmpsum
    return ans
```
