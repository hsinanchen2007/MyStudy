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
    def hasCycle(self, head: ListNode) -> bool:
        #第一个方法可用于无重复链表
        #test=[]
        #count=0
        #while True:
         #   if len(set(test)) != count:
          #      return True
           # else:
            #    try:
             #       test.append(head.val)
              #      count+=1
               #     head=head.next
                #except:
                 #   return False
        
        slow=head
        if head is not None:
            fast=head.next
        else:
            return False
        while fast is not None:
            if fast == slow:
                return True
            else:
                try:
                    slow=slow.next
                    fast=fast.next.next
                except:
                    return False
        return False
```