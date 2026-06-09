思路如下：我们先取数组第一个元素为候选元素，计数器count初始为1。然后遍历数组，若遇到相同元素则count加1,否则count减1。当count减为0时，我们把数组分为该元素之前（包含该元素）和该元素之后两个子数组A, B。
接下来说明候选元素只能在子数组B中是主要元素，才有可能是整个数组的主要元素。
例： [4, 4, 5, 5, 5, 4, 4, 5, 4], 则 A == [4, 4, 5, 5], B = [5, 4, 4, 5, 4]。
若A中含有主要元素，则其最多占A中一半，对B中寻找主要元素无任何帮助。所以在原数组中寻找主要元素的问题就变成在子数组B中寻找主要元素。以此类推，只需一趟遍历我们就能找到主要元素候选元素。
然后再一趟遍历确认该候选元素是否为主要元素即可。
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = 0
        count = 0
        for item in nums:
            if count == 0:
                candidate = item
            if candidate == item:
                count += 1
            else:
                count -= 1
        if nums.count(candidate) > len(nums)//2:
            return candidate
        else:
            return -1
```
