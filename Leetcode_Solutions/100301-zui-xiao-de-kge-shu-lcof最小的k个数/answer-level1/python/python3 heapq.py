### 解题思路
python3 heapq

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        import heapq
        heapq.heapify(arr)
        ret_list = []
        for _ in range(k):
            ret_list.append(heapq.heappop(arr))

        return ret_list

```