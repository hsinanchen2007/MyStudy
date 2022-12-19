```python
### 这道题要格外注意的一点是，滑动的时候，需要删除前面所有小于当前值的点。但是初始化时，只需要删除最大值前面的点
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue = list(range(k))

        res = [max(nums[:k])]

        while queue and nums[queue[0]] < res[0]:
            queue.pop(0)
        
        for i in range(k,len(nums)):
            if queue and queue[0] <= i-k:
                queue.pop(0)
            
            for j in range(len(queue)-1,-1,-1):
                if nums[queue[j]] < nums[i]:
                    queue.remove(queue[j])
            queue.append(i)
            res.append(nums[queue[0]])
        return res

```