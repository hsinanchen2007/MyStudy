```python
class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = [-float('inf')]*3
        for i in nums:
            if i>= ans[0]:
                if i == ans[0]:
                    continue
                ans[1:]=ans[0:2] #后面不可以ans[0:]
                ans[0] = i
            elif i>=ans[1]:
                if i == ans[1]:
                    continue
                ans[2:]=ans[1:2]
                ans[1] = i
            elif i> ans[-1]:
                ans[-1] =i
        print(ans)
        if ans[-1]== -float('inf'):
            return ans[0]
        else:
            return ans[-1]
```
