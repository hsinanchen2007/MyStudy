### 解题思路
每次找到链表中的中间节点，然后根据中间节点，将链表分成两部分，左边部分作为左子树，右边部分作为右子树

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        return self.buildtree(head)
        
        
    def buildtree(self,head):
        if not head:return None
        if not head.next:return TreeNode(head.val)
    
        last_node,middle = self.findmiddle(head)
        last_node.next = None
        left = head
        val = middle.val
        right = middle.next
        middle.next = None
        treehead = TreeNode(val)
        treehead.left = self.buildtree(left)
        treehead.right = self.buildtree(right)
        return treehead

    def findmiddle(self,link):
        lastnode = ListNode(-1)
        lastnode.next = link
        temp = lastnode
        slow = link
        fast = link
        while fast and fast.next:
            temp = temp.next
            slow = slow.next
            fast = fast.next.next
        return temp,slow
```