双端队列。建队列和更新队列都属于双端队列的push和pop操作，只不过建立的时候只有push，而更新的时候（本题中）包含一次push和一次pop，因此将这两个函数写出来就可以了。
```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        stack = []
        res = []
        def pushQueue(n): # 双端队列的push操作
            while stack and nums[n] >= nums[stack[-1]]:
                stack.pop()
            stack.append(n)
        def popQueue(n): # 双端队列的pop操作
            if n == stack[0]:
                stack.pop(0)
        for i in range(k): # 建立队列的过程
            pushQueue(i)
        res.append(nums[stack[0]]) # 前k个数的最大值
        for i in range(k, len(nums)): 从第k+1个数开始更新
            popQueue(i - k)
            pushQueue(i)
            res.append(nums[stack[0]])
        return res
```
