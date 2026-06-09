### 解题思路
这种题和 合并二叉树一样，都在考察树的遍历

1：先序递归
2：先序迭代
3：层次遍历

我感觉若不特定要求树的遍历方式，先序和层次相比之下更简单，可优先选择



### 代码

```

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        elif not p or not q:
            return False
        elif p.val == q.val:
            return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)

```

```

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:



        stack, output = [(p,q), ], []
        while stack:
            root1,root2 =stack.pop()
            if not root1 and not root2:
                continue
            elif not root1 or not root2:
                return False
            elif root1.val != root2.val:
                return False

            
            stack.append((root1.right, root2.right))

            stack.append((root1.left,root2.left))

        return True

```

```
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        deque, output = [(p,q), ], []
        while deque:
            root1,root2 =deque.pop(0)
            if not root1 and not root2:
                continue
            elif not root1 or not root2:
                return False
            elif root1.val != root2.val:
                return False

            deque.append((root1.left, root2.left))
            deque.append((root1.right, root2.right))
        return True
```