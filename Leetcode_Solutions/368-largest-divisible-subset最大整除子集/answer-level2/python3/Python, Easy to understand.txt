+ **Analysis**:

first, sort `nums` at ascending order

then, use `dp[i]` to store the previous index of `nums[i]`, use `count[i]` to store the max size of subset which is ended up with `nums[i]`

traverse `nums[i]`, find the largest subset from `nums[0]` to `nums[i-1]`, store previous index as `tmpIdx`, 

`tmpCount` is the max size of subset which is ended up with `nums[i]`

`p` is used to find the last index of the largest subset, than traverse with `dp[p]` and reverse the `res`, that's the answer

+ **Solution**:
```
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if nums is None or len(nums) == 0: return []
        nums.sort()
        dp = [-1] * len(nums)
        count = {}
        for i in range(len(nums)):
            tmpIdx = i
            tmpCount = 1
            for j in range(i-1, -1, -1):
                if nums[i] % nums[j] == 0 and (1+count[j]) > tmpCount:
                    tmpCount = 1 + count[j]
                    tmpIdx = j
            dp[i] = tmpIdx
            count[i] = tmpCount
        res = []
        p = int(max(count.items(), key=operator.itemgetter(1))[0])
        while dp[p] != p:
            res.append(nums[p])
            p = dp[p]
        res.append(nums[p])
        res.reverse()

        return res 
```
