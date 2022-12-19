### 解题思路

* 该题的代码可以当做二分模板。另外，拎几个点。
    * python3中`1/2`会返回`0.5`，不像python2一样会自动取整。可以使用`1//2`该符号。
    * 计算中间索引时，`mid = (left + right)//2`有溢出风险，公式`mid = left + (right - left)//2`更加安全。
    * 三部分呼应：`right`从`n-1`开始；`left <= right`；`right = mid - 1`。否则要同步改成：`right`从`n`开始；`left < right`； `right = mid`。具体可参照@labuladong的[二分查找细节详解](https://leetcode-cn.com/problems/binary-search/solution/er-fen-cha-zhao-xiang-jie-by-labuladong/)。
* 二分查找的时间复杂度为O(logN)

### 代码 

```python []
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)-1
        res = -1
        while(left <= right):
            mid = left + (right - left)//2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                res = mid
                break
        return res

```