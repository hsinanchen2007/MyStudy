### 解题思路
    分两层循环：
        外层遍历层次k：1，2，4，8......    共log(n)次
        内层遍历长度l：2k，4k, 6k, 8k...， 共n次(每个节点都要访问)
### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    #从head开始、最多找到cnt个链表节点的首位
    def findLast(self, head, cnt):
        left = head
        while cnt>1 and head.next:
            cnt, head = cnt-1, head.next
        return left, head
    #连接链表，返回首尾
    def join(self, left, right):
        dummy = ListNode()
        tail = dummy
        while left and right:
            if left.val <= right.val:
                tail.next = left
                tail, left = tail.next, left.next
            else:
                tail.next = right
                tail, right = tail.next, right.next
        if left:   tail.next = left
        if right:  tail.next = right
        while tail.next:
            tail = tail.next
        return dummy.next, tail

    def sortList(self, head):
        c, tail = 0, head
        while tail:
            c, tail = c+1, tail.next

        k, dummyHead = 1, ListNode(-1)
        dummyHead.next = head
        while k < c:
            l = 0
            pre, tail = dummyHead, dummyHead.next
            while l<c and tail:
                # 找到两串不为空的链表：需要与原始链表断开
                left, leftEnd = self.findLast(tail, k)
                leftEnd.next, tail =  None, leftEnd.next

                if tail==None: break
                right, rightEnd = self.findLast(tail, k)
                rightEnd.next, tail = None, rightEnd.next

                # 拼接两串链表，并与原始断点连接【pre、tail】
                left, right = self.join(left, right)
                pre.next, right.next= left, tail

                # 往前挪动一步：更新pre、已排序长度
                pre = right
                l += 2*k
            k*=2
        return dummyHead.next
        



        
```