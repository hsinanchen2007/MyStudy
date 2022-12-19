这一题是第136题的进阶版。第136题中是：除了某个元素只出现一次以外，其余每个元素均出现了两次。这一题是出现了三次，那么就不能直接用异或运算快速解决了。所幸我在第136题中介绍了三种方法，其中有两种是可以直接复制过来的，很快捷，各位朋友可以先看看我刚写的一篇文章：

https://leetcode-cn.com/problems/single-number/solution/zhi-chu-xian-yi-ci-de-shu-zi-python-by-fei-ben-de-/

这篇文章里我写的很详细了，所以在这里我就不写这么多了，只介绍这其中的一种方法。

思路就是：通过这些不重复的元素和的三倍减去原来nums的和，得到的结果就是单个元素的两倍。

代码如下：
```python
class Solution(object):
    # 通过这些不重复的元素和的三倍减去原来nums的和，得到的结果就是单个元素的两倍
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        set_nums = set(nums)
        return (3*sum(set_nums)-sum(nums))//2

if __name__ == "__main__":
    nums = [2, 3, 2]
    unique_num = Solution().singleNumber(nums)
    print(unique_num)
```
执行效率在99%，还是很不错的！

![image.png](https://pic.leetcode-cn.com/cbf693e2e95f2fe9a8b19f1eadbe3f75af06bab2d866ad5d1c9c1bd68fc4a15f-image.png)