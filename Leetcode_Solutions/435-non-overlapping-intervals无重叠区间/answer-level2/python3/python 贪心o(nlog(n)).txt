### 解题思路

策略：
把问题转换成：**最多能选取几个区间不重叠的区域**
那答案显然变成：**总区间个数 - 不重叠区间个数**

- 1. 按照结束时间从小到大排序，然后对新列表遍历。
- 2. 判断当前区间是否满足：**开始时间** 晚于或等于上一次的 **结束时间**
- 3. 每次都选结束时间最早的
- 4. 每选一次更新一下结束时间

### 为什么贪心算法有效
我一开始想，那如果是下面这种情况，虽然你结束时间早，但是你跨越的时间太长了啊！

但仔细想想，虽然下面的蓝线看起来占用空间很少，其实**当算法选择**上面这条红线时，意味着蓝线没占用的空间也不存在能选择的区间了。

![exm1.png](https://pic.leetcode-cn.com/a83914c872bc7b9653ed537bf12d025b04bea5ea706b5a97e8332cfae7287148-exm1.png)

如果是蓝线前面还存在可选择的区间。那算法会优先选绿线，而不是选到红线。

![exm2.png](https://pic.leetcode-cn.com/fc183ba92c23ea9fba8d62dbdbde8226f3bbb7b079e35a9182b0c612906f18fe-exm2.png)

### 代码

```python3
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        
        intervals = sorted(intervals, key=lambda x:x[1])

        ans = 0
        end = -float('inf')  # 结束时间
        for i in intervals:
            if i[0] >= end:
                ans += 1
                end = i[1]
        return len(interval) - ans
```