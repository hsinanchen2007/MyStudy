可以直接利用while循环将链表转化为列表，再利用列表的长度配合索引得到倒数的元素，属于比较暴力的一种方法。
class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        list_node = []
        while head:
            list_node.append(head.val)
            head = head.next
        return list_node[len(list_node)-k]``
