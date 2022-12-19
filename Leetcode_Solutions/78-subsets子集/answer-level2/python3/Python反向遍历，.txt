```
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        tmp = nums[::-1]
        arr = [[]]
        for i in tmp:
            for j in range(len(arr)): # for j in arr:会陷入无限循环
                arr.append([i]+arr[j])
        return arr
```
> 参考了@wuYinIO
> 这个题蛮有意思的，可以直接从后遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集

我自己有个疑惑 为什么循环的时候for j in arr会陷入死循环而for j in range(len(arr))则不会，有人能大致解释一下这背后的机制吗，谢谢。