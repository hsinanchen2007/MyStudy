这其实是一个披着算法题外衣的xxxx视频...

##### 题目：如何判断一个链表是否有环
![...何判断链表是否有环之龟兔赛跑新解.mp4](dfc2e6bc-7227-4fce-88c3-4968f304a8d1)

题目链接：[https://leetcode-cn.com/problems/linked-list-cycle/](https://leetcode-cn.com/problems/linked-list-cycle/)
（题目描述如标题...相信你一看就知道了，就不放题目描述了...）
###### 解法一：（非o(1)空间复杂度解法）
遍历链表，每次遍历到一个新的结点时，判断该结点是否在集合set中，如果在集合set中说明链表有环，否则记录在set(集合)中，继续遍历。
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None:
            return False
        node = head
        nodeset = set()
        while (node):
            if node in nodeset:
                return True
            else:
                nodeset.add(node)
            node = node.next
        return False
```
在python中set的底层是字典，所以在set中查找一个数的时间复杂度是o(1)，因此这种解法的时间复杂度是o(1*n)=o(n)，需要一个集合记录结点所以空间复杂度为o(n)。
###### 解法二：
我们设置快慢两个指针，快指针每次走2步，慢指针每次走1步
如视频所示，跑道是链表，兔子（快指针）每次走2步，乌龟（慢指针）每次走1步，在走完跑道（链表）的前提下，如果兔子和乌龟（快慢指针）相遇，说明跑道（链表）有环，否则说明跑道没有环。
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None:
            return False
        fastnode = head
        slownode = head
        while (fastnode):
            if fastnode.next and fastnode.next.next:
                fastnode = fastnode.next.next
                slownode = slownode.next
            else:
                return False

            if fastnode == slownode:
                return True
        return False

```
由于我们只用到快慢指针，所以空间复杂度为o(1),遍历一次链表所以时间复杂度为o(n)。



