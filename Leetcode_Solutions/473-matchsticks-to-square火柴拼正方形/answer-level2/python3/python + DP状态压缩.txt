```python
class Solution:
    def makesquare(self, nums: List[int]) -> bool:
        # dp + bit
        # Time complexity: O(N * 2 ** N)
        # Space complexity: O(2 ** N)
        sum_arr = sum(nums)
        if sum_arr % 4 != 0: return False
        edge_length = sum_arr >> 2
        n = len(nums)
        all_state = (1 << n) - 1
        edge_arr, half_arr = [], []
        for mask in range(all_state):
            edge = 0
            for i in range(n):
                if mask >> (n - 1 - i) & 1:
                    edge += nums[i]
            if edge == edge_length:
                edge_arr.append(mask)

        for i in range(len(edge_arr) - 1):
            for j in range(i + 1, len(edge_arr)):
                if edge_arr[i] & edge_arr[j] == 0:
                    half_arr.append(edge_arr[i] | edge_arr[j])

        for i in range(len(half_arr) - 1):
            for j in range(i + 1, len(half_arr)):
                if half_arr[i] & half_arr[j] == 0:
                    if (half_arr[i] | half_arr[j]) == (1 << n) - 1: return True
        return False
```