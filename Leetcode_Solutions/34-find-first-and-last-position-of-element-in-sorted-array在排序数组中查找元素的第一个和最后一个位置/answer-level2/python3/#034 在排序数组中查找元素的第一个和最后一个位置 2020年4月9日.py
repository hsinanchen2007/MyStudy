### 解题思路
1.二分查找到一个target后，向左向右遍历
2.二分查找本身就可以做到查找右边界、左边界
对于二分查找参见：
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/
a.查找一个元素 b.查找左边界 c.查找右边界
查找区间

a.查找一个元素：
查找区间[a, b] => 初始化 a, b = 0, lens-1

b.查找左边界
查找区间[a, b) => 初始化 a, b = 0, lens


### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        #二分查找可以做到查找左边界与右边界
        lens = len(nums)
        if lens == 0:
            return [-1, -1]
        a, b = 0, lens-1
        while b>a:
            mid = (a+b)//2
            if target == nums[mid]:
                b = mid
            elif target > nums[mid]:
                a = mid + 1
            elif target < nums[mid]:
                b = mid - 1
        res1 = a if nums[a] == target else -1

        a, b = 0, lens-1
        while b>a:
            mid = (a+b)//2+1
            if target == nums[mid]:
                a = mid
            elif target > nums[mid]:
                a = mid + 1
            elif target < nums[mid]:
                b = mid - 1
        res2 = b if nums[b] == target else -1

        return [res1, res2]


        # 直接的想法：二分查找，找到target之后向左向右寻找相同元素(愚蠢)
        """
        lens = len(nums)
        a = 0
        b = lens-1
        res = -1
        while b>=a:
            mid = (a+b)//2
            if target == nums[mid]:
                res = mid
                break
            elif target > nums[mid]:
                a = mid+1
            else:
                b = mid-1
        
        if res == -1:
            return [-1, -1]
        else:
            j, k = res, res
            for i in range(res, lens):
                if nums[i] == target:
                    j = i
            for i in range(res, -1, -1):
                if nums[i] == target:
                    k = i
            return [k, j]
        """

```