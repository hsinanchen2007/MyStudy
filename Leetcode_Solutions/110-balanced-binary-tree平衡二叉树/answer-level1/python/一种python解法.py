### 解题思路
- `function depth()`用于确定以该节点为根节点的子树的深度
> 采用非赌鬼递归算法尽量保证低空间复杂度
- 若给定树为空树则直接返回True
- 递归调用，左右子树之差的绝对值小于2/左子树为平衡二叉树/右子树为平衡二叉树三个条件同时满足时该树为平衡二叉树

### Feature
- 感觉上应该可以将全部递归换为其他方式解决以得到最佳的空间复杂度，待确定

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def depth(root: TreeNode) -> int:
            queue = [] # 层次遍历工具队
            front = rear = -1 # 队列前后指针
            last = 0 # 本层次最后的节点
            level = 0 # 树深
            if not root:
                return 0
            rear += 1
            queue.append(root)
            while front < rear:
                front += 1
                p = queue[front]
                if p.left:
                    rear += 1
                    queue.append(p.left)
                if p.right:
                    rear += 1
                    queue.append(p.right)
                if last == front:
                    level += 1
                    last = rear
            return level # 返回树深度
        
        # 递归调用遍历每个节点
        # 出现深度差值大于1则返回False
        if not root:
            return True # 空树
        return abs(depth(root.left) - depth(root.right)) < 2 and self.isBalanced(root.left) and self.isBalanced(root.right)
```