1、定义两个函数：search_lower,用于查找下边界指针；search_upper,用于查找上边界指针；
2、search_lower里，先判断first与last的大小，如果first比last大，说明给定区间不合法或者已经完全搜索过没找到target值，否则，找中点，判断是否是target值，如果是，判断mid是否为0或者nums[mid-1] < nums[mid]，是则直接返回，否则递归调用。
3、找上边界是同样的做法，只是if里条件有些变动。
```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def search_lower(first, last, target):
            if first > last:
                return -1
            mid = first + (last - first) // 2
            if nums[mid] == target and (mid == first or nums[mid] > nums[mid-1]):
                return mid
            elif nums[mid] >= target:
                return search_lower(first, mid - 1, target)
            else:
                return search_lower(mid+1, last, target)
        
        def search_upper(first, last, target):
            if first > last:
                return -1
            mid = first + (last - first) // 2
            if nums[mid] == target and (mid == last or nums[mid] < nums[mid+1]):
                return mid
            elif nums[mid] > target:
                return search_upper(first, mid - 1, target)
            else:
                return search_upper(mid+1, last, target)
        
        if not nums:
            return [-1,-1]
        n = len(nums)-1
        first = search_lower(0, n, target)
        if first == -1:
            last = -1
        else:
            last = search_upper(0, n, target)
        return [first, last]
        
```
