### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head 
        
        cur = head
        hnext = None
        h = ListNode(0)
        while cur != None:
            h.next = cur 
            cur_next = cur.next
            cur.next = hnext
            hnext = cur 
            cur = cur_next 
        return h.next 
        
'''
已知的不带头结点，上面是带头结点的解法
public ListNode reverseList(ListNode head) {
    ListNode prev = null;
    ListNode curr = head;
    while (curr != null) {
        ListNode nextTemp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
'''
```