### 解题思路
首先对`candidates`进行排序，这样可以方便在遍历candidates时如果出现连续相等的值，可以在回溯树中同层去重。

回溯函数的输入为
1. 剩余没加上的元素
2. 已加的元素组成的类别
3. 已加元素的和

回溯终止条件：
1. 和大于`target`：剪枝(return)
2. 和等于`target`：存下结果，return

和小于`target`时，递归调用回溯函数，**注意如果出现连续两个相等的元素，`continue`，回溯树同层去重**


### 代码

```python3
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def recur(nums, temp, he):
            if he > target:
                return
            if he == target:
                res.append(temp)
                return
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1]:
                    continue
                recur(nums[i+1:],temp+[nums[i]], he+nums[i])
        res = []
        candidates.sort()
        recur(candidates, [], 0)
        return res

```