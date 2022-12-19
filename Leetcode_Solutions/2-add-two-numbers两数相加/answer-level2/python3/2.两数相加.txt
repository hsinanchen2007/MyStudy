### 解题思路
分三个步骤来进行，第一步，两个数对应非空位相加；第二步，只剩一个数还存在非空位；最后一步，考虑可能的进位，添加一个结点，值为1.

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1 = l1; num2 = l2
        div,mod = divmod(num1.val+num2.val,10)
        ListHeader = ListNode(mod)
        cur = ListHeader
        num1 = num1.next; num2 = num2.next; 
        while(num1 and num2): #two number are exist
            div,mod = divmod(num1.val+num2.val+div,10)
            Node = ListNode(mod)
            cur.next = Node
            num1 = num1.next; num2 = num2.next; cur = cur.next
        while(num1):
            div,mod = divmod(num1.val+div,10)
            Node = ListNode(mod)
            cur.next = Node
            num1 = num1.next; cur = cur.next
        while(num2):
            div,mod = divmod(num2.val+div,10)
            Node = ListNode(mod)
            cur.next = Node
            num2 = num2.next; cur = cur.next
        if(div!=0):
            Node = ListNode(div)
            cur.next=Node
        return ListHeader



```