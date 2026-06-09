### 解题思路
遍历A树，使用一个辅助函数isSame判断两树相同（和leetcode572差别就在isSame定义上）

### 前序遍历用递归

```python

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        # 遍历A树
        # 题目定义，空树不是任意一个树的子结构
        if not B:
            return False
        # B非空时，A为空，返回False
        if not A:
            return False
        # 递归
        return self.isSame(A, B) or self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B)

    # 判断两树是否相同，注意不需要完全相同，p可以是q的叶子节点后又挂一些节点的树
    def isSame(self, p, q):
        # 递归终止条件，q为空，返回True；q不为空，p为空，返回False
        if not q:
            return True
        if not p:
            return False
        # 递归
        return p.val == q.val and self.isSame(p.left, q.left) and self.isSame(p.right, q.right)

```

### 前序遍历用迭代
```python
class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        # 遍历A树
        # 题目定义，空树不是任意一个树的子结构
        if not B:
            return False

        stack = [A]
        while A and stack:
            node = stack.pop()
            # res = self.isSame(node, B)
            # if res:
            #     return True
            # if node.right:
            #     stack.append(node.right)
            # if node.left:
            #     stack.append(node.left)
            res = self.isSame(node, B)
            if node:
                if res:
                    return True
                stack.append(node.right)
                stack.append(node.left)
        return False        
        

    # 判断两树是否相同，注意不需要完全相同，p可以是q的叶子节点后又挂一些节点的树
    def isSame(self, p, q):
        # 递归终止条件，q为空，返回True；q不为空，p为空，返回False
        if not q:
            return True
        if not p:
            return False
        # 递归
        return p.val == q.val and self.isSame(p.left, q.left) and self.isSame(p.right, q.right)
```
