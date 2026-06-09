### 解题思路
利用双指针的思路
pre 保存的的当前的指向位置
cur 保存的是当前位置
核心的就是把cur.next变成pre，cur变成cur.next进行迭代

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = None
        cur = head
        while(cur != None):
            cur.next,cur,pre= pre,cur.next,cur
        return pre
```