### 解题思路
利用Python的logn的sort直接对所有元素排序
其他方法还有很多，头疼，不想了，Python这个应该klogn的时间复杂度，不算差的，但是kn的空间复杂度，肯定是比较差的

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        self.nodes = []
        head = node = ListNode(0)
        for i in lists:
            while i:
                self.nodes.append(i.val)
                i = i.next
        for i in sorted(self.nodes):
            node.next = ListNode(i)
            node = node.next
        return head.next
```