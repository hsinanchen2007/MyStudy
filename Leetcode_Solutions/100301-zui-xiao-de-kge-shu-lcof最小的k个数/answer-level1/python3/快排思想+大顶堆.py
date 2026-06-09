```python
import heapq
class Solution:
    def getLeastNumbers0(self, arr: List[int], k: int) -> List[int]:
        if not k: return []
        start, end = 0, len(arr)-1
        while start < end:
            j = start
            for i in range(start, end+1):
                if arr[i] <= arr[end]:
                    arr[i], arr[j] = arr[j], arr[i]
                    j += 1
            if j == k:
                return arr[:k]
            elif j > k:
                end = j - 2
            else:
                start = j
        return arr[:start+1]

    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if not k: return []
        heap = []
        for num in arr:
            if len(heap) < k:
                heapq.heappush(heap, -num)
            else:
                heapq.heappushpop(heap, -num)
        heap = [-num for num in heap]
        return heap 
```