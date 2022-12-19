### 字典法(哈希)
![image.png](https://pic.leetcode-cn.com/96cfe858db5c46ebb07a3e8de38c2b6791e39678aa948bd11c9719a41a5484fd-image.png)
- 用字典存储已经遍历的数字,如果`target - i`在字典中,则直接返回`[i, target-i]]`,i为当前遍历到的数字.
- 时间复杂度`O(n)`,空间复杂度`O(n)`

### 代码
```
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums or len(nums) == 1:
            return []
        dic = {}
        for i in nums:
            if (target - i) in dic:
                return [i, target-i]
            dic[i] = 0
        return []



```

### 双指针
![image.png](https://pic.leetcode-cn.com/5ff6d68403bddda78c025be96cb4945f6c30cd218a2acebb9be631eef7ce27ac-image.png)
- 拿到题目后,直接冲入大脑的思路可能是先固定一个数,在依次判断其余的`n-1`个数与它的和是否等于`s`,这种做法不难想到,但是时间复杂度为`O(n**2)`,这样的思路可能不是面试官喜欢的
- 下面介绍一种使用双指针的策略,我们设定一头一尾两个指针,一个指针`low`指向数组的开头,一个指针`high`指向数组的末尾,设置`sum_ = nums[low] + nums[high]`
- 当`sum_ == target`时,则就返回现在这两个数字即可
- 当`sum_ > target`时,则需要减小`sum_`,由于数组是递增排序的,所以我们要将`high`向前移,`high -= 1`
- 当`sum_ < target`时,则需要增大`sum_`,由于数组是递增排序的,所以我们要将`loe`向后移,`low += 1`
- 此方法的时间复杂度为`O(n)`,空间复杂度`O(1)`
### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums or len(nums) == 1:
            return []
        low = 0
        high = len(nums)-1
        while low < high:
            sum_ = nums[low] + nums[high]
            if sum_ == target:
                return [nums[low], nums[high]]
            if sum_ > target:
                high -= 1
            else:
                low += 1
        return []

```