
```
class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        length = len(nums)
        if length <= 2:
            return False
        else:
            mininum = mid = 1e10
            for i in range(length):
                if nums[i] <= mininum:
                    mininum = nums[i]
                elif nums[i] <= mid:
                    mid = nums[i]
                else:
                    return True
            return False
```

假设现在已经遍历了序列nums中的k个数，准备遍历第k+1个数，第k个数里面的mininum和mid保证了包括k在内的，从序列开始
到k之间的所有数都在mininum和mid这个范围之内，说明已经存在一个长度为2的递增序列了，我们对于这个序列的具体范围
并不感兴趣，此时只要k+1大于mid，则可以找到长度为3的递增子序列，否则更新在k+1之前的所有值的新的范围