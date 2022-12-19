循环四步
```python []
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue, output = collections.deque([]), []
        
        for i in range(len(nums)):
            #1 把队列里比当前数小的顶出去。
            while queue and nums[i] >= nums[queue[-1]]:
                queue.pop()
            #2 把当前数(下标)放入队列
            queue.append(i)
            #3 队列里有足够多数，就开始输出
            if i+1 >= k :
                output.append(nums[queue[0]])
            #4 队列的数为窗口大小K时，把队列头部元素移除
            if i+1-k == queue[0]:
                queue.popleft()
        return output
                

