1、分别求取两个链表的长度，l1执行较长链表
2、用step保存当前计算位置，如果长度比短链表还要靠前l2始终指向短链表的开始，相当于补齐两个链表了
3、递归计算两个逻辑上长度一致链表的和

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        

        l1_len = self.list_len(l1)
        l2_len = self.list_len(l2)
        if l1_len < l2_len:
            l1, l2 = l2, l1
            l1_len, l2_len = l2_len, l1_len
        def add_helper(l1, l2, step):
            if l1 is None:
                return 0
            
            if step > l2_len:
                l2_next = l2
                l2_val = 0
            else:
                l2_next = l2.next
                l2_val = l2.val
            c = add_helper(l1.next, l2_next, step - 1)

            s = l1.val + l2_val + c
            l1.val = s % 10
            return s / 10

        carry = add_helper(l1, l2, l1_len)
        if carry > 0:
            node = ListNode(carry)
            node.next = l1
            l1 = node
        return l1


    def list_len(self, head):
        size = 0
        p = head
        while p:
            size += 1
            p = p.next
        return size


        