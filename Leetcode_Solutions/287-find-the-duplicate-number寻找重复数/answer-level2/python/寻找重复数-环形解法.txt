### 解题思路

本题的题解，主要是为了记录，个人在解决和了解过程中，碰到的对自己助益比较大的思路和方法：
- [官方题解](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode/)，多种方案，条分缕析，值得先看；
- [力友“windliang”总结](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--52/),[@windliang](/u/windliang/)，整理疏解，重点在快慢指针的使用和方法推导。
- 还有他所引用参考的[具体推导过程](https://leetcode.wang/leetcode-142-Linked-List-CycleII.html#%E9%A2%98%E7%9B%AE%E6%8F%8F%E8%BF%B0%EF%BC%88%E4%B8%AD%E7%AD%89%E9%9A%BE%E5%BA%A6%EF%BC%89)，很赞！

以上，非常感谢!

### 代码

```python3
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # 把nums看成是顺序存储的链表，nums中每个元素的值是下一个链表节点的地址
        # 那么如果nums有重复值，说明链表存在环，本问题就转化为了找链表中环的入口节点，
        # 因此可以用快慢指针解决
        
        # 初始时，都指向链表第一个节点nums[0]
        slow, fast = 0, 0
        # 慢指针走一步，快指针走两步
        slow, fast = nums[slow], nums[nums[fast]]
        # 循环退出时，slow与fast相遇，相遇节点必在环中
        while slow != fast:
            slow, fast = nums[slow], nums[nums[fast]]
        
        # 让before，after分别指向链表开始节点，相遇节点
        before, after = 0, slow
        # before与after相遇时，相遇点就是环的入口节点
        while before != after:
            before, after = nums[before], nums[after]
            
        return before
```