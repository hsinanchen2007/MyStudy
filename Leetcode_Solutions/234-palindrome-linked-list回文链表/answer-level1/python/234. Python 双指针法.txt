### 解题思路
将链表的数值拷贝到列表中，两个指针进行遍历。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        temp = []
        p = head
        while p:
            temp.append(p.val)
            p = p.next
        p, q = 0, len(temp) - 1
        while p < q:
            if temp[p] != temp[q]:
                return False
            p += 1
            q -= 1
        return True
```