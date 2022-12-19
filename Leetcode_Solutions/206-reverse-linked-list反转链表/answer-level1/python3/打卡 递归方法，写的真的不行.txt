### 解题思路
击败10%..应该有好多冗余,大家多参考高赞代码,我是打卡拿个分溜了

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        def reverse(prv, node, ans):
            if node != None:
                ans = reverse(node, node.next, ans)
                node.next = prv
                #print(node.val)
                return ans
            else:
                return prv
        if not head:
            return []
        ans = reverse(head, head.next, None)
        head.next = None
        return ans
```