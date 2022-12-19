复杂度为 `O(n)` 的滑动窗口解法比较容易懂，大家可以看看其他人的解法。
这里用 `python` 写了个比较容易看懂的时间复杂度为 `O(nlogn)` 解法，结合注释理解起来应该没有难度了，有问题欢迎留言。
```python
class Solution:
    def minSubArrayLen(self, s: int, nums) -> int:
        if nums is None or len(nums) == 0:
            return 0
        sums, min_len = [0], float('inf')
        # 累计求和的结果，可看做排序数组 sums[i] 表示 nums 中前 i 个元素的和
        for num in nums:
            sums.append(sums[-1] + num)
        # 所有元素的和比 s 还小
        if sums[-1] < s:
            return 0
        # 我们需要找到最小的j，使得 sums[j]-sums[i] >= s；即在 sums 数组中找到大于等于 s+sums[i] 的第一个元素
        # 这里 sums[j]-sums[i] 表示 nums 中第 i+1 个元素至第 j 个元素的和
        for i in range(len(sums)):
            j = self.findFirstBiggerNumber(s+sums[i], sums)
            # print(j)
            if j >= 0 and j-i < min_len:
                min_len = j-i
        return 0 if min_len == float('inf') else min_len

    def findFirstBiggerNumber(self, s, nums):
        """
        找大于等于给定值的第一个元素，二分查找
        :param s: 给定的值
        :param nums: 排序数组
        :return:
        """
        low, high = 0, len(nums)-1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] >= s:
                if mid == 0 or nums[mid-1] < s:
                    return mid
                # 前半部分还有满足条件的元素
                else:
                    high = mid - 1
            else:
                low = mid + 1
        return -1

```