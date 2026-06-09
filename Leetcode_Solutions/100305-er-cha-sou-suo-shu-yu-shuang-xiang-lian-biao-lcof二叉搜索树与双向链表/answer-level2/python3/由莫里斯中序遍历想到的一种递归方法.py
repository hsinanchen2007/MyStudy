
我最初的想法：即通过Morris中序遍历过程来破坏原二叉搜索树的结构时，可以发现可以实现左子树有序。
    - **则通过每次实现左子树有序，再对右子树递归，这样最终可以得到一个单链表，再将单链表遍历得到循环双向链表**
```
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return root
        
        # 得到一个单链表
        def dfs(root):
            if not root:
                return None
            cur = root
            # 左子树已经有序，morris遍历中的一部分
            while cur.left:
                pre = cur.left
                while pre.right:
                    pre = pre.right
                pre.right = cur
                cur = cur.left
                pre.right.left = None
            # 即左子树的最左结点，即新树的根结点
            first = cur
            # 找到新的要递归的根结点
            while cur.right and cur.right.right and not cur.right.left:
                cur = cur.right
            cur.right = dfs(cur.right)
            return first
        first = dfs(root)

        # 遍历单链表，构成循环双向链表
        def getleft(first):
            pre,cur = first,first.right
            while cur:
                cur.left = pre
                pre,cur = cur,cur.right
            first.left = pre
            pre.right = first
            return first
        
        return getleft(first)
```
