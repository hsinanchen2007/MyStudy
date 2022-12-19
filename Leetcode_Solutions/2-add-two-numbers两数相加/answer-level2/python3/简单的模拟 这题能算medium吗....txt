### 解题思路
思路挺简单的，模拟手算就可以了。用一个`add`变量用来存进位，有进位就置成1，然后跟两位一起加，再置回0就可以了。如果两个加数位数不一样长，在比较短的那个加数前补0.

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        ans = ListNode(None)
        head = ans
        add = 0
        while True:
            sum = l1.val + l2.val + add
            l1 = l1.next
            l2 = l2.next
            add = 0
            if sum >= 10:
                sum -= 10
                add = 1
            ans.val = sum
            if l1 == None and l2 == None:
                if add == 1:
                    ans.next = ListNode(1)
                break
            else:
                if l1 == None:
                    l1 = ListNode(0)
                if l2 == None:
                    l2 = ListNode(0)
                ans.next = ListNode(None)
                ans = ans.next
        return head

```