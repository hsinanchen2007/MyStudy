### 解题思路
搜索问题 + 有序数组 首先就要想到二分法，哪怕没有提示时间复杂度是O(logn)也应该有这种意识。讲一下这道题思路：
以搜索左区间为例：
（1）对于普通二分法当我们发现`nums[mid] == target`我们就可以`return mid`了，但是这道题显然需要另做处理，因为当我们发现该条件时无法确定mid指针左边是否还有target所以需要进一步缩小区间，关于缩小区间问题我想强调一下，区间缩小有两种方法：`right = mid`和`right = mid - 1`，这里我选择`left = mid - 1`，原因是为了避免死循环，因为有可能出现`left == mid`（说是有可能是因为这和mid的计算方法有关，但是不管哪种方法在求左区间或者右区间的时候总有一个会出现死循环）。
（2）当我们使用如上的更新方法以后，实际上只需要判断`nums[left]`即可，这里举个例子就知道了。

### 代码

```python
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if nums == []:
            return [-1, -1]
        num1 = self.half_search_1(nums, target)
        if num1 == -1:
            return [-1, -1]
        num2 = self.half_search_2(nums, target)
        return [num1, num2]

    def half_search_1(self, nums, target):
        left, right = 0, len(nums) - 1
        mid = (left + right) // 2
        while left <= right:
            if nums[mid] == target:
                right = mid - 1
            elif target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
            mid = (left + right) // 2
        if left < len(nums) and nums[left] == target:
            return left
        else:
            return -1
                
    def half_search_2(self, nums, target):
        left, right = 0, len(nums) - 1
        mid = (left + right) // 2
        while left <= right:
            if nums[mid] == target:
                left = mid + 1
            elif target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
            mid = (left + right) // 2
        if right > -1 and nums[right] == target:
            return right
        else:
            return -1
```