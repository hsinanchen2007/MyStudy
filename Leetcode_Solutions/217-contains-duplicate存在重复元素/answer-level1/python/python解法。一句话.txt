这题首先打眼一看，嘿，不是一句话的事儿嘛
然后我写出了下面的代码：

```
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return True if len(set(nums))!=len(nums) else False
```
思路很简单，把list转换成集合set，集合会自动去重，然后对比一下长度，set长度小就说明有重复的

自以为极简，洋洋自得一提交，228ms，百分之五。傻眼。
去看看提交124ms的大佬们怎么写的吧：
![image.png](https://pic.leetcode-cn.com/ade6e51cc5531c51f089011e5efea1ede42591c24dd40e111f63d2f93320e716-image.png)

orz。

看到一个140ms大佬，更简单：
```
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return len(set(nums))!=len(nums)
```
天外有天呀
