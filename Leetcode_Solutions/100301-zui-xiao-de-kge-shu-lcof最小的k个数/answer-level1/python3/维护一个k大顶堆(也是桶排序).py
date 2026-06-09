### 解题思路
堆顶为最大值，不断用更小的值代替堆顶，最后该堆就是最小k个数

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        # if k==0: return []
        # if len(arr) < k: return arr
        # for i in range(k):
        #     res = arr[:k]
        # res.sort()
        # for j in range(k, len(arr)):
        #     i = k-1
        #     while(i>=0 and arr[j]<res[i]):
        #         i-=1
        #     if i<k-1:
        #         res.insert(i+1, arr[j])
        #         res.pop()
        # return res
        if k==0: return []
        opposite = [-x for x in arr[:k]]
        heapq.heapify(opposite) #小顶堆 实际上是大顶堆
        for i in range(k, len(arr)):
            if -opposite[0]>arr[i]:
                heapq.heappop(opposite)
                heapq.heappush(opposite, -arr[i])
        return [-x for x in opposite]
```