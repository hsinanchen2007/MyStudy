这一题我用的是双指针法，无非是固定一个start, end指针。end指针负责右移扩展数组，start指针也是右移不过是精简数组。简言之就是如果nums[start:end]子数组之和大于或等于s，那么end指针不动，start指针右移；如果nums[start:end]子数组之和小于s，那么start指针不动，end指针右移。直至end遍历完了数组，结束遍历取出最小连续子数组的长度即可。
**代码如下**：
```Python
class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        start, end = 0, 1
        flag = False
        min_length = len(nums)
        while start < end:
            all_sum = sum(nums[start:end])
            if all_sum >= s:
                min_length = min(min_length, end-start)
                start += 1
                flag = True
            else:
                end += 1
                if end > len(nums):
                    break
        return min_length if flag is True else 0


if __name__ == "__main__":
    s = 3
    nums = [1, 1]
    min_length = Solution().minSubArrayLen(s, nums)
    print(min_length)
```
很奇怪的是，执行效率极其的差，耗时1500ms，这简直不能忍嘛！
![image.png](https://pic.leetcode-cn.com/15093dafd5a029a14f247c3558d7de7d82d64911e5f09f6d6cc4214c1ee1d2fc-image.png)
于是我查看了那些耗时只有几十ms的解法，感觉大同小异，都是用双指针法，个人觉得外层循环用for更快吧，我找了个解法如下，大家可以比较看下差异。
**28ms代码如下**：
```
class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        l = 0
        tmp = 0
        res = float('inf')
        for r in range(len(nums)):
            tmp += nums[r]
            while tmp >= s:
                res = min(r-l+1, res)
                tmp-=nums[l]
                l+=1
        return res if res != float('inf') else 0


if __name__ == "__main__":
    s = 3
    nums = [1, 1]
    min_length = Solution().minSubArrayLen(s, nums)
    print(min_length)
```
