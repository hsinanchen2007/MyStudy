### 解题思路
dfs + 一些辅助函数
![2020-01-01 00-16-32屏幕截图.png](https://pic.leetcode-cn.com/843d6f979e3b9801fd6513a4072c2c7e3eaba90df156f8ef541d62ebd408f85b-2020-01-01%2000-16-32%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def len(self,head):
        count = 0
        while head != None:
            count += 1
            head = head.next
        return count

    #补0函数
    def buzero(self,node,n):
        head = cur = ListNode(0)
        for i in range(n-1):
            cur.next = ListNode(0)
            cur = cur.next
        cur.next = node
        return head

    def addTwoNumbers(self, l1, l2):
        if self.len(l1) < self.len(l2):
            l1 = self.buzero(l1,self.len(l2) - self.len(l1))
        elif self.len(l1) > self.len(l2):
            l2 = self.buzero(l2,self.len(l1) - self.len(l2))
        # res1 = self.print(l1)
        # res2 = self.print(l2)
        # print(res1)
        # print(res2)

        def help(l1,l2,carry):
            a = l1.val
            if not l1.next:
                l1.val = (l1.val + l2.val + carry) % 10
                carry = (a + l2.val + carry) // 10
            else:
                res = help(l1.next, l2.next, carry)
                l1.val = (l1.val + l2.val + res) % 10
                carry = (a + l2.val + res) // 10
            return carry
        carry = help(l1,l2,0)
        if carry != 0:
            head = ListNode(carry)
            head.next = l1
            return head
        else:
            return l1
        
    # def print(self,head):
    #     res = []
    #     while head != None:
    #         res.append(head.val)
    #         head = head.next
    #     return res
```