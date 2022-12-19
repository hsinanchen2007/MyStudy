### 解题思路
挨个按住左边节点（遍历root1的所有节点），然后在root2中挨个进行比较。
比较过程如下：
1. target == 左边节点.val + 右边节点.val， 返回True。
2. target < 左边节点.val + 右边节点.val, 继续查找右边节点的左子树中的值。
3. target > 左边节点.val + 右边节点.val，那么接着查找右边节点的右子树中的值。
**左边的节点都遍历完了也没在右边搜索树中找到相关节点，函数最后返回False**

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        if not root1 or not root2:
            return False

        stack = [root1]
        while stack:
            x = stack.pop()
            if x.left:
                stack.append(x.left)
            if x.right:
                stack.append(x.right)
            ptr = root2
            while ptr:
                if ptr.val+x.val == target:
                    return True
                elif ptr.val+x.val > target:
                    ptr = ptr.left
                else:
                    ptr = ptr.right
            
        return False



        

        
```