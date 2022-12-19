如果是排好序的数组，用双指针的方法更好，但是探索的二分查找里有这题，我就试着写了下，好像很麻烦，没想出来简单的二分查找方法，记录一下思考过程
思路：
1. 对排好序的数组nums1 = [4,5,9]，nums2 = [4,4,8,9,9]，
2. 遍历nums2中的元素，用二分查找找到每个元素在nums1中出现的第一个位置，
3. 如果找到了，用二分查找找下一个元素的时候left从这个位置的下一位开始；
   如果没找到，用二分查找找下一个元素的时候left还是从这个位置开始。
   举个例子：
   nums2的第一个元素4在[4,5,9]中进行二分查找后的left = 0，下一次二分查找的left就从0 + 1开始；
   nums2的第二个元素4在[5,9]中进行二分查找，因为不存在，所以下一次二分查找的left就继续从1开始；
   nums2的第三个元素8继续在[5,9]中进行二分查找...
时间复杂度：O(nlogn + mlogm)，排序的复杂度
空间复杂度：最差情况O(min(m,n))

```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        # 排序
        nums1.sort()
        nums2.sort()
        n = len(nums1)
        index = 0
        for target in nums2: 
            if index == n:  
                break
            left = index
            right = n - 1
            # 二分查找
            while left < right:
                mid = left + (right - left) // 2
                if nums1[mid] < target:
                    left = mid + 1
                else:
                    right = mid
            # nums2中的元素在nums1中找到了下一次二分查找的左边界就加一
            # 没找到下一次二分查找的左边界就还是现在的左边界
            if nums1[left] == target:
                index = left + 1     
                res.append(target)
        return res
```
