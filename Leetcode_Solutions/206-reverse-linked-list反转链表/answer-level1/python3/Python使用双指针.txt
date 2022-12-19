### 解题思路
使用cur指针指向当前头结点
使用pre指针指向当前头结点的前一个节点
将cur.next置为pre然后将pre和cur都向后移动直到cur为None循环结束
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre = None
        cur = head
        while(cur != None):
            temp = cur.next 
            cur.next = pre
            #将pre和cur分别向后移动一位
            pre = cur
            cur = temp
        return pre
```
