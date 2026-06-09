### 解题思路
哈希表

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        dic1=dict()
        i=0
        while headA!=None:
            dic1[headA]=i
            i+=1
            headA=headA.next
        while headB!=None:
            if headB in dic1:
                return headB
            headB=headB.next
        return 
```

![image.png](https://pic.leetcode-cn.com/5f980208b5d0a7eb570de08e38ed26ce047fcf400265edff4c2ba381f212ec19-image.png)
