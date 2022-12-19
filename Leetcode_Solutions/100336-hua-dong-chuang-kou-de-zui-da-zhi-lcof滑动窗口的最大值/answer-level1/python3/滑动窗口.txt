```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        from collections import deque
        if k == 0: return []
        if not nums: return []
        ans = deque()
        ind = deque()
        co = 0
        while co < k:
            while ans and nums[co] > ans[-1]: 
                ans.pop()
                ind.pop()
            ans.append(nums[co])
            ind.append(co)
            co +=1
        res =[ans[0]]
        c = 0
        for i in range(k, len(nums)):
            
    
            if ind[0] == c:
                ans.popleft()
                ind.popleft()
            c+=1
           
            while ans and nums[i] > ans[-1]: 
                ans.pop()
                ind.pop()
            ans.append(nums[i])
            ind.append(i)
            res.append(ans[0])
        return res


```
