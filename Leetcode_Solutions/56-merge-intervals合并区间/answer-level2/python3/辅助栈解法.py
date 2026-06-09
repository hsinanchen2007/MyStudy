### 解题思路
先进行排序，保证每个区间的第一个元素大于等于上一个区间的第一个元素
使用辅助栈，先将第一个区间放入栈内，然后对比栈顶的区间和interval后面的区间，
如果没有重合，就添加下一个区间到栈顶，如果有重合，那就去除栈顶区间，并将两个区间和并
再放入栈顶，这样重复直到最后一个区间

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # 避免区间不是从小到大排列的
        if intervals ==[] :return []
        intervals.sort()
        res = [intervals[0]]
        
        # 先将interval的第一个队列放入res
        #排完序过后一定满足的条件 
        #intervals[i][0] <= intervals[i+1][0]
        for i in range(1, len(intervals)):
            x = []
            if res[-1][1] < intervals[i][0]:
                #此时区间不相关，排序过后，i+2个区间也不会与第i 个区间相关
                res.append(intervals[i])
            elif res[-1][1] >= intervals[i][0] and res[-1][1] <=intervals[i][1]:
                #此时两个区间相关：
                x[:] = res.pop()

                res.append([x[0], intervals[i][1]])
                
                # 去掉重复的那个区间
            else:
                # res[-1][1] > intervals[i][1],说明这个区间包含了下一个区间
                # 可以不做操作
                continue
        return res
            
```