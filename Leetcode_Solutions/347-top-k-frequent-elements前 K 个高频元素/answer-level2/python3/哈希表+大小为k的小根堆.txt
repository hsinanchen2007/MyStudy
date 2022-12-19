```
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ### 建哈希表
        dic = {}
        for i in nums:
            if i not in dic:
                dic[i] = 1
            else:
                dic[i] += 1
        #### 建大小为k的小根堆，并调整
        heap = []
        for i in dic:
            if len(heap) < k:
                heap.append([dic[i], i])
                if len(heap) == k:
                    heapq.heapify(heap)
                continue

            if len(heap) == k:
                if dic[i] > heap[0][0]:
                    heap[0] = [dic[i], i]
                heapq.heapify(heap)

        res = [i[1] for i in heap][::-1]
        return res
                

```
