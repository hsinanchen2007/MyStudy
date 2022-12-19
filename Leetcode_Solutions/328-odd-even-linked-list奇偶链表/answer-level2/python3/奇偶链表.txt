遍历链表，奇数节点放在一个链表中，偶数节点放在一个链表中，遍历完毕。奇数链表的尾节点指向偶链表的头节点，偶链表的尾节点为None,最后返回one_link.next（注意标志位的使用）
    
    class Solution:
        def oddEvenList(self, head: ListNode) -> ListNode:
            if not head:return head
            node = head
            one = ListNode(None)
            two = ListNode(None)
            one_link = one
            two_link = two
            i = 1
            while node:
                #pre = node.next
                if i%2==1:
                    one.next = node
                    one = one.next
                    #node = node.next
                else:
                    two.next = node
                    two = two.next
                node = node.next
                i+=1
            two.next = None
            one.next = two_link.next
            return one_link.next
                