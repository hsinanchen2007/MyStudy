说明:（真心不是困难的级别）

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。 

从题目要求来看，需要返回的是一个正数（不包括0）这就好理解啦 

第一：先判断1是不是在数组内，不在直接返回1

第二：遍历数组，要是发现一个数字不在nums，就直接返回(不能直接循环，还需要考虑nums为空的情况，那样只要返回1就可以了，上一步已经处理了)

第三：溢出的处理，返回最大值+1。

        class Solution:
            def firstMissingPositive(self, nums: List[int]) -> int:
                if 1 not in nums:return 1
                for i in range(1,max(nums)+1):
                    if i not in nums:
                        return i
                return max(nums)+1