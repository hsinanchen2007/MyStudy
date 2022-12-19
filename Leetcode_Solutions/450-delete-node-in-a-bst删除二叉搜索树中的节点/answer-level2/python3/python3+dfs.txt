### 解题思路比较清楚的实现，但是应该还可以优化，不懂的同学可以看看《数据结构与算法Python语言实现》这本书的第11章
![UC截图20200102205226.png](https://pic.leetcode-cn.com/5b67565f40cb0da2a647ce5ced780acd607aa3cc2b3ccffa791fabb31850ff2e-UC%E6%88%AA%E5%9B%BE20200102205226.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def find_max(self,root):
        if root.right:
            return self.find_max(root.right)
        else:
            return root

    def search_node(self,pre,root,key,type,panduan):
        if not root:
            return pre,root,type,False
        if key < root.val:
            type = False
            pre = root
            return self.search_node(pre,root.left,key,type,panduan)
        if key > root.val:
            pre = root
            type = True
            return self.search_node(pre,root.right,key,type,panduan)
        if key == root.val:
            panduan = True
            return pre,root,type,panduan

    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return root
        if not(root.left or root.right):
            if root.val == key:
                return None
        pre, node, type, panduan = self.search_node(TreeNode('inf'), root, key, False, False)
        if not panduan:
            return root
        if not node.right and node.left:
            if node == root:
                return root.left
            if not type:
                pre.left = node.left
            else:
                pre.right = node.left
        elif not node.left and node.right:
            if node == root:
                return root.right
            if not type:
                pre.left = node.right
            else:
                pre.right = node.right
        elif not node.left and not node.right:
            if not type:
                pre.left = None
            else:
                pre.right = None
        elif node.left and node.right:
            cur = self.find_max(node.left)
            if node == root:
                if node.left == cur:
                    cur.right = node.right
                    return cur
                self.deleteNode(node.left, cur.val)
                cur.left = node.left
                cur.right = node.right
                return cur
            if not type:
                pre.left = cur
            else:
                pre.right = cur
            left_node = self.deleteNode(node.left, cur.val)
            cur.left = left_node
            cur.right = node.right
        return root
```