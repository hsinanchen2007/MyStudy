### 解题思路
执行用时 :28 ms, 在所有 Python3 提交中击败了99.69%的用户
内存消耗 :13.2 MB, 在所有 Python3 提交中击败了46.59%的用户

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        """
        链表的操作，往往需要借助一个虚拟节点，以及一个当前工作的节点来完成整个的遍历。
        """
        rootNode = ListNode(0)
        cur = rootNode
        while(l1 is not None and l2 is not None):
            if l1.val < l2.val:
                cur.next = l1 #使用值更小的节点作为下一个节点
                cur = cur.next #当前工作节点移动下一个节点
                l1 = l1.next #l1使用了一个节点。
            else:
                cur.next = l2
                cur = cur.next
                l2 = l2.next
        if l1 is None:
            cur.next = l2
        elif l2 is None:
            cur.next = l1
        return rootNode.next
        
        

        
```