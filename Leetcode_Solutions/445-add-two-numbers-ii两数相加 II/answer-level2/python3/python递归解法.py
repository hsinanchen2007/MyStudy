# 思路
- 短的链表在前面补零节点直到和长的链表的长度相等，然后用递归的方法对每个节点的值进行相加，这个过程中直接对l1进行in-place的修改操作，使其每个节点存储都存储加和后的值，别忘了最后的进位就可以了。

```python
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        self.c = 0  # 进位标志
        l1_length = self._get_length(l1)  # 求两个链表的长度
        l2_length = self._get_length(l2)
        diff = l1_length - l2_length  
        if diff == 0:
            self._add_recur(l1, l2)  # 长度相等直接加就可以了
        else:
            zero_listnode, tail = self._get_zero_listnode(abs(diff))  # 全零链表，同时拿到头和尾，准备拼接
            if diff > 0:  # l1 > l2
                tail.next = l2  # 对l2进行拼接
                l2 = zero_listnode  # 拿到l2新的头节点
            else:  # l1 < l2
                tail.next = l1  # 对l1进行拼接
                l1 = zero_listnode  # 拿到l1新的头节点
            self._add_recur(l1, l2)  #  开始相加

        result = l1  # 我们是对l1进行in-place的相加操作，所以要拿l1作为返回结果
        if self.c:  # 别忘了最后可能有进位
            result = ListNode(1)
            result.next = l1
        return result

    def _add_recur(self, l1, l2):
        if l1 is None and l2 is None:
            return
        self._add_recur(l1.next, l2.next)
        tmp_val = l1.val + l2.val + self.c
        val = tmp_val % 10
        self.c = tmp_val // 10
        l1.val = val

    def _get_length(self, l):
        cur_node = l
        length = 0
        while cur_node:
            length += 1
            cur_node = cur_node.next
        return length

    def _get_zero_listnode(self, length):
        head = ListNode(0)
        cur = head
        while length - 1:
            cur.next = ListNode(0)
            cur = cur.next
            length -= 1
        return head, cur
```