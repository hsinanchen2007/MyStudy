本题解答起来不难，主要的难点就是：题目要求空间复杂度为O(1)，也就是不能用另一个数组来保存数据。本题我是想到了两种解法，思路都挺清晰的，下面一一分享。

方法一：

此种方法思路很easy，就是把nums列表想象成一个栈，右移一个位置，就相当于是把栈顶元素给取出来放置在栈底位置。所以直接用列表的insert()函数和pop()函数即可完成该操作。

代码如下：

```Python
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        true_k = k%len(nums)
        for index in range(true_k):
            nums.insert(0, nums[-1])
            nums.pop()


if __name__ == "__main__":
    nums = [1,2,3,4,5,6,7]
    k = 3
    Solution().rotate(nums, k)
```

执行效率一般般吧，在30%左右。

![image.png](https://pic.leetcode-cn.com/09c3daa62325c2ceca0bc39c0dc29ba2b0cadb35998233b85dbca513aa3038f7-image.png)

方法二：

方法一是一步一步进行右移操作的，执行效率自然是不高的，那么，如果我们能一次性进行多步数的右移操作，执行效率是不是可以大幅度提高？答案是肯定的。使用nums列表的切片操作即可快速实现。

代码如下：

```Python
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        true_k = k%len(nums)
        for index in range(true_k):
            nums.insert(0, nums[-1])
            nums.pop()


if __name__ == "__main__":
    nums = [1,2,3,4,5,6,7]
    k = 3
    Solution().rotate(nums, k)
```

执行效率还是很不错的，在90%以上。

![image.png](https://pic.leetcode-cn.com/721a59e21d956676c9fb22430609fefa6a5548b8305eff92b6f1e61ac4ba7bef-image.png)
