```python
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        heap = []
        char_arr = [0] * 26
        for ch in tasks:
            char_arr[ord(ch) - ord('A')] += 1
        for i in range(26):
            if char_arr[i]:
                heapq.heappush(heap, -char_arr[i])
        res = 0
        while heap:
            temp = []
            i = 0
            while i <= n:
                if heap == []:break
                cnt = -heapq.heappop(heap)
                if cnt > 1:
                    temp.append(1 - cnt)
                i += 1
            for t in temp:
                heapq.heappush(heap, t)
            res += n + 1 if temp else i
        return res
```