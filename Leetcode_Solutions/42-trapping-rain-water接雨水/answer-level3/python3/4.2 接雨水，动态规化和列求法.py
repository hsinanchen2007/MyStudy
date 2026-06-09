### 解题思路
看大神解答得知：
1.第一列和最后一列一定没有水
2.除了第一列和最后一列的所有列 小于 其左右两边最大列中的最小列时，才会积水
所以每次都去找每一列的左右两边的最大最小列，如果最大最小列都小于此列的话，即不积水
否则积水: 此列 - max(最大列，最小列)  

### 代码
```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        ans = 0

        for i in range(1, n - 1):
            # 因为 头和尾一定没有水

            lmax = 0
            for k in range(i - 1, -1, -1):
                if height[k] > lmax:
                    lmax = height[k]

            rmax = 0
            for m in range(i + 1, n):
                if height[m] > rmax:
                    rmax = height[m]

            lower = min(lmax, rmax)
            if height[i] < lower:
                ans += lower - height[i]

        return ans

```
### 动态规化，使用列的思想

### 代码

```python3

def trap(self, height: List[int]) -> int:
    # 动态规化
    # 前面一个柱子的左边或者右边的最大值已经之前得到过了，所以用两个list来储存 左边最大值和右边最大值
    # 长度为两个height 长度 -2
    # lmax[i] 储存第i个list 的左边最大柱子
    # rmax[i] 储存第ii个list 的右边最大柱子
    n = len(height)
    lmax = [0]*n
    rmax = [0]*n
    ans = 0
    # 先找到每个柱子左右两边的最高度
    # 此时只需要判定前一个柱子和其左边最大柱子选一个最大的就是现在这个柱子的左边最大柱子
    # 对于右边最大柱子也时同理
    for i in range(1, n-1):
        # 左边最高
        lmax[i] = max(lmax[i-1], height[i-1]) 
    
    for i in range(n-2, 0, -1):
        rmax[i] = max(rmax[i+1], height[i+1])
    
    # 然后求每个柱子能装多少水
    for i in range(1, n-1):
        # 因为 头和尾一定没有水           
        lower = min(lmax[i], rmax[i])
        # 得到第i个柱子左右两边的最大柱子中小的那一个为lower
        if height[i] < lower:
            # 如果第i个柱子小于左右两边的最小值
            # 如果不满足条件，说明这个柱子不会装水
            ans += (lower - height[i])
        
    return ans

```


