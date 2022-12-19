### 解题思路
python3堆的典型应用

### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        import heapq
        len_nums = len(nums)

        is_opposite = False
        if k < len_nums//2:
            is_opposite = True
            nums = [-item for item in nums]
        else:
            k = len_nums + 1 - k

        heapq.heapify(nums)
        for _ in range(k-1):
            heapq.heappop(nums)

        return -heapq.heappop(nums) if is_opposite else heapq.heappop(nums)

```