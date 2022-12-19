### 解题思路
**回溯算法**

### 代码

```python
class Solution(object):
    def permute(self, nums):
        self.ans = []
        self.visit = [0] * len(nums)
        temp = []
        self.que(nums,temp)
        return self.ans

    def que(self,nums,temp):
        if len(nums) == 0:
            self.ans.append(temp[:])
        for i in range(len(nums)):
            #表示从这个数开头
            self.visit[i] = 1
            temp.append(nums[i])
            #以nums[i]开头的排列情况取决于剩余数组的排列情况
            num_copy = [n for n in nums if n != nums[i]]
            self.que(num_copy,temp)
            temp.pop()
            #取消标记
            self.visit[i] = 0
    
```