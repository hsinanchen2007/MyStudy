## 思路
+ 看到这道题很容易想到使用二分查找
+ 但是难点在于，不仅要找到这个值的下标，还要找起始下标和终结下标
+ 其实单纯使用两个二分查找即可，一个找起始下标，一个找最终下标
+ 你可能会疑惑，这样会不会造成太多冗余计算？
+ 但实际上，`O(logn)`和`O(2logn)`是相等的，都是`O(logn)`的时间复杂度。
+ 所以使用两次二分查找的方式可以减少你的思考方式，同时不会增加复杂度。
## 二分查找细节
+ 首先初始化l,r，左右指针
+ 循环条件设为当l<r，这样设立的原因是跳出循环的时候l与r总是相等的，不用思考是l还是r
+ 取中值，取中左还是中右，这就需要看情况了。
+ 如果我们想要找值的起始下标，那么当mid对应值大于这个值或者哪怕当找到这个值的时候，右边界都要缩小
+ 即当`nums[mid] >= target`的时候，`r = mid`
+ 同时要注意不能以mid-1这样的形式缩小，否则当找到这个起始下标的时候还得再减1,就不对了。
+ 因为不可以左右两个都=mid，必须有一个=mid+1,否则会陷入死循环。
+ 所以在其他情况下，左边界等于mid + 1
+ 同时，mid取左中还是右中，要以你选择哪个是mid+1来定。这里我们选了mid+1的是左边，所以我们要取左中值。否则会陷入死循环。
+ 所以可以这样写出代码
```python
    while l < r:
        mid = (l + r) // 2
        if nums[mid] >= target:
            r = mid
        else:
            l = mid + 1
```
+ 对于取结束下标，也是如此。
## 代码
```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # 取起始下标
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1

        # 没找到
        if not nums or nums[l] != target:
            return [-1,-1]
        
        # 取结束下标
        a, b = l, len(nums) - 1
        while a < b:
            mid = (a + b + 1) // 2
            if nums[mid] <= target:
                a = mid
            else:
                b = mid - 1
        
        return [l,a]
```