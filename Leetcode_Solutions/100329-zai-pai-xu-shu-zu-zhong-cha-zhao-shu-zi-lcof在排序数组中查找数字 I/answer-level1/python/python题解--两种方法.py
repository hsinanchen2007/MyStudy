### 直接遍历
![image.png](https://pic.leetcode-cn.com/5173406dd0c6fcbff8025c0e1c1247f63955ba11c459d1bca2098935015f41f7-image.png)

- 直接遍历即可,统计出现的个数
- 时间复杂度`O(n)`,空间复杂度`O(1)`

### 代码

```python
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        result = 0
        for i in nums:
            if i == target:
                result += 1
        return result
```
### 二分法
![image.png](https://pic.leetcode-cn.com/eef9a04641f565724f730fb2fa9eb532eed8b6db02e066543674e3ef4da830ba-image.png)

- 使用二分法查找出`target`在数组中出现的第一个位置和最后一个位置,有了位置直接相减加一就是我们要找的数目
- 二分法的思路相信大家已经很清楚了,需要注意的是,当遍历到`nums[mid] == target`时,对于我们要找的第一个位置时,需要判断`nums[mid-1]`是否等于`target`,如果`nums[mid-1] != target`说明`mid`的位置就是第一个位置,如果`nums[mid-1] == target`则说明第一个还在`mid`的前面,`end = mid - 1`
- 在求最后一个位置时,当遍历到`nums[mid] == target`时,需要判断`nums[mid+1]`是否等于`target`,如果`nums[mid+1] != target`说明`mid`的位置就是最后一个位置,如果`nums[mid-1] == target`则说明第一个还在`mid`的后面面,`start = mid + 1`
- 时间复杂度`O(logn)`,空间复杂度`O(1)`

### 代码 
```
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        length = len(nums)
        if nums and length > 0:
            first = self.getFirstK(nums,length, target, 0, length-1)
            last = self.getLastK(nums,length, target, 0, length-1)
            if last > -1 and first > -1:
                return last - first + 1
        return 0
    
    def getFirstK(self, nums, length, target, start, end):
        if start > end:
            return -1
        mid = (start + end) / 2
        if nums[mid] == target:
            if (mid > 0 and nums[mid-1] != target) or mid == 0:
                return mid
            else:
                end = mid - 1
        elif nums[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
        return self.getFirstK(nums, length, target, start, end)   


    def getLastK(self, nums, length, target, start, end):
        if start > end:
            return -1
        mid = (start + end) / 2
        if nums[mid] == target:
            if (mid < length - 1 and nums[mid + 1] != target) or mid == length -1:
                return mid
            else:
                start = mid + 1
        elif nums[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
        return self.getLastK(nums, length, target, start, end)   



```
