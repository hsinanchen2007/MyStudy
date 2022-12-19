**方案（一）：递归**

    def reverseList(self, head: ListNode) -> ListNode:
        #递归解法：
        #当头节点为空或下个节点为空时返回该节点：
        if head == None or head.next == None:
            return head
        
        #获取下一个节点：
        next_node = head.next
        #递归反转
        res = self.reverseList(next_node)
        #将头节点接到反转链表的尾部
        next_node.next = head
        head.next = None
        
        return res


**方案（二）：非递归**
    
    def reverseList(self, head: ListNode) -> ListNode:
        #非递归解法：
        if head == None or head.next == None:
            return head
        #建立新的空链表用于存储反转后的结果：
        res = None
        
        #遍历输入链表，将当前节点加入结果链表的头部：
        while head != None:
            next_node = head.next
            head.next = res
            res = head
            head = next_node
        
        return res
