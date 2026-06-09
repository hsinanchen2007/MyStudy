### 解题思路
1. **拆解奇偶两个链表 + 添加到结尾**： 将奇节点放在一个链表里，偶链表放在另一个链表里。然后把偶链表接在奇链表的尾部。
2. 这个解法非常符合直觉思路也很简单。但是要写一个精确且没有 bug 的代码还是需要进行一番思索的。
    - 注释掉的代码是自己书写的，accept，但是代码不够简洁，太晦涩。
    - 当然，自己的代码也不是一次性通过的，#pre.next = h.next 就是考虑不周的错误，偶数结尾。
3. 对应的模板是 链表合并


### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head 
        
        odd = head
        even = head.next
        heven = even 

        while (even != None and even.next != None):
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next
        
        odd.next = heven

        return head 

        '''
        # accept but code is amazing
        cur = head 
        step = 1
        pre = head 
        h = ListNode(0)
        hcur = h
        while cur != None:
            if step % 2 == 0:
                pre.next = cur.next 
                hcur.next = cur 
                hcur = hcur.next
                pre = cur 
                cur = cur.next 
                
            else:
                pre = cur 
                cur = cur.next
            step += 1
        hcur.next = None
        cur = head 
        #pre.next = h.next
        while cur.next != None:
            cur = cur.next
        cur.next = h.next
        
        return head 
        '''
        






```