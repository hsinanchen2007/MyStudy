### 解题思路
    暴力法：遍历headA的同时遍历headB，当找到结点相同时，退出循环     时间复杂度O(MN) 空间按复杂度O(1)
    
    堆栈法：空间换时间，构建两个堆栈对headA和headB的数据进行保存，当存储完毕时进行抛出。
            当两个堆栈抛出的数据不同时，返回。   时间复杂度 O(M+N)   空间按复杂度O(M+N)

    再相遇（代码）：遍历两次，则第一个相同节点为公共节点。    时间复杂度O(MN)  空间按复杂度O(1)

### 代码

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        node1,node2 = headA,headB   #此时为浅复制，内存地址相同，未开辟新的内存
        while (node1 != node2):
            node1 = node1.next if node1 else headB    # 只是将node的指针指向了 head.next
            node2 = node2.next if node2 else headA
        return node1
```