首先对整个数组进行排序，其次遍历所有的$i$，在$i$固定时，$j$从左往右扫描，而$k$从右往左扫描，直到$j=k$结束。

这道题将三个数的和问题转化成为了两个数的和问题。而两个数的和问题可以在$O(nlogn)$的时间内解决。

整道题目的代码如下：

```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = set()
        nums.sort()

        for i in range(len(nums) - 2):
            num = -nums[i]
            j = i + 1
            k = len(nums) - 1

            while j != k:
                sum = nums[j] + nums[k]
                if sum == num:
                    res.add((nums[i], nums[j], nums[k]))
                    j = j + 1
                elif sum < num:
                    j = j + 1
                else:
                    k = k - 1

        return list(res)
```

