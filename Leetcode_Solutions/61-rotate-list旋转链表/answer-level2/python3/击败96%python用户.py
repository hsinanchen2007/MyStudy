```
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head
        # 得到链表的值
        count = 0
        n_list = []
        p = head
        while p:
            count += 1
            n_list.append(p.val)
            p = p.next
        # 确定链表开始的位置
        n_num = len(n_list)
        shift = k % n_num
        n_list = n_list[-shift:] + n_list[:-shift]
        # 修改链表
        p1 = head
        for i in n_list:
            p1.val = i
            p1 = p1.next
        return head
```