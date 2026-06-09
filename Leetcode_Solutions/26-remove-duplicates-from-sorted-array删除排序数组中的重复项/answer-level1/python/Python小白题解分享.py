### 解题思路
由于这个给定数组是有序的，所以重复元素都是挨着的。从数组的第一个元素开始遍历，找到一个重复的就删一个，直到找到不重复元素，进行下一个元素的遍历。最后返回数组长度。

废话几句：
这是我在LeetCode上做的第10道题目，相比之前做的，这道题我只用了十几分钟就写完了，而且代码也相对简洁，执行用时也有了很大进步，所以想给自己鼓励一下！也希望看到这篇分享的其他Python新手可以有信心！只要坚持，一定会进步！（以上我说的进步仅对比我以前的水平哈，不是说我现在很牛的意思，还是小白，还在努力！）
我也知道我现在的代码写得还是中下水平，如果大家有关于我的代码的修改建议，欢迎提出！

### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i=0
        while i<len(nums)-1:
            j=i+1
            while j<len(nums):
                if nums[j]==nums[i]:
                    del nums[j]
                else:
                    break                
            i=i+1
        return len(nums)
                

      

```