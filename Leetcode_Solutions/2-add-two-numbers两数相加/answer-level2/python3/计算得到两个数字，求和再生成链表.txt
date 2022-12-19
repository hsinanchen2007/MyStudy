### 解题思路
先分别得到两个数字
再对两个数据求和
将和生成新的链表返回

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        temp1, temp2 = l1, l2
        num1 = num2 = 0
        i = j = 0
        while temp1:
            num1 += 10 ** i * temp1.val
            i += 1
            temp1 = temp1.next
        while temp2:
            num2 += 10 ** j * temp2.val
            j += 1
            temp2 = temp2.next
        new_list = ListNode(0)
        nums = str(num1 + num2)
        for char in nums:
            new_node = ListNode(int(char))
            new_node.next = new_list.next
            new_list.next = new_node
        return new_list.next


```