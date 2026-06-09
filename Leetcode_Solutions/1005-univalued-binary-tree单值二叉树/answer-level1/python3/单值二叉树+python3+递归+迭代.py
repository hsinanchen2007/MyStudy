### 递归
思路：左右子树同时为True才为True, 递归终点：当前节点为None。代码如下：
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root:
            return True
        else:
            val = root.val
            print(val)
            if root.left and root.left.val != val:
                return False
            elif root.right and root.right.val != val:
                return False
            else:
                return self.isUnivalTree(root.left) and self.isUnivalTree(root.right)
```
#### 复杂度分析
__时间复杂度__: O(n)，每个值访问一遍

__空间复杂度__: 平衡树O(log(n))，非平衡树O(n)

### 迭代
思路就是用一个栈存储起来，在一个个的判断，代码如下：
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        stack = [root]
        val = root.val
        while stack:
            tmp = stack.pop()
            if tmp and tmp.val != val:
                return False
            elif tmp:
                stack.append(tmp.left)
                stack.append(tmp.right)
        return True
        
```
#### 复杂度分析

都是O（n）,目前来看，好像是比set快一点的