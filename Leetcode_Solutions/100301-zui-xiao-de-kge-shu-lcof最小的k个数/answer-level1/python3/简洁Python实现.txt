### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        import heapq
        if k == 0 or not arr:
            return []
        hp = [-x for x in arr[:k]] # 保持k个数的大根堆
        heapq.heapify(hp)
        for i in range(k, len(arr)): # 从k开始遍历
            if -hp[0] > arr[i]: # 检查大根堆中最大的数 是否 大于其他数
                heapq.heappop(hp)
                heapq.heappush(hp, -arr[i])
        res = [-x for x in hp]
        return res
```