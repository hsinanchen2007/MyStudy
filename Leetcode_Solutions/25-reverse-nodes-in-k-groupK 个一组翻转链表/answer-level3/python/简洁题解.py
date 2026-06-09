这里提供一个程序逻辑较清晰，良好处理细节且更易解读代码：
```
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if k <= 0:
            return None
        if k == 1:
            return head
        pre_list_node = ListNode(0)
        cur = head
        head = pre_list_node
        while cur != None:
            ret = self.reverse_k_list(cur, k)
            pre_list_node.next = ret
            pre_list_node = cur
            cur = cur.next
        return head.next

    def reverse_k_list(self, cur, k, is_reverse_back=False):
        flag = 0
        first = cur
        pre = None
        while cur and flag < k:
            flag += 1
            l_next = cur.next
            cur.next = pre
            pre = cur
            cur = l_next
        if flag < k:
            pre = self.reverse_k_list(pre, flag, is_reverse_back=True)
        else:
            if not is_reverse_back:
                first.next = cur
        return pre
```