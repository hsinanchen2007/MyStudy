### 解题思路
这道题如果没有那么多限制那么解法有很多，比如哈希表、排序、利用数值限制本地交换位置等。
但是由于有太多的限制，主要是不允许改变数组而且要求O(1)的空间复杂度，就应该想到不能用常规的方法了。
二分法变形的思路是给定一个值，查找数组中大于或者小于这个值的数量（抽屉原理），进而进一步缩小查找空间，直到left == right。
时间复杂度分析：需要logn次循环，每次循环遍历n个元素所以时间复杂度是O(nlogn)的。
还有一点需要提醒的是：在区间的选取建议按照下面的划分[left, mid]和[mid + 1, right]，这样在区间更新的时候，不会出现死循环，因为如果是[left, mid - 1]和[mid, right]，那么代码中对于left的更新就是left = mid，当只剩两个元素的时候，如果进入这个更新的话就一直是left == mid死循环。

### 代码

```python
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 1, len(nums) - 1 # 分别对应1和n
        mid = (left + right) // 2
        while left < right:
            cnt = 0
            for num in nums:
                if num >= left and num <= mid:
                    cnt += 1
            if cnt > mid - left + 1:
                right = mid
            else:
                left = mid + 1
            mid = (left + right) // 2
        return mid
```