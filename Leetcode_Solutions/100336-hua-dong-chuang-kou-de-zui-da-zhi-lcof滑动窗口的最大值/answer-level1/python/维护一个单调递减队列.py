思路：
为什么要维护一个单调递减队列
1. 为了避免在每次窗口移动时重新遍历窗口的元素。我们需要充分利用前面的窗口的最大值信息来推导出当窗口移动一格时的最大值变化。
2. 只保存前面的窗口的最大值信息显然不够，因为当前面窗口最大值位置处于当前窗口边界外，我们无法利用前面的窗口最大值在O（1）时间推导出当前窗口的最大值



```python

        deque = collections.deque()
        res = []
        for i in range(len(nums)):
           
            
            # 保证每次加入元素都保持队列单调递减
            while deque and nums[deque[-1]] <= nums[i]:
                deque.pop()
            deque.append(i)
            
            # 队列的最大值以及当前窗口边界，弹出，此时队列队首又变成了当前窗口的最大值
            if deque[0] < i - k + 1:
                deque.popleft()
            if i >= k-1:
                res.append(nums[deque[0]])
        return res
```
