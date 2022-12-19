先给数组排序，然后从后向前遍历列表中的元素，当第h个元素不满足引用数大于等于h+1时退出，说明h再增加时不能满足条件。
如果排序时直接逆序排序运行时间比正向排序的慢，我也不知道为什么。。。


```python []
class Solution:

    def hIndex(self, citations: List[int]) -> int:
        if not(citations):
            return 0
        
        citations.sort()
        Total = len(citations)
        

        for h in range(Total):
            if citations[Total - 1 - h] >= h+1:
                if h == Total -1:
                    h += 1
            else:
                break
        
        return h
            
            
```
