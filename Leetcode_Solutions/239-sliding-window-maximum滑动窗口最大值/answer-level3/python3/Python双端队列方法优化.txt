### 解题思路
官方的双端队列python方法优化了一下

### 代码

```python3
class Solution:
    # 优化了官方题解，用双端队列
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return []

        length = len(nums)
        if length == 1:
            return nums
        
        def clean_queue(i):
            # 如果刚好把最大值经过去了
            if queue and i - k == queue[0]:
                queue.pop(0)
            # 把所有比自己小的全pop，这样子queue就存放着nums从大到小排列的index
            while queue and nums[i] > nums[queue[-1]]:
                queue.pop(-1)

            queue.append(i)

        queue = []
        output_list = []

        for i, ele in enumerate(nums):
            clean_queue(i)
            output_list.append(nums[queue[0]])
        return output_list[-(length-k+1):]

  
```