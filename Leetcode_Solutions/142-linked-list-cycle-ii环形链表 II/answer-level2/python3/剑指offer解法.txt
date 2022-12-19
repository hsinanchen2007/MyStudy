```
class Solution:
    def MeetingNode(self, head):
        if head == None:
            return None
        pslow = head.next
        if pslow == None:
            return None
        pfast = pslow.next
        while pslow != None and pfast != None:
            if pslow == pfast:
                return pfast
            pslow = pslow.next
            pfast = pfast.next
            if pfast != None:
                pfast = pfast.next
        return None

    def detectCycle(self, head: ListNode) -> ListNode:
        meetingNode = self.MeetingNode(head)
        if meetingNode == None:
            return None
        
        # 计算环中节点数目
        nodeInLoop = 1
        p1 = meetingNode
        while p1.next != meetingNode:
            nodeInLoop += 1
            p1 = p1.next
        

        # p1先在链表上从头开始向前移动n步
        p1 = head
        for _ in range(nodeInLoop):
            p1 = p1.next
            
        # 再同时移动p1和p2
        p2 = head
        while p1 != p2:
            p1 = p1.next
            p2 = p2.next
        
        return p1

```
