解题思路：迭代，头插
（1）指针从第二个节点开始，head先断开，否则会进入死循环
（2）每个节点插到head前，指针已经移到下一个节点
class Solution:
    def reverseList(self, head):
        if head is None:
            return head
        cur = head.next
        head.next = None
        while cur is not None:
            temp_node = cur
            cur = cur.next
            temp_node.next = head
            head = temp_node
        return head