分析：
- 1 必须把链表走一趟，O(n)是跑不掉了。
- 2 向右移动 k 相当于相当于向右移动 k%listlen  (listlen != 0)

思路：
先遍历一遍得到长度listlen，再算出新的k。（顺便记录旧的尾节点）
移动 k 就相当于把 后面k个节点移到链表前面。新的表头就在第listlen-k处，找到这个位置断开，同时得到新的尾节点。再利用旧尾节点连接旧头节点就ok了。
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        #: 计算链表长度
        list_len = 0
        node = head
        while node:
            list_len += 1
            old_end = node  # 记录链表的旧尾节点，能提高效率（最多减少查找次数list_len-1次）
            node = node.next
        
        
        if list_len == 0:
            return head
        
        #：不用移动原来k那么多,会循环。
        k = k % list_len
        if k == 0: 
            return head
        
        #：定位新的尾节点，头节点
        i = list_len-k
        new_end = None
        new_head = head
        while i>0:
            new_end = new_head
            new_head = new_head.next
            i -= 1
        new_end.next = None
        old_end.next = head
        return new_head
        



```
