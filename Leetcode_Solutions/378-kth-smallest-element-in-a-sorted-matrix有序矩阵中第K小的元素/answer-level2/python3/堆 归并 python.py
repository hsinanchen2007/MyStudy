```
import heapq
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        heap = []
        for i in range(n):
            heapq.heappush(heap,(matrix[i][0],i,0))
        t = 0
        while t < k:
            num,row_index,col_index = heapq.heappop(heap)
            col_index += 1
            if col_index<n:
                heapq.heappush(heap,(matrix[row_index][col_index],row_index,col_index))
            t += 1
        return num
```
