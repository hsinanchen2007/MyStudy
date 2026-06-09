```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head) -> ListNode:
        mid, tag = head, head
        flag = True
        while tag != None:
            tag = tag.next
            if flag and tag != None:
                mid = mid.next
                flag = False
            else:
                flag = True
        return mid
    
```
![image.png](https://pic.leetcode-cn.com/0ba714b75d6d163b17a74e4d919d9f025fc10c3c3d1e76491d8d97045b09ed12-image.png)
