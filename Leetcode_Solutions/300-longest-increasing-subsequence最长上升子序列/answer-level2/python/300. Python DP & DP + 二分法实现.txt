### 解题思路
普通的动态规划方法dp[i]记录的是以nums[i]为结尾的最长子序列长度。这里遍历nums时间复杂度O(n)，查找之前的子序列时间复杂度O(n)，所以总的时间复杂度为O(n^2)。
加入二分法的思想是同样长度的子序列，我们只需要保留尾数最小的那个即可，比如对于子序列(1, 2, 3)和(1, 2, 4)来说，子序列(1, 2, 3)更容易成为更长升序子序列的一部分（概率可知），所以我们只需要记录同样子序列长度的尾数即可，即dp[i]记录长度为i + 1的最长子序列的尾数，对于上面的例子来说也就是dp == [1, 2, 3]，而且dp是**严格递增**的，非常适合使用二分法来查找，这时，我们的问题就转化为在已有记录的dp中找到第一个>=nums[i]，取等的原因是考虑到nums中可能存在同样的元素，那么就可能出现这样的情况：dp == [1, 2, 3]，nums == 2，如果不取等号，我们则找到第一个>nums[i]的位置left == 2，即修改dp[2]，但是此时并不应该修改dp[2]，因为dp[1] == 2，如果修改dp[2] == 2则相当于出现了[1, 2, 2]的子序列是不符合升序的原则的，所以此时我们又需要判断dp[left - 1]和nums[i]的值，这时候考虑left可能为0，left - 1会报错，又要特殊处理，所以最简单的方法就是取等号，然后判断当前的dp[left]是否小于nums[i]。

### 代码

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        """ 动态规划 + 二分法
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 0
        dp = [0] * length # dp[i]记录当前为i + 1长度子序列的最小尾数
        dp[0] = nums[0]
        p = 0
        for i in range(1, length):
            left, right = 0, p
            mid = (left + right) >> 1
            # 查找第一个>=nums[i]的数
            while left <= right:
                if dp[mid] >= nums[i]: # 注意这里取等号
                    right = mid - 1
                else:
                    left = mid + 1
                mid = (left + right) >> 1
            if left <= p: # 查找成功 
                if dp[left] > nums[i]:
                    dp[left] = nums[i]
            else:
                dp[p + 1] = nums[i]
                p += 1
        print(dp)
        return p + 1


    def lengthOfLIS_2(self, nums):
        """ 动态规划
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 0
        dp = [0] * length
        dp[0] = 1
        max_num = 0
        for i in range(1, length):
            temp = 0
            for j in range(i - 1, -1, -1):
                if nums[j] < nums[i] and dp[j] > temp:
                    temp = dp[j]
            dp[i] = temp + 1
            if dp[i] > max_num:
                max_num = dp[i]
        return max_num

```