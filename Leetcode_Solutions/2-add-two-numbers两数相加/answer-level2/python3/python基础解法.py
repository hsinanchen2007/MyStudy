### 解题思路
1. 遍历，纯粹的数学相加，需要注意的是进位操作，一直在l1上面进行操作，不用增加空间消耗
2. 递归，每一位进行操作，递归出口是l1,l2都为零，主要做的就是将l1，l2的值相加然后赋值给l1

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # a, b , p, carry = l1, l2, None, 0
        # while a or b:
        #     val = int((a.val if a else 0) + (b.val if b else 0) + carry)
        #     carry, val= int(val/10) if val >= 10 else 0, int(val%10)
        #     p, p.val = a if a else b, val
        #     a, b = a.next if a else None, b.next if b else None
        #     p.next = a if a else b
        
        # if carry > 0:
        #     p.next = ListNode(carry)
        # return l1
        def add(a,b,carry):
			# 递归的终止条件是a和b都为空
			# 如果carry大于0需要返回一个进位标志
            if not (a or b):
                return ListNode(1) if carry>0 else None
            # 如果a为空则将ListNode(0)赋给a，对于b也是
            a = a if a else ListNode(0)
            b = b if b else ListNode(0)
            val = a.val + b.val + carry
            carry = 1 if val>=10 else 0
            a.val = val%10
            a.next = add(a.next,b.next,carry)
            return a
        return add(l1, l2, 0)


```