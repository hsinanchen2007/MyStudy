### 解题思路
分为两步1是获取节点
        2是通过获取的节点构建平衡树
首先dfs中序遍历从小到大获取所有节点保存到vals里面

第二步构建对应的树,设定了两个基线条件 只有1个点和2个点
两种情况
其余情况可以递归地解决,
取中点,中点左右两端递归的构建left树和right树


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        vals = []
        def dfs(node):
            if node:
                dfs(node.left)
                vals.append(node.val)
                dfs(node.right)
            return vals
        dfs(root)
        def build(i,j):
            if i ==j:
                return TreeNode(vals[i])
            elif i+1 ==j:
                ans = TreeNode(vals[i])
                ans.right = TreeNode(vals[j])
                return ans
            mid = (i+j)>>1
            ans = TreeNode(vals[mid])
            ans.left = build(i,mid-1)
            ans.right = build(mid+1,j)
            return ans
        return build(0,len(vals)-1)
            

```