对链表每次循环取K个节点，将K个节点翻转后挂在前一个已经反转完成的尾节点上，依次遍历直至链表结束，保持高效率需要注意的点有：
    1、在每次循环中判断是否存在K个节点，最后一次循环的节点数可能不满K个
    2、每次翻转一组后尽量少消耗额外空间的挂载
    3、尽量少占用额外空间进行链表翻转


     def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
         dummy = ListNode(None)
         dummy.next = head
         point1 = point2 = temp = dummy
         indicate = True

         while True:
             point1 = point1.next
             for i in range(0,k):
                 if point2.next:
                     point2 = point2.next
                 else:
                     indicate = False
                     break
             if indicate:
                 pre = point2.next
                 point2.next = None
                 temp.next = self.reverseList(point1)
                 point1.next = pre
                 point2 = temp = point1
             else:
                 break
         temp.next = point1
         return dummy.next
        
        
     def reverseList(self,head):
         if not head:
             return None
        
         pre = None
        
         while head:
             temp = head.next
             head.next = pre
             pre = head
             head = temp
         return pre
