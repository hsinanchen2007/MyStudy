### 解题思路

#### 自己最初的解法: 保留高度和子树解

对左右子树， 分别记录其高度，和其最长的直径
则对于 root 节点，其高度是  max(left_height, right_height)+1
其直径是 max([left_diam, right_diam, left_height+right_height+2])

if root == None:  # 以此作为递归出口
    return -1, 0  # height, diameter   # 这里 返回 height = -1 具有深意 

#### 官方题解
设置一个全局变量，直接记录经过每个节点的最长路径，并不计算以此节点为父节点的树的最长路径。

我之前的方法是求出每个子树的最长路径，然后 root 树的最长路径必然是解。

直接从每个节点所经过的路径出发，思路似乎更好。并且不用再额外传出统计高度的变量值。


直接设置一个全局变量 self.ans ，当遍历到某个节点时，求出经过该节点的路径的最大值，直接处理，而不一定要在父节点处理子树的 diam。

但官方题解中，是统计路径中节点的个数，直接来计算。 函数名用 num_nodes 更恰当。

我下面给出的另一种解法是直接统计路径长：
+ 定义 路径长 = 节点个数-1
+ 深度 = 节点个数 - 1

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:

        def diam_height(root):
            if root == None:  # 以此作为递归出口
                return -1, 0  # height, diameter
            left_height, left_diam = diam_height(root.left) # 如果用 C++ 写，可能无法同时返回两个变元
            right_height, right_diam = diam_height(root.right)
            new_height = max(left_height, right_height)+1
            new_diam = max([left_diam, right_diam, left_height+right_height+2]) # 这里+2，故上面当为空时返回 -1

            return new_height, new_diam

        return diam_height(root)[1]
```

``` python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if root == None: # 假设 root 就是空，按照定义，一个节点都没有，深度 = -1
            return 0     # 但测试用例期望输出 0

        self.ans = -1    # self.ans 是一个全局变量
        def depth(root): #定义 深度 = 路径长 = 节点个数 -1
            if root==None:
                return -1
            left_dep = depth(root.left)
            right_dep = depth(root.right)
            diam = left_dep + right_dep + 2   # 这里的深度是算路径长，而不是节点个数
            self.ans = max(self.ans, diam)
            dep = max(left_dep, right_dep) +1
            return dep

        depth(root)
        return self.ans
        
```