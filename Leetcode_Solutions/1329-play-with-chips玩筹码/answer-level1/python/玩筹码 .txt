### 解题思路
最终思想就是奇偶分组，比较较小值

### 代码

```python
class Solution(object):
    def minCostToMoveChips(self, chips):
        #首先以2为间隔将所有能划归到一起的数字分组，最终会分为两组 奇数组和偶数组
        odd,even = 0,0 #初始化统计数据
        for c in chips:
            if c % 2 == 0:
                even += 1
            else:
                odd += 1
        return min(odd,even)
```