### 解题思路
- 相似题型
- BFS
- 代码
- 复杂度

### 相似题型
- [102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/)
- [107. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/solution/er-cha-shu-xi-lie-107-er-cha-shu-de-ceng-ci-bian-l/)
- [103. 二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/er-cha-shu-xi-lie-103-er-cha-shu-de-ju-chi-xing-ce/)
- [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/er-cha-shu-xi-lie-111-er-cha-shu-de-zui-xiao-shen-/)
- [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/er-cha-shu-xi-lie-116-tian-chong-mei-ge-jie-dian-d/)
- [117. 填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/er-cha-shu-xi-lie-117-tian-chong-mei-ge-jie-dian-d/)
- [199. 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/tree-bfs-199-er-cha-shu-de-you-shi-tu-python3-bfs-/)
- [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/solution/er-cha-shu-xi-lie-200-dao-yu-shu-liang-python3-bfs/)
- [863. 二叉树中所有距离为 K 的结点](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/solution/tree-bfs-863-er-cha-shu-zhong-suo-you-ju-chi-wei-k/)



### BFS
指路：[102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/) 的题解

**重点**：`树即为directed graph`，层次遍历就可以用`Breadth Search First`完成

**区别**：不再保存每一层的全部数值，而是求一个平均值，即为：`sum(cur)/len(cur)`

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return []

        res = []
        queue = [root]
        
        while queue:
            cur = []  # 保存当前层的遍历值，因为queue保存的是TreeNode类型
            nxt = []  # 保存下一层的节点
            for node in queue:
                cur.append(node.val)
                if node.left:
                    nxt.append(node.left)
                if node.right:
                    nxt.append(node.right)
 
            '''记录平均值'''
            res.append(sum(cur)/len(cur))  
            queue = nxt  # 每次更新queue
        
        return res
```

### 复杂度
`n`是树的节点个数
- 时间复杂度：`O(n)`
  我们遍历了所有节点
- 空间复杂度：`O(m)`
  我们需要用辅助的队列来存放树的一部分节点，`m`为树中每一层节点个数的最大值
  `res`保存的是树的高度的节点数，但是肯定不大于最大层的节点个数