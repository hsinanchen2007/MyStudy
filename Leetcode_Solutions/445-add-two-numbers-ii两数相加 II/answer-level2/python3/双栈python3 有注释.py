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
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1: return l2
        if not l2: return l1

        stack_l1 = self.ListNode2Stack(l1)
        stack_l2 = self.ListNode2Stack(l2)
        carry = 0
        res = ListNode(0)
        while(stack_l1 or stack_l2 or carry):
            num1 = stack_l1.pop() if stack_l1 else 0
            num2 = stack_l2.pop() if stack_l2 else 0
            sum = num1 + num2 + carry #+carry加进位
            res_num = ListNode(sum % 10)  #新建node
            res_num.next = res.next#插入为头节点后的第一个节点
            res.next = res_num
            carry =  sum//10
        return res.next



        #print(stack_l1)
        #print(stack_l2)
    
    #不重复, 函数化
    def ListNode2Stack(self, l1):
        stack_l1 = []
        while(l1):
            item1 = l1.val
            stack_l1.append(item1)
            l1 = l1.next
        return stack_l1
```