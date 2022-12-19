### 解题思路
方法1 迭代
翻译了一下官方题解。这里用collections模块里的deque（）作为双向列表，stack.pop（）弹出根节点进行处理，得到根节点的左右子树，再用stack.appendleft()将左右子树添加到栈的头部，形成循环。子节点永远在根节点的后面处理，所以也是BFS一种。

### 代码

```python3
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1:
            return t2
        from collections import deque
        stack = deque()
        stack.appendleft([t1,t2])
        while stack:
            t = stack.pop()
            if not t[0] or not t[1]:
                continue
            t[0].val += t[1].val
            if not t[0].left :
                t[0].left = t[1].left
            else:
                stack.appendleft([t[0].left, t[1].left])
            if not t[0].right :
                t[0].right =t[1].right
            else:
                stack.appendleft([t[0].right, t[1].right])
        return t1
        

方法2 递归DFS


### 代码

```python3
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1: return t2
        if not t2: return t1
        t1.val += t2.val
        t1.left = self.mergeTrees(t1.left, t2.left)
        t1.right = self.mergeTrees(t1.right, t2.right)
        return t1