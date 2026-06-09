这一题看上去是有点像第229题[求众数](https://zhuanlan.zhihu.com/p/115746327)，因为题目已经告诉你了，在nums数组中一定存在一个重复数。当时有想到用摩尔投票法的思想来解题，可是又想到摩尔投票法是要求数字出现的次数超过1/n的，这里面n没有给定，所以还真不好用摩尔投票法来解决。

后来又想到一个很直接的方法，就是首先将数组nums排序，然后我们再从左至右依次遍历，只要是数字连续出现，那么该数字就是我们要找的众数。**代码如下**：
```Python
class Solution(object):
    def findDuplicate(self, nums):
        """
        排序法，查重
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        for index in range(len(nums)-1):
            if nums[index] == nums[index+1]:
                return nums[index]


if __name__ == "__main__":
    nums = [3, 1, 3, 4, 2]
    duplicate_num = Solution().findDuplicate(nums)
    print(duplicate_num)
```
思路非常简单，真论执行效率也不差，达到了70%。但是呢，我们用了nums.sort()排序法，看似没有扩充空间，但还是临时分配了O(n)的空间，所以不符合题目的要求。那这也不能用，还有什么方法呢？在这儿得着重介绍一个概念：抽屉原理。概念如下：
`桌上有十个苹果，要把这十个苹果放到九个抽屉里，无论怎样放，我们会发现至少会有一个抽屉里面放不少于两个苹果。`

有了这个作为铺垫，我们可以用到了二分法来解决了。即定义一个中位数，值为选定nums集合内最大值和最小值的平均值。如果：**小于等于 4 的个数如果严格大于 4 个，此时重复元素一定出现在 [1, 4] 区间里**。凭此概念，代码如下：
```Python
class Solution(object):
    def findDuplicate(self, nums):
        """
        不同理解的二分法来解题
        :type nums: List[int]
        :rtype: int
        """
        left, right = 1, len(nums)-1
        while left < right:
            mid = (left + right) // 2
            cnt = 0
            for num in nums:
                if num <= mid:
                    cnt += 1
            # 根据抽屉原理，小于等于 4 的数的个数如果严格大于 4 个，
            # 此时重复元素一定出现在 [1, 4] 区间里

            if cnt > mid:
                # 重复的元素一定出现在 [left, mid] 区间里
                right = mid
            else:
                # if 分析正确了以后，else 搜索的区间就是 if 的反面
                # [mid + 1, right]
                left = mid + 1
        return left


if __name__ == "__main__":
    nums = [3, 1, 3, 4, 2]
    duplicate_num = Solution().findDuplicate(nums)
    print(duplicate_num)
```
执行效率还可以吧，在70%左右。
![image.png](https://pic.leetcode-cn.com/40035438b11ee49dd3931a6e44110936b47da176c57b8a93f95416784e3519f1-image.png)
