![image.png](https://pic.leetcode-cn.com/5e9080ba7c4f1cf5b0075f75cfa4bdb1e7c33b293fe70f3a260606c8d29a131a-image.png)
起初不太明白为什么这个题目是动态规划问。后来想到，如果每次求一个区间都要重新计算的话，复杂度比较高，可能存在很多重复计算。
如果求得 0-j 的和，每次计算只需要用 0-j 的和减去 0-i 的和，因为区间是闭区间，因此还要加上 i 的值。
先写了一个每次都重新计算的——超时了
考虑用空间替换时间，写一个数组保存 `0-每一个数` 的值
```
class NumArray(object):
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums
        self.sum_array = []
        tmp = 0
        for num in self.nums:
            tmp += num
            self.sum_array.append(tmp)

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sum_array[j]-self.sum_array[i]+self.nums[i]
```
