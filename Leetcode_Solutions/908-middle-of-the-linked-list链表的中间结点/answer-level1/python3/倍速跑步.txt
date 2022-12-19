### 解题思路

#两个人跑步，一个1倍速（ans），一个二倍速（ans2），二倍速到达终点时，一倍速在中点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        ans=ans2=head
        while ans2 and ans2.next:
            ans=ans.next
            ans2=ans2.next.next        
        return ans

```