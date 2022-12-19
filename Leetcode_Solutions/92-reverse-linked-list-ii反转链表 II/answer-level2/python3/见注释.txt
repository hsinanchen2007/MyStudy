### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        change_len = n - m + 1  # 记录逆置节点的个数
        pre_head = None  # 记录逆置节点的前驱
        result = head  # 最终转换后的链表头节点，非特殊情况即为head
        mm = m - 1
        while head and mm:  # 将head向前移动m-1个位置
            pre_head = head  # 记录head的前驱
            head = head.next
            mm -= 1
        modify_list_tail = head  # 将modify_list_tail指向当前的head，即逆置后的链表尾
        new_head = None
        while head and change_len:  # 逆置change_len个节点
            temp = head.next
            head.next = new_head
            new_head = head
            head = temp
            change_len -= 1
        modify_list_tail.next = head  # 连接逆置后的链表尾与逆置段的后一个节点
        if pre_head:  # 如果pre_head不空，说明不是从第一个节点开始逆置
            pre_head.next = new_head  
        else:
            result = new_head  # 如果pre_head为空，说明 m==1从第一个节点开始逆置，记过即为逆置后的头节点
        return result

```