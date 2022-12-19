### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        # min_value = float('-inf')
        # max_value = float("inf")
        # if k>len(arr):
        #     return -1
        # if k==len(arr):
        #     return arr
        # queue = collections.deque(arr[:k])
        # min_value = min(arr[:k])
        # max_value = max(arr[:k])
        # for i in range(k,len(arr)):
        return sorted(arr)[:k]


```