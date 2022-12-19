看本题解时，建议先看下[双指针经典题目的经典解法，适合新手小白！](https://leetcode-cn.com/problems/max-consecutive-ones/solution/shuang-zhi-zhen-jing-dian-ti-mu-de-jing-dian-jie-f/)，一起服用效果更佳！

看了上面链接的介绍，本题其实唯一难点就是当慢指针更新的条件被触发时的业务逻辑了。

如果没有额外空间的限制，最直观的方法是新建一个数组`rst`，
慢指针`j`更新触发条件是`nums[i]==val`,
触发后业务代码`rst.extend(nums[j+1:i])`，即将这个无val的片段添入rst
然后更新j: `j=i`
最后结果返回rst:
```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        j = nums.index(val) if val in nums else len(nums) ## 套路代码：初始化慢指针
        rst = []
        for i in range(j+1,len(nums)): ## 套路代码：初始化快指针
            if nums[i]==val: ## 套路代码：慢指针更新的触发条件
                rst.extend(nums[j+1:i]) ## 业务代码
                j=i ## 套路代码：更新慢指针
        return rst
```
题目要求就地修改，触发条件`nums[i]==val`的触发次数太少，值肯定修改不对。
而是`nums[i]!=val`，这样就可以一直触发，修改值了。
这里的思考过程可能写的不清楚，见谅~
```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        j = nums.index(val) if val in nums else len(nums) ## 套路代码：初始化慢指针
        for i in range(j+1,len(nums)): ## 套路代码：初始化快指针
            if nums[i]!=val: ## 套路代码：慢指针更新的触发条件
                nums[j] = nums[i] ## 业务代码
                j += 1 ## 套路代码：更新慢指针
        return j
# 执行用时 :36 ms, 在所有 Python3 提交中击败了99.55%的用户
# 内存消耗 :13.7 MB, 在所有 Python3 提交中击败了5.37%的用户
```
是不是感觉豁然开朗！其实本题套用快慢双指针套路不是难点，难点是原地修改的业务逻辑。