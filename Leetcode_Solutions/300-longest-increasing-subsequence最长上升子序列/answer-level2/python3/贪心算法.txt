```

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        
        ans = [nums[0]]

        for i in range(1, n):
            if nums[i] > ans[len(ans) - 1]:
                ans.append(nums[i])
            else:
                for j in range(len(ans)):
                    if nums[i] <= ans[j]:
                        # print('before: %s' % ans)
                        ans[j] = nums[i]
                        # print('after: %s' % ans)
                        break
        
        return len(ans)

```
