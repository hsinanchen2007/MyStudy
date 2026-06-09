### 解题思路
- Counter函数可以统计出各个元素的个数，然后我们按个数大小存入小根堆结构

- nlargest函数取出前K大的元素
注：这里时间复杂度不是很好，可以不使用nlargest函数直接循环得到结果

### 代码

```python3
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #堆
        from collections import Counter
        import heapq

        res = Counter(nums)
        heap = []
        for key,value in res.items():
            heapq.heappush(heap,[value,key]) #这里按value排序存入
        s = heapq.nlargest(k,heap)
        res = []
        for i in s:
            res.append(i[1])
        return res
```