本题我是准备分享三种解法，虽然有些是从网上借鉴一些大佬的，没办法，谁让他们的思路如此清奇呢！！！

方法一：字典记值法

题目不是要求给定数组n中最多的元素吗，所以我用个字典专门来记录数组n中每个元素出现的次数即可，这样的话只需要一次遍历，而且字典的遍历效率是最高的！

代码如下：

```Python
class Solution(object):
    # 使用字典来记录nums数组中元素出现的次数
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dict_num = {}
        for num in nums:
            if num not in dict_num.keys():
                dict_num[num] = 0
            else:
                dict_num[num] += 1
        sorted(dict_num.items(), key=lambda item:item[1], reverse=True)
        return list(dict_num.keys())[0]
                

if __name__ == "__main__":
    nums = [3, 2, 3]
    mode = Solution().majorityElement(nums)
    print(mode)
```

但是报错了，这真的是让我百思不得其解，因为我在自己的IDLE编辑器上跑的是没问题的，如果有哪位大佬看出问题了，还望不吝赐教啊！！！！

方法二：摩尔投票法

这个方法我之前还真的没学习过，看了网上的文章，大概的思想如下：

在每一轮投票过程中，从数组中找出一对不同的元素，将其从数组中删除。这样不断的删除直到无法再进行投票，
如果数组为空，则没有任何元素出现的次数超过该数组长度的一半。如果只存在一种元素，那么这个元素则可能为目标元素。

也可以看作是动态规划方法的一种。

代码如下：

```Python
class Solution(object):
    # 摩尔投票法
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        majority = nums[0]
        count = 1

        for index in range(1, len(nums)):
            if count == 0:
                majority = nums[index]
                
            count = count+1 if majority == nums[index] else count-1
        return majority              

if __name__ == "__main__":
    nums = [3, 2, 3]
    mode = Solution().majorityElement(nums)
    print(mode)
```

执行效率中等偏上吧，在80%左右！

![image.png](https://pic.leetcode-cn.com/ce902f0ead137a1a9fa85c5daddbe3a6e5cef886e2450f4028f0eff5dcae4a74-image.png)

方法三：中位数法

这方法是真的骚，骚的不行。因为题目默认了给定数组s中有且仅有一个众数，所以将数组s按照从小到大的顺序排序后，众数肯定会占据着数组s一半以上的江山，那么也就可以说：数组s的最中间的元素肯定就是中位数了。怎么样，这波操作骚吧！！！

代码如下：

```Python
class Solution(object):
    # 排序后找中位数
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return nums[len(nums)//2]
                

if __name__ == "__main__":
    nums = [3, 2, 3]
    mode = Solution().majorityElement(nums)
    print(mode)
```

执行效率也在80%左右，比上一种方法稍微强一些！

![image.png](https://pic.leetcode-cn.com/2d93b63e741149841fe04f59066a892987b0502731045b9f6543083a1abb921c-image.png)
