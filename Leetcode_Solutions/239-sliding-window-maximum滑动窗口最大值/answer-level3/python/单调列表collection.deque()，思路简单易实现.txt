### 解题思路
用单调列表collection.deque(),每次加入新元素时和队首元素比较，新元素更大就不断弹出队首元素，直至队列严格递增，这样每次添加新元素只需弹出队尾值即为最大。下一轮弹出第一个元素时判断其是否为队底，否则不用执行pop操作。（因为在加入新元素的时候可能已经把它弹出了）。简单易懂

### 代码

```python
from collections import deque
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        
        def push(arr,x):
            for i in range(len(arr)):
                if arr[0] < x:
                    arr.popleft()
                else:
                    break
            arr.appendleft(x)
        
        def get_max(arr):
            return arr[-1] if arr else 0
        
        def pop(arr,x):
            if arr and x == arr[-1]:
                arr.pop()
        res = []
        window = deque()
        for i in range(len(nums)):
            #填充滑动窗口
            if i < k - 1:
                push(window, nums[i])
                continue
            #将下一个元素推入窗口,此时窗口满，得到最大值加入res
            push(window, nums[i])
            res.append(get_max(window))
            #将最左边元素弹出窗口准备下一次比较
            pop(window, nums[i-k+1])
        
        return res



                    


```