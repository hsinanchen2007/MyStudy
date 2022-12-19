## 分析
本题需要注意的是，解集中不能包含重复，但是输入中会包含重复数字。
我们把所有解集想象成一颗递归树，那么同一层的节点不能包含重复的分支，这样就能保证解集中不会存在重复。所以可以先对数据进行排序，然后再递归分支的时候，使用一个变量进行记录上一次递归的数字。
一般组合类问题需要在参数中设置一个start，由于他们不考虑顺序，所以 122 还是211对他们来说都一样。所以组合类问题总结起来就是：**排序+start参数**


## 答案
```python
class Solution:

    def __init__(self):
        self.result_all = None


    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        self.result_all = [[]]
        nums = sorted(nums)
        self.dfs(nums, 0, 0, [])
        return self.result_all

    def dfs(self, nums, n, start, result):
        if n == len(nums):
            return
        
        pre_num = None
        for i in range(start, len(nums)):
            if pre_num == nums[i]:
                continue
            pre_num = nums[i]
            result.append(nums[i])
            self.result_all.append(result[:])
            self.dfs(nums, n + 1, i + 1, result)
            result.pop()

        return
```




