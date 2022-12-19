### 解题思路
此处撰写解题思路利用双端队列
力扣调了collections类利用双端队列类deque
其实利用列表即可
### 代码

```python3

class Solution:
    def maxSlidingWindow(self, nums: 'List[int]', k: 'int') -> 'List[int]':
        # base cases
        n = len(nums)
        if n * k == 0:
            return []
        if k == 1:
            return nums
        
        def clean_deque(deq,i):
            # remove indexes of elements not from sliding window
            if deq and deq[0] == i - k:
                deq.pop(0)
                
            # remove from deq indexes of all elements 
            # which are smaller than current element nums[i]
            while deq and nums[i] > nums[deq[-1]]:
                deq.pop()
            return deq
        
        # init deque and output
        deq = []
        max_idx = 0
        for i in range(k):
            deq=clean_deque(deq,i)
            deq.append(i)
            # compute max in nums[:k]
            if nums[i] > nums[max_idx]:
                max_idx = i
        output = [nums[max_idx]]
        
        # build output
        for i in range(k, n):
            deq=clean_deque(deq,i)          
            deq.append(i)
            output.append(nums[deq[0]])
        return output

```