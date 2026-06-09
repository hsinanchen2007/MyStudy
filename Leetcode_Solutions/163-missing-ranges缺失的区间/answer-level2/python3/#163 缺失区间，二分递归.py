### 解题思路
最直接的方法是一次遍历，比较lower和当前元素，添加缺失区间并更新lower（lower小于当前元素时，添加lower到nums[i]-1区间，等于时只更新lower=nums[i]+1，大于时continue）。

尝试优化时间复杂度，对有序数组始终可以考虑能不能转化为log(n)。
考虑二分查找，将数组始终从中间分开递归调用函数，左边的数组为nums[:mid]，不包含mid，所以upper为nums[mid] - 1，右边的数组为剩下的一半nums[mid:]，lower为nums[mid]本身。利用数组加法将两边的返回值拼接。

现在唯一的问题就是递归的base case，考虑空数组和包含1个元素的数组：
1. 空数组直接返回上下界区间
2. 包含一个元素的数组，比较元素和上下界（最多会更新两个区间，最少不会更新）：
    * 如果lower小于nums[0]就需要更新[lower, nums[0] - 1];
    * 如果upper大于nums[0]就需要更新[numsg[0] + 1, upper]。

其实在二分的过程是不会分到空数组的，因为两个元素的数组会分为两个一个元素的数组，一个元素的数组会直接返回结果而不会接着分，空数组只有在初始输入的时候会遇到。

### 代码

```python3
class Solution:
    def stringy(self, lower, upper):
        if lower == upper:
            return str(lower)
        return str(lower) + "->" + str(upper)
    
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        if lower > upper:
            return []
        if not nums or len(nums) == 0:
            return [self.stringy(lower, upper)]
        
        if len(nums) == 1:
            result = []
            if lower < nums[0]:
                result.append(self.stringy(lower, nums[0] - 1))
            if nums[0] < upper:
                result.append(self.stringy(nums[0] + 1, upper))
            return result

        mid = len(nums) // 2
        return self.findMissingRanges(nums[:mid], lower, nums[mid] - 1) + self.findMissingRanges(nums[mid:], nums[mid], upper)


```