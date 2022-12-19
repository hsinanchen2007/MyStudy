### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    # 排序的结果较小时，用冒泡的方法得出结果
    # 冒泡采用标记法，实际没有冒出
    flag = set()
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if k >= 10:
            return sorted(nums, reverse=True)[k - 1]
        for i in range(k):
            nums, num = self.pop_max(nums)
        self.flag.clear()
        return num    
            
    def pop_max(self, nums):
        index = 0
        while True:
            if index in self.flag:
                index += 1
            else:
                break
                
        for i in range(len(nums)):
            if i in self.flag:
                continue
            if nums[i] >= nums[index]:
                index = i
        self.flag.add(index)
        return nums, nums[index]
```