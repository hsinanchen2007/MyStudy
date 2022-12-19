
```python
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:

        # recursion
        k_node = self._check_valid_k(head, k)  # 检查是否还有包括自己在内的k个节点 
        if k_node is None:
            return head

        next_node = self.reverseKGroup(k_node.next, k)
        k_node.next = None  # 断开链表准备翻转当前链表
        reversed_head = self._reverse_nodelist(head)  # 翻转
        head.next = next_node  # 尾连头就可以了

        return reversed_head

    def _check_valid_k(self, node, k):
        """
        算上自己看有效的节点有没有k个
        """
        cur_node = node
        while k > 1 and cur_node is not None:
            cur_node = cur_node.next
            k -= 1
        return cur_node

    def _reverse_nodelist(self, node):
        """反转一个单链表"""
        if node.next is None:
            return node

        ret_node = self._reverse_nodelist(node.next)
        node.next.next = node
        node.next = None

        return ret_node
```