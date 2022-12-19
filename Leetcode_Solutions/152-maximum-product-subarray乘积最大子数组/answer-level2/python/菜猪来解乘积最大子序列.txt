本题是经典的动态回归方法，关于动态回归方法我前面有专门写了一篇文章来介绍如何作答的，感兴趣的朋友可以看看这篇[文章](https://zhuanlan.zhihu.com/p/55538325)。
在这篇文章里，我也提到了，其实解答动态回归的题目的关键点就是要找到动态方程。而本题的方程式比较难归纳到，让我们一步一步来分析。
首先，本题的难点无非就是要把负数和正数给区分开，而负数其实就是分两种情况：个数为单数和偶数。如果负数的个数为偶数的话，那好办了，最大乘积和为列表所有元素的乘积。如果负数个数为奇数个的话，其实也是两种情况：
![23f1eb06be2b8ec9b0f92d55d081277.jpg](https://pic.leetcode-cn.com/ccf24c84d4971d6395010a2718bc43d8811e08b9d2b6d30ca27f14af3feb0c27-23f1eb06be2b8ec9b0f92d55d081277.jpg)


所以，我们就是要能标记出这两种情况。一般来说，我们就是要初始化两个标记列表max_num和min_num来一次记录不同子序列的最大值和最小值。请注意：这里面的最大值和最小值不是全局意义上的最大值和最小值，但是但是但是，这两个值里面一定是有个最值的，即最小值或者是最大值，不然题目就解不出来啦。我们每次再用max()函数得出全局最大值即可。

最后，就是要给出动态方程了：
![9cfe3c589ac8411e83e767e1b933d18.png](https://pic.leetcode-cn.com/7e8d61df66139d70a8b9c5f2235332ba66d7930c5ace8e123ecb350cb04cd3fc-9cfe3c589ac8411e83e767e1b933d18.png)

代码如下：
```Python
class Solution(object):
    # 本题考查动态回归，难点就是动态方程的归纳
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 初始化子序列最大的乘积
        product = nums[0]
        # 这两个数组用来分别记录不同子序列的最大值和最小值
        max_num, min_num = [1] * (len(nums)+1), [1] * (len(nums)+1)
        for index in range(len(nums)):
            # 以下两步是状态转移方程
            max_num[index+1] = max(max_num[index]*nums[index], min_num[index]*nums[index], nums[index])
            min_num[index+1] = min(max_num[index]*nums[index], min_num[index]*nums[index], nums[index])
            product = max(product, max_num[index+1])
        return product


if __name__ == "__main__":
    nums = [-4,-3,-2]
    max_num = Solution().maxProduct(nums)
    print(max_num)
```
不过执行效率属实一般，在20%左右。