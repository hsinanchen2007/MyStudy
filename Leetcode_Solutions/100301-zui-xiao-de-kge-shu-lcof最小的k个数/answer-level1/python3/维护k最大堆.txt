### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k==0:return []
        h = [-x for x in arr[:k]]
        heapq.heapify(h)
        for i in range(k,len(arr)):
            heapq.heappush(h,-arr[i])
            heapq.heappop(h)
        ans = [-x for x in h]
        return ans

```