### 递归法
执行用时 :72 ms, 在所有 Python3 提交中击败了68.22%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了5.07%的用户

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def create_listnode(self, sums):
        if sums == 0:
            return None
        val = sums % 10
        output = ListNode(val)
        output.next = self.create_listnode(sums // 10)
        return output
        
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        cnt = 0
        sum1 = 0
        sum2 = 0
        while l1 or l2:
            if l1:
                sum1 += l1.val*10**cnt
                l1 = l1.next
            if l2:
                sum2 += l2.val*10**cnt
                l2 = l2.next
            cnt += 1
        sum3 = sum1 + sum2
        if sum3 == 0:
            return ListNode(0)
        res = self.create_listnode(sum3)
        return res
        
            
```
### 指针
执行用时 :72 ms, 在所有 Python3 提交中击败了68.22%的用户
内存消耗 :13.5 MB, 在所有 Python3 提交中击败了5.07%的用户

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
        
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        res = p = ListNode(0)
        while l1 or l2:
            if l1:
                a1 = l1.val
                l1 = l1.next
            else:
                a1 = 0
            if l2:
                a2 = l2.val
                l2 = l2.next
            else:
                a2 = 0
            a = a1 + a2 + carry
            if a > 9:
                carry = 1
                a = a % 10
            else:
                carry = 0
            p.next = ListNode(a)
            p = p.next
        if carry == 1:
            p.next = ListNode(1)
        
        return res.next
           
```