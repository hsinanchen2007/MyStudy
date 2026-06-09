
### 1. 暴力求解
基本思路就是遍历一遍，用两个变量，一个记录最大的和，一个记录当前的和。时空复杂度貌似还不错......（时间复杂度 $O(n)$，空间复杂度 $O(l)$）
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        tmp = nums[0]
        max_ = tmp
        n = len(nums)
        for i in range(1,n):
            # 当当前序列加上此时的元素的值大于tmp的值，说明最大序列和可能出现在后续序列中，记录此时的最大值
            if tmp + nums[i]>nums[i]:
                max_ = max(max_, tmp+nums[i])
                tmp = tmp + nums[i]
            else:
            #当tmp(当前和)小于下一个元素时，当前最长序列到此为止。以该元素为起点继续找最大子序列,
            # 并记录此时的最大值
                max_ = max(max_, tmp, tmp+nums[i], nums[i])
                tmp = nums[i]
        return max_
        
```
### 2. 分治法

书刚看完......
分治法其他题解里将的很清楚了。其实就是它的最大子序和要么在左半边，要么在右半边，要么是穿过中间，对于左右边的序列，情况也是一样，因此可以用递归处理。中间部分的则可以直接计算出来，时间复杂度应该是 $O(nlogn)$。代码如下：
```Python []
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        #递归终止条件
        if n == 1:
            return nums[0]
        else:
            #递归计算左半边最大子序和
            max_left = self.maxSubArray(nums[0:len(nums) // 2])
            #递归计算右半边最大子序和
            max_right = self.maxSubArray(nums[len(nums) // 2:len(nums)])
        
        #计算中间的最大子序和，从右到左计算左边的最大子序和，从左到右计算右边的最大子序和，再相加
        max_l = nums[len(nums) // 2 - 1]
        tmp = 0
        for i in range(len(nums) // 2 - 1, -1, -1):
            tmp += nums[i]
            max_l = max(tmp, max_l)
        max_r = nums[len(nums) // 2]
        tmp = 0
        for i in range(len(nums) // 2, len(nums)):
            tmp += nums[i]
            max_r = max(tmp, max_r)
        #返回三个中的最大值
        return max(max_right,max_left,max_l+max_r)
```
### 3. 动态规划
我去看看书......

第一种暴力法好像就用到了 DP 的思想（后面的懒得写了，已经有其他大神有更好的方案）。
1. 可以从第一个数开始向后扫描，找到最大的和，再从第二个数开始向后扫描，找到最大的和......，依次进行下去，用一个数组存储这些值，其中最大的就是所需的答案（其实这种方法就是暴力不能再暴力的动态规划？），时间复杂度 $O(n^2)$，空间复杂度 $O(n)$；
2. 或者，直接在原数组上记录最大的子序和，时空复杂度非常好，就是改变了原数组。基本的思路跟第一种 ‘暴力法’ 类似，就是一次遍历，从左到右记录最大子序和，只不过要找准当前最大子序和与前一最大子序和的关系（如果前一最大子序和大于 0，则是当前元素值加上前一最大子序和，反之，则不变，继续遍历），最后再找出数组中的最大值。时间复杂度 $O(n)$， 空间复杂度 $O(l)$。


如有建议，请指出，谢谢。如有疑问请评论区评论，共同探讨！