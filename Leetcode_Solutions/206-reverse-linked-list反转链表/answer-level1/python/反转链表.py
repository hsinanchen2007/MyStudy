* 递归解法
```
def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 递归终止条件是当前为空，或者下一个节点为空
        if head==None or head.next==None:
            return head
		# cur = n(k)
        cur = self.reverseList(head.next)
        # n(k+1)=n(k).next>n(k)
        head.next.next = head
		# 防止链表循环，需要将head.next设置为空
        head.next = None
		# 每层递归函数都返回cur，也就是最后一个节点
        return cur
```
* 迭代解法
```
def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return head
        pre=None
        cur = head
        while cur:
            tmp=cur.next()
            cur.next=pre
            pre=cur
            cur=tmp
        return pre
```
