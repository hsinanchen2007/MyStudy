### 解题思路
先把链表转成数组，然后每次将数组中位数放在根节点，左右子数组作为左右子树

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
        if not head:
            return []
        def generate_Tree(alist):
            if len(alist)==0:
                return None
            if len(alist)==1:
                root=TreeNode(alist[0])
                return root
            mid=len(alist)//2
            root=TreeNode(alist[mid])
            root.left=generate_Tree(alist[:mid])
            root.right=generate_Tree(alist[mid+1:])
            return root

        alist=[]
        while head.next:
            alist.append(head.val)
            head=head.next
        alist.append(head.val)
        return generate_Tree(alist)

```