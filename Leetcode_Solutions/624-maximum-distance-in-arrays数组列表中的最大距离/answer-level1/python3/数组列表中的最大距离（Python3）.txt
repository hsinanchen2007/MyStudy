#### 思路
思路为官方题解的方法二，容易出错的是保证最大值和最小值不能同时出现在同一数组中，因此从索引1开始遍历。
#### 代码
```
class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        res = 0
        min_val = arrays[0][0]
        max_val = arrays[0][-1]
        for i in range(1,len(arrays)):
            res = max(res,(arrays[i][-1] - min_val),(max_val - arrays[i][0]))
            min_val = min(min_val,arrays[i][0])
            max_val = max(max_val,arrays[i][-1])
        return res
```
#### 复杂度分析
- 时间复杂度：O（N），我们遍历了一遍数组。
- 空间复杂度：O（N）使用了`res`,`min_val`,`max_val`等常数空间。