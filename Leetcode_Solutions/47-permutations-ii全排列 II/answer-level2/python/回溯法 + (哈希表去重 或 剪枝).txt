### 解题思路

本问题在 [46. 全排列](https://leetcode-cn.com/problems/permutations/) 的基础上增加了一些条件. 本篇解题思路和 46 题没有本质的区别, 关键在于如何对排序结果进行去重, 下面提供两种方法.

![Screen Shot 2020-02-05 at 4.59.12 PM.png](https://pic.leetcode-cn.com/c6e9de4f363be151ff844af32187952136c9c1ff1ff612deddab3a997c62383f-Screen%20Shot%202020-02-05%20at%204.59.12%20PM.png)


### 解法一 回溯法 + 哈希表去重

说到去重最容易相当的就是哈希表了. 下面的程序采用了和 46 题一模一样的回溯法来解决问题, 将找到的结果放入哈希表中实现去重, 最后返回哈希表值的集合即可.

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = {}

        def backtrack(nums: List[int], permute: List[int]):
            if not nums:
                res[','.join([str(x) for x in permute])] = permute
                return
            for i, x in enumerate(nums):
                backtrack(nums[:i] + nums[i + 1:], permute + [x])

        backtrack(nums, [])
        return res.values()
```


### 解法二 回溯法 + 剪枝

虽然利用哈希表能够达到去重的目的, 但是这种方法使我们对那些重复的排列做了多余的遍历, 浪费了计算资源, 是否有可能更早发现重复并规避多余的遍历呢?

**这是可以做到的**. 首先, 我们需要先对输入的数组进行排序之后再进行遍历, 当我们发现迭代中的某个数字和它的前一个元素相等, 说明当前分支最终产生的结果和前一个的结果也会是完全一样的, 所以我们可以直接跳过对当前元素子集的探索, 从而减少了计算量.

![Screen Shot 2020-02-05 at 4.31.09 PM.png](https://pic.leetcode-cn.com/55c0c993d324edd251b037b340ae7ff6e714bbae2cc75ba132d87e91fad157a3-Screen%20Shot%202020-02-05%20at%204.31.09%20PM.png)

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(nums: List[int], permute: List[int]):
            if not nums:
                res.append(permute)
                return
            prev = None
            for i, x in enumerate(nums):
                if x == prev:
                    continue
                backtrack(nums[:i] + nums[i + 1:], permute + [x])
                prev = x

        backtrack(sorted(nums), [])
        return res
```