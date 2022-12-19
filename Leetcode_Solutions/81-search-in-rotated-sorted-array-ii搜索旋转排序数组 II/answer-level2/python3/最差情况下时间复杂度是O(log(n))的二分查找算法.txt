# 考虑有三种情况
建立左右两个指针，left指向第一个元素，right指向最后一个元素，mid为(left + right) // 2
若target == nums[left] 或 target == nums[right] 或 target == nums[mid]则返回True

## 第一种情况nums[left] < nums[mid]
当数据为[3, 4, 5, 6, 7, 1, 2]，此时left指向3，right指向2，mid指向6，前半部分[3, 4, 5]有序，后半部分[7, 1, 2]无序，则若3 < target < 6， 则right = mid - 1,否则left = mid + 1

## 第二种情况nums[left] > nums[mid]
当数据为[6, 7, 1, 2, 3, 4, 5]，此时left指向6，right指向5，mid指向2，前半部分[6, 7, 1]无序，后半部分[3, 4, 5]有序，则若2 < target < 5， 则left = mid + 1,否则right = mid - 1

## 第三种情况nums[left] == nums[mid]
当数据为[1, 0, 1, 1, 1]，右半部分[1, 1, 1]，元素全为nums[mid]，此时right = mid - 1
当数据为[1, 1, 1, 0, 1]，左半部分[1, 1, 1]，元素全为nums[mid]，此时left = mid + 1
Python种检测一个列表中元素只有一种，可以用set实现，len(set(nums[left:mid])) == 1检测左半部分元素是否相同

# 总结
利用数据的特性，可以实现最差情况下时间复杂度也为O(log(n))的算法，并且空间复杂度为O(1)

```
class Solution(object):
    def search(self, nums, target):
        """
        :nums: List[int]
        :target: int
        :rtype: bool
        """
        left, right = 0, len(nums) - 1
        while left <= right:
            if nums[left] == target:
                return True
            if nums[right] == target:
                return True
            mid = (left + right) // 2
            if nums[mid] == target:
                return True
            if nums[left] < nums[mid]:
                if nums[left] < target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            elif nums[left] == nums[mid]:
                if len(set(nums[left:mid])) == 1:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if nums[mid] < target < nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return False
```