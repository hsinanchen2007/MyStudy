### 解题思路
1. 排序 + 查重：
先排序，再从头到尾扫描：如果某个元素和它后面一个数相等，则这个数就是重复的

时间复杂度：O(nlogn)
空间复杂度：O(1)


2. dict 查重：
从头到尾扫描，把每个数当作dict的key，
如果新的元素值在dict里，则重复；否则添加进去

时间复杂度：O(N)
空间复杂度：O(N)


3. 逻辑判断
因为这个长为n的数组元素大小在0～n-1内，所以若没有重复元素，下标为i的元素值也是i。
思路：
从头到尾扫描，当扫描到下标为i时：
    3.1. 如果值是i，跳到下一个
    3.2. 如果不是，假设是m，
        3.2.1 若m = nums[m]，则重复数字是m
        3.2.2 否则就和下标为m的元素nums[m]交换位置，也即：将i放到第i个位置
    重复比较、交换、前进，直到找到重复元素

时间复杂度：O(N)
空间复杂度：O(1)


### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        if nums:
            i = 0
            while i < len(nums):
                num = nums[i]
                if i == nums[i]:
                    i += 1
                else:
                    if nums[i] == nums[num]:
                        return nums[i]
                    else:
                        nums[i], nums[num] = nums[num], nums[i]
        return None
```