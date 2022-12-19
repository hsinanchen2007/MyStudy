### 解题思路
1. odd奇数列表和even偶数列表分开, 再合并成一个新的List = oddList + evenList
2. 遍历List, 重新赋值给head

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        oddList, evenList = [], []
        cur, flag = head, 1
        while cur is not None:
            if flag % 2 == 0:
                evenList.append(cur.val)
            else:
                oddList.append(cur.val)
            flag += 1
            cur = cur.next
        
        List = oddList + evenList
        _index, _cur = 0, head
        while _index < len(List):
            _cur.val = List[_index]
            _cur = _cur.next
            _index += 1

        return head
```