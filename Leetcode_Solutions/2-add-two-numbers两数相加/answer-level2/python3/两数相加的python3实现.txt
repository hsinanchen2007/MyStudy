### 解题思路
因为链表是逆序的，(这里逆序和逆序数无关, 开始理解错了)，逆序表示链表的顺序就是从数字的低位到高位，这样正好符合加法竖式的运算规则，然后就遍历两个链表同时注意进位，链表有一个遍历到null也不要紧，当做0用即可. 

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 设置前置的head为0, 方便后续操作
        res = ListNode(0)
        cur = res
        carry = 0
        while l1 is not None or l2 is not None:
            if l1 is not None:
                n1 = l1.val
                l1 = l1.next
            else:
                n1 = 0
                # 不要手动补零, 否则while无法退出
                # 只需要设置和0位即可
                # l1.next = ListNode(0)

            if l2 is not None:
                n2 = l2.val
                l2 = l2.next
            else:
                n2 = 0

            s = n1 + n2 + carry
            cur.next = ListNode(s % 10)
            carry = s // 10
            # print(n1, n2, carry)

            cur = cur.next

        if carry != 0:
            cur.next = ListNode(carry)
        return res.next



```