### 解题思路
python三种方法

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        #排序
        arr.sort()
        res1=arr[:k]
        #大顶堆
        q=[]
        if k==0:return []
        for i in range(k):
            q.append(-arr[i])
        heapq.heapify(q)
        for i in range(k,len(arr)):
            heapq.heappush(q,max(heapq.heappop(q),-arr[i]))
        res2=[-i for i in q]
        return res2
        #堆排序,小顶堆
        q=[]
        heapq.heapify(arr)
        for i in range(k):
            q.append(heapq.heappop(arr))
        res3=q
        return res3

```