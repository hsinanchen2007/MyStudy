一、算法思路
（一）直接法
1 创建空的目标数组target。
2 从左到右顺序遍历数组nums和index,按照数组index中的值，将nums中的数插入到target中指定位置。
（二）不创建新数组的原地解法
顺序遍历index，如果index中的数值k等于其下标值j，说明nums中数值在合适位置无需调整。反之，说明nums中数值nums[j]需要放到nums中下标为k的位置，下标为k至j-1的元素后移一位。为此，用变量temp记录nums[j],逆序遍历nums[j]到nums[k+1],将相关元素赋值为其前一个元素的值，最后将nums[k]赋值为temp。
二、算法实现
```
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        # # method1
        # N = len(nums)
        # target = []
        # for i in range(N):
        #     target.insert(index[i], nums[i])
        # return target

        # method2
        N = len(nums)
        for i in range(N):
            k = index[i]
            if k != i:
                temp = nums[i]
                # nums[k+1:i+1] = nums[k:i]
                for j in range(i, k, -1):
                    nums[j] = nums[j-1]
                nums[k] = temp
        return nums
```
三 复杂度分析
（一）直接法
时间复杂度：O(N2)。遍历数组为O(N),插入操作为O(N)，故总的时间复杂度为O(N2)。
空间复杂度：O(N)。创建了数组target，空间复杂度O(N)。
（二）原地解法
时间复杂度：O(N2)。两层循环，故时间复杂度为O(N2)。
空间复杂度：O(1)。只用到了几个变量，所以空间复杂度为O(1)。
