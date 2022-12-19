降序后求和，当和大于nums数组和的1/2时弹出
```
class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        temp = int(sum(nums)/2)
        nums.sort(reverse= True)
        ans = []
        s = 0
        for n in nums:
            s += n
            ans += [n]
            if s > temp:
                break
        return ans
```
