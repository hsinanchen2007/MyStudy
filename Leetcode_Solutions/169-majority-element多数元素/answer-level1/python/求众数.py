最抖机灵的一种办法：因为众数肯定超过了整个数列的一半
所以最快的办法就是：1.先排序 2.取中位数
假设有10000个元素，所以众数必须要有至少5001个，所以中位数（向上取整）必是众数。
```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        
        return nums[len(nums)/2]
```

执行用时 :
28 ms, 在所有 Python 提交中击败了 98.79% 的用户

内存消耗 :
12.7 MB , 在所有 Python 提交中击败了 100.00% 的用户