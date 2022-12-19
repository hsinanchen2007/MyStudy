### 解题思路
需要一个能同时从头部和尾部将数字删除的list，用来储存最大值和潜在最大值的下标。
最大值下表永远在这个list的头部。

核心思想是一个双端队列，最终时间复杂度是O（n），空间复杂度是O（n）。

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []

        if len(nums) >= k and k >= 1:
            index = []

            for i in range(k):
                while len(index) != 0 and nums[i] >= nums[index[-1]]:
                    index.pop()
                    
                index.append(i)
            
            for i in range(k, len(nums)):
                result.append(nums[index[0]])

                while len(index) != 0 and nums[i] >= nums[index[-1]]:
                    index.pop()
                
                if len(index) != 0 and index[0] <= i-k:
                    index.pop(0)
                
                index.append(i)
            
            result.append(nums[index[0]])
        
        return result

```