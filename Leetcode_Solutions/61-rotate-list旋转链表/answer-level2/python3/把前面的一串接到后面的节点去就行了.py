class Solution:
    
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        
        if head == None or head.next == None:
            return head
        
        
       
        length = 1
        cur = head
        while cur.next != None:
            cur = cur.next
            length += 1
        #上面的代码是用来计算总长度地
        
        last_node = cur   #把原链表最后一个节点标记一下，到时候直接用菊花接住前面的一串节点
        if k >=length:
            k = k % length
        if k == 0:
            return head
       
    
        
        dummy = ListNode(0)   #辅助哑节点
        dummy.next = head      
        index = length - k   #新的开头节点的位置
        count = 0
        pre = dummy
        pt = dummy.next
        while count != index:   #找到新的开头节点，pre则是开头节点的前一个，也就是新的末尾节点，一会儿给他置空，防止形成闭环
            pre = pt
            pt = pt.next
            count += 1


        last_node.next = dummy.next   #原链表最后的节点用菊花接住
        dummy.next = pt         #开头
        pre.next = None         
            
        return pt
            