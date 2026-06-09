```python
class Solution:
    def makesquare(self, nums: List[int]) -> bool:
        # dfs => 2 ** 16 => 64 * 1000 => 6.4 * 10 ** 4
        # prune: edge <= sum // 4
        sum_length = sum(nums)
        if sum_length % 4 != 0: return False # edge case
        edge_length = sum_length // 4
        edge_arr = [0] * 4
        res = 0
        nums.sort(reverse = True) # prune
        def getMaxSquare(index, edge_arr, edge_length):
            nonlocal res
            if res : return
            if index == len(nums): 
                if edge_arr[0] == edge_arr[1] == edge_arr[2] == edge_arr[3]:
                    res = max(res, edge_arr[0])
                return
            for i in range(4):
                if edge_arr[i] + nums[index] <= edge_length: #prune
                    edge_arr[i] += nums[index]
                    getMaxSquare(index + 1, edge_arr, edge_length)
                    edge_arr[i] -= nums[index]
        getMaxSquare(0, edge_arr, edge_length)
        return res 
```