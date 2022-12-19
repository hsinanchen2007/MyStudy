```python
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        # return the indices : start of each interval
        # nume.length : 2e4
        # k => [1, nums.length // 3]
        # window size =  k 
        # interval_cnt = 3
        
        # dp[i][j] = max(dp[i - 1][j - k] + sum(j - k, j), dp[i][j - 1])
        # i means intervals num.
        # j means current length.
        sumArr = []
        for i, num in enumerate(nums): # O(N)
            if i == 0: sumArr.append(num)
            else: sumArr.append(sumArr[-1] + num)

        def get_interval_sum(i, j, sumArr): # O(1)
            # corner case
            if i < 0: return sumArr[j]
            return sumArr[j] - sumArr[i]

        dp = [[0] * len(nums) for _ in range(4)]
        index_arr = [[0] * len(nums) for _ in range(4)]
        res, maxVal = [], float('-inf')
        # i = 1
        # j = 0, 
        # dp[1][k] = sumArr[i]
        # Time complexity: O(3 * N)
        for i in range(1, 4):
            for j in range(i * k - 1, len(nums)):
                interval_sum = get_interval_sum(j - k, j, sumArr)
                if dp[i - 1][j - k] + interval_sum > dp[i][j - 1]:
                    index_arr[i][j] = j - k + 1
                    dp[i][j] = dp[i - 1][j - k] + interval_sum
                else:
                    index_arr[i][j] = index_arr[i][j - 1]
                    dp[i][j] = dp[i][j - 1]
                
                if i == 3 and j >= 3 * k - 1 and dp[i][j] > maxVal:
                    maxVal = dp[i][j]
                    index3 = index_arr[i][j]
                    index2 = index_arr[i - 1][index3 - 1]
                    index1 = index_arr[i - 2][index2 - 1]
                    res = [index1, index2, index3]
        return res
```