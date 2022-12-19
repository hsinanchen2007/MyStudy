### 解题思路
与**46**题解类似，差别在于多了去重这一步骤，在结果中去重

### 代码

```python
class Solution(object):
    def permuteUnique(self, nums):
        self.ans = []
        self.visit = [0] * len(nums)
        temp = []
        self.que(nums,temp)
        self.ans = list(set(map(tuple,self.ans)))
        self.ans = list(map(list,self.ans))
        return self.ans

    def que(self,nums,temp):
        if len(nums) == 0:
            self.ans.append(temp[:])
        for i in range(len(nums)):
            #表示从这个数开头
            self.visit[i] = 1
            temp.append(nums[i])
            #以nums[i]开头的排列情况取决于剩余数组的排列情况
            num_copy = [nums[j] for j in range(len(nums)) if j != i]
            self.que(num_copy,temp)
            temp.pop()
            #取消标记
            self.visit[i] = 0
```