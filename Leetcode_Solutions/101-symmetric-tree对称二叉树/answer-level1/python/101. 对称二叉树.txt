### 解题思路
迭代思想，类似于BFS

### 代码
BFS
```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#### 迭代方法 类比于BFS 但入列方式稍有差异
class Solution(object):
    def isSymmetric(self, root):
        #对于镜像树而言，相同根节点的两棵树，1左=2右，1右=2左
        q = [root,root]
        while q:
            r1 = q.pop(0)
            r2 = q.pop(0)
            if not r1 and not r2:
                continue
            if not r1 or not r2:
                return False
            if r1.val != r2.val:
                return False
            else:
                q.append(r1.left)
                q.append(r2.right)
                q.append(r1.right)
                q.append(r2.left)
        return True
- 
 **递归方法**
class Solution(object):
    def isSymmetric(self, root):
        return self.ismirror(root,root)
    def ismirror(self,root1,root2):
        if not root1 and not root2:
            return True
        if not root1 or not root2:
            return False
        if root1.val != root2.val:
            return False
        return self.ismirror(root1.left,root2.right) and self.ismirror(root1.right,root2.left)

```



```