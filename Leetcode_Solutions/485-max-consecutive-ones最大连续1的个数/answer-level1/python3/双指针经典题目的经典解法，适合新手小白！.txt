双指针算是数组里比较基础的算法套路，其实就是两种，头尾双指针和快慢双指针。本题用到快慢双指针。

其基本原理，就是 i 在前头遍历一直走`for i in range(length)`，
j 在后头符合业务逻辑时走一下`if something is True: do something; update j`。

具体到代码套路就是：

1. 初始化慢指针j, 本例中是`j = nums.index(0) if 0 in nums else len(nums)`

2. 初始化快指针i，本例中是`for i in range(j+1,len(nums))`
    如需要，初始化结果值，本例是`_max = sum(nums[:j])`

3. 构造慢指针更新的触发条件，本例中是`if i == len(nums)-1 or nums[i]==0:`
    如需要，执行业务代码，本例是`_max = max([_max, sum(nums[j:i+1])])`

4. 执行慢指针(及结果值)更新逻辑，本例中是`j=i`

结合本题代码：
```
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:

        j = nums.index(0) if 0 in nums else len(nums) ## 基本套路：初始化慢指针
        _max = sum(nums[:j]) ## 业务代码：初始化结果，根据题目来

        for i in range(j+1,len(nums)): ## 基本套路：可以理解为初始化快指针
            if i == len(nums)-1 or nums[i]==0: ## 基本套路：构造慢指针更新的触发条件
                _max = max([_max, sum(nums[j:i+1])]) ## 业务代码
                j = i ## 基本套路：慢指针更新

        return _max ## 基本套路：返回结果

# 执行用时 :456 ms, 在所有 Python3 提交中击败了74.17%的用户
# 内存消耗 :14.1 MB, 在所有 Python3 提交中击败了5.14%的用户
```
是不是很好理解呢！