### 解题思路
执行44ms,时间复杂度是O(n),主要运用进位思想，有进位就加上进位去算

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        p=0
        i=0
        # 进位
        while True:
            if l1 and l2:
                a = l1.val+l2.val
                l1 = l1.next
                l2 = l2.next
            elif l1:
                a = l1.val
                l1 = l1.next
            elif l2:
                a = l2.val
                l2 = l2.next
            else:
                if p==0:
                    break
                else:
                    a=0
            i+=1
            o = (a+p)%10
            p = (a+p)//10
            if i==1:
               x = ListNode(o)
               q = x
            else:
                w = ListNode(o)
                q.next = w
                q = w
        return x



```