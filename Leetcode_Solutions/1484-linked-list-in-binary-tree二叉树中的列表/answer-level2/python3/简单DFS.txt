### 解题思路
2种判断逻辑，如果对应的数字一致，接下来每个数字都需要在子树中找到，否则只需要dfs搜寻即可

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
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        if not head:
            return True
        elif head and not root:
            return False
        elif head.val == root.val:
                flag =  self.isHasWay(head.next, root.left) or self.isHasWay(head.next, root.right)
                if flag:
                    return True
                else:
                    return self.isSubPath(head, root.left) or self.isSubPath(head,root.right)
        else:
            return self.isSubPath(head, root.left) or self.isSubPath(head,root.right)

    def isHasWay(self,head,root):
        if not head:
            return True
        elif head and not root:
            return False
        elif head.val == root.val:
                return self.isHasWay(head.next, root.left) or self.isHasWay(head.next, root.right)
        else:
            return False

```