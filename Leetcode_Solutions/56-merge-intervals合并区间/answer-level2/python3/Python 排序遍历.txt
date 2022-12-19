基本上是排序遍历的思路。

简而言之就是，

1. 如果前一个元素（sort之后此元素第一个值一定小于下一个元素的第一个值）的最大值都没有下一个元素的最小值大，那么就没办法合并，直接抬走下一个
2. 反之，说明可以合并，那么找这两个元素合并起来后的最小与最大值作为新的边界，再去尝试合并下一个值。



```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        i = 1
        while(i < len(intervals)): 
            if max(intervals[i-1]) < min(intervals[i]):
                i += 1
                continue
            else:
                subli = intervals[i-1]+intervals[i]
                intervals[i-1] = [min(subli),max(subli)]
                intervals.pop(i)
        
        return intervals
```
