1. 包含重复元素会影响到程序的时间复杂度，因采取的是二分的方法, O(log2n)~O(n)
2. 多了一个条件判断的区别
3. 下面的程序用RUN来进行递归控制
```
class Solution:
    RUN = True

    def search(self, nums: List[int], target: int) -> bool:
        """
            搜索旋转排序数组

            假设按照升序排序的数组在预先未知的某个点上进行了旋转。
            ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
            编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
        """
        i, j = 0, len(nums) - 1
        if nums and self.RUN:
            in_middle = (j + i) // 2
            list1 = nums[:in_middle + 1]
            list2 = nums[in_middle + 1:]
            if nums[in_middle] > nums[i]:
                res = self.binarySearch(list1, target)
                if res == -1:
                    return self.search(list2, target)
                else:
                    return True
            elif nums[in_middle] == nums[i]:
                if nums[i] == target:
                    return True
                elif list1.count(nums[i]) == len(list1):
                    return self.search(list2, target)
                else:
                    return self.search(list1, target)
            else:
                res = self.binarySearch(list2, target)
                if res == -1:
                    return self.search(list1, target)
                else:
                    return True

        if not self.RUN:
            return True
        return False

    def binarySearch(self, nums, target):
        """ 二分查找 """
        i, j = 0, len(nums) - 1
        while i <= j:
            in_middle = (j + i) // 2
            if nums[in_middle] == target:
                self.RUN = False
                return in_middle
            elif nums[in_middle] < target:
                i = in_middle + 1
            else:
                j = in_middle - 1

        return -1
```