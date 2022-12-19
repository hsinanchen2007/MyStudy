python3小白答案，力扣第一道题，欢迎大佬评论

速度不快，但写起来简单，两层循环，返回所有nums[i] + nums[j] == target的[i,j]

 小白的疑问，力扣上直接def会报错说30多行Solution没有定义（没class代码只有6行啊），而且下面的代码复制到pycharm也会报错（list没有定义），是怎么回事啊。

执行用时 :6540 ms, 在所有 Python3 提交中击败了8.04%的用户
内存消耗 :14.3 MB, 在所有 Python3 提交中击败了24.09%的用户
### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lens = len(nums)
        for i in range(0, lens - 1):
            for j in range(i + 1, lens):
                if nums[i] + nums[j] == target:
                    return [i, j]

```