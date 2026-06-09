### 解题思路
### 根据dfs的思想，采用递归的方法解题。

本题关键点在于选定条件
1.p存在，q不存在，返回False
2.p不存在,q不存在，返回False
3.p和q都为None的时候，返回True
4.除了上述条件下，值相等的情况下进行递归




### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if p and not q:
            return False
        if not p and q:
            return False
        if p is None and q is None:
            return True

        if p.val == q.val:
            result = self.isSameTree(p.left,q.left)
            if not result:
                return False 
            result = self.isSameTree(p.right,q.right)
            if not result:
                return False
            return True
        else:
            return False
        
```
# 利用all（）稍微优化一下
```python
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if p and not q:
            return False
        if not p and q:
            return False
        if p is None and q is None:
            return True
        if p.val != q.val:
            return False
        return all((self.isSameTree(p.left,q.left),self.isSameTree(p.right,q.right)))

```
### 使用迭代方法解题：
本题关键点在于选定条件
每次迭代从队列中取出两个相邻的节点，因为每两个相邻的节点表示两棵树对应比较的结点。
1.p存在，q不存在，返回False
2.p不存在,q不存在，返回False
3.p和q都为None的时候，返回True
4.除了上述条件下，值相等的情况下进行，因为是二叉树，所以两棵树对应比较的种类为2种，即4个结点，按照两两对应的方式存入队列中，循环迭代取出比较。
5.如果两棵树完全相同，那么队列应该为空，返回True，否则中途不满足条件返回False

```python
from collections import deque
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        deq = deque([p,q])
        while deq:
            left_tree = deq.popleft()
            right_tree = deq.popleft()
            if left_tree == None and right_tree == None:
                # 可能还有其他比较需要迭代
                continue
            if left_tree == None or right_tree == None:
                return False
            if left_tree.val != right_tree.val:
                return False
            deq.extend([left_tree.left,right_tree.left,left_tree.right,right_tree.right])
        # 最终队列如果为空的话，表示两个树相同
        return True 
```