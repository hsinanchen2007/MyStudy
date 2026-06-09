### 解题思路
常规思路:
新建hashset; 排序后找连续相同数字; 以本身做hashtable; 
但这些都不满足

二分新用法: 用二分去找重复数所在的区间范围.
所以每次遍历还是遍历整个数组, 只不过每次二分缩小范围

### 代码

```python3
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        i, j = 1, len(nums)-1
        while i<j:
            mid = (i+j)//2
            count = 0
            for n in nums:
                if i<=n<=mid:
                    count += 1
            if count>(mid-i+1):
                j = mid
            else:
                i = mid+1
        return i
```

这个人总结的很好
思路：如果题目不限制：

1.不能更改原数组（假设数组是只读的）；
2.只能使用额外的 O(1) 的空间。
容易想到的方法有：

使用哈希表判重，这违反了限制 2；
将原始数组排序，排序以后，重复的数相邻，即找到了重复数，这违反了限制 1；
使用类似「力扣」第 41 题：“缺失的第一个正数” 的思路，当两个数发现要放在同一个地方的时候，就发现了这个重复的元素，这违反了限制 1；
既然要定位数，这个数恰好是一个整数，可以在“整数的有效范围内”做二分查找，但是比较恶心的一点是得反复看整个数组好几次，本文就介绍通过二分法定位数；
还可以使用“快慢指针”来完成，不过这种做法太有技巧性了，不是通用的做法，官方的题解就提供了这种做法

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

关于O(n)的快慢指针, 这个代码讲得清楚些
```
def findDuplicate(self, nums: List[int]) -> int:
        # 把nums看成是顺序存储的链表，nums中每个元素的值是下一个链表节点的地址
        # 那么如果nums有重复值，说明链表存在环，本问题就转化为了找链表中环的入口节点，因此可以用快慢指针解决
        
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