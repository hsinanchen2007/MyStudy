### 解题思路
依次读取链表值，乘以相应的10的i次方，加到数中；
计算两数之和，转换为字符串列表，再生成数字链表。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1 = num2 = 0
        i = 0
        current = l1
        while current is not None:
            num1 += current.val * (10**i)
            current = current.next
            i += 1
        i = 0
        current = l2
        while current is not None:
            num2 += current.val * (10**i)
            current = current.next
            i += 1
        the_sum = num1 + num2
        sum_list = list(str(the_sum))
        resList = ListNode(int(sum_list.pop()))
        position = resList
        for k in range(len(sum_list)):
            temp = ListNode(int(sum_list.pop()))
            position.next = temp
            position = position.next
        return resList

```