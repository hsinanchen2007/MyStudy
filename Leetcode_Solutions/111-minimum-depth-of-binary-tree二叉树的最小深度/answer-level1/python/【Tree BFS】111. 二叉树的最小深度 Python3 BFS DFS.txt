### 解题思路
- 相似题型
- BFS
- DFS
- 代码
- 复杂度

### 相似题型
- [102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/)
- [107. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/solution/er-cha-shu-xi-lie-107-er-cha-shu-de-ceng-ci-bian-l/)
- [103. 二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/er-cha-shu-xi-lie-103-er-cha-shu-de-ju-chi-xing-ce/)
- [637. 二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/solution/er-cha-shu-xi-lie-637-er-cha-shu-de-ceng-ping-jun-/)
- [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/er-cha-shu-xi-lie-116-tian-chong-mei-ge-jie-dian-d/)
- [117. 填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/er-cha-shu-xi-lie-117-tian-chong-mei-ge-jie-dian-d/)
- [199. 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/tree-bfs-199-er-cha-shu-de-you-shi-tu-python3-bfs-/)
- [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/solution/er-cha-shu-xi-lie-200-dao-yu-shu-liang-python3-bfs/)
- [863. 二叉树中所有距离为 K 的结点](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/solution/tree-bfs-863-er-cha-shu-zhong-suo-you-ju-chi-wei-k/)


### BFS
指路：[102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/) 的题解

**重点**：`树即为directed graph`，层次遍历就可以用`Breadth Search First`完成

**区别**：对于最小深度，即为没有左右子树的时候的深度就是最小深度，那么不再保存每一层的数值，而是用一个变量存储每一层的高度，`bfs`遍历的时候判断只要有一个节点是没有左右子树，那么当前层就代表了最小深度

**注意**：当没有`root`的时候，`dep=0`，那么`dep`的初始化就应该`1`而不是`0`

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        
        if not root:
            return 0
        
        '''dep的初始化应该是1而不是0，root为第一层，高度为1'''
        dep = 1  
        queue = [root]
        
        while queue:
            nxt = []  # 保存下一层的节点
            for node in queue:
                '''如果有一个node没有左右子树，那么此时就为最小深度'''
                if not node.left and not node.right:
                    return dep
                if node.left:
                    nxt.append(node.left)
                if node.right:
                    nxt.append(node.right)
            
            dep += 1
            queue = nxt  # 每次更新queue
            
        return dep
                
```
#### 复杂度
`n`是树的节点个数
- 时间复杂度：`O(n)`
  我们遍历了所有节点
- 空间复杂度：`O(m)` 
  我们需要用辅助的队列来存放树的一部分节点，m为树中每一层节点个数的最大值


### DFS
这道题除了`BFS`，还可以用`DFS`完成
`最小深度 = min(左子树的最小深度，右子树的最小深度) + 1`

**注意**：如果一个没有`root`，返回`0`，但是如果`root`只有左子树或者只有右子树，那么缺失的那一边就会返回`0`，那么对于当前`root`取`min`值的话就是会得到`0+1`的结果，`但实际上，这个root的实际最小深度应该是有子树的那一边的深度+1`，那么就应该把只有单边子树的情况列出来作为`base case`:

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        '''如果没有左子树，那么就是右子树的高度+1'''
        if not root.left:
            return self.minDepth(root.right) + 1
        '''如果没有右子树，那么就是左子树的高度+1'''
        if not root.right:
            return self.minDepth(root.left) + 1

        '''如果有左右子树，那么就返回(左子树的最小深度，右子树的最小深度) + 1'''
        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
```

#### 复杂度
`n`是树的节点个数
- 时间复杂度：`O(n)`
  我们遍历了所有节点
- 空间复杂度：
  最坏情况下，整棵树是非平衡的，例如每个节点都只有一个孩子，递归会调用 `n` （树的高度）次，因此栈的空间开销是 `O(n)` 。但在最好情况下，树是完全平衡的，高度只有`log(n)`，因此在这种情况下空间复杂度只有`O(log(n))`