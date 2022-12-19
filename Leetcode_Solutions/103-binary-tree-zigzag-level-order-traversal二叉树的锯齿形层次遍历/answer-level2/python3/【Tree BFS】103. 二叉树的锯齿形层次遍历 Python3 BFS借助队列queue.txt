### 解题思路
- 相似题型
- BFS
- 代码
- 复杂度

### 相似题型
- [102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/)
- [107. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/solution/er-cha-shu-xi-lie-107-er-cha-shu-de-ceng-ci-bian-l/)
- [637. 二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/solution/er-cha-shu-xi-lie-637-er-cha-shu-de-ceng-ping-jun-/)
- [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/er-cha-shu-xi-lie-111-er-cha-shu-de-zui-xiao-shen-/)
- [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/er-cha-shu-xi-lie-116-tian-chong-mei-ge-jie-dian-d/)
- [117. 填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/er-cha-shu-xi-lie-117-tian-chong-mei-ge-jie-dian-d/)
- [199. 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/tree-bfs-199-er-cha-shu-de-you-shi-tu-python3-bfs-/)
- [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/solution/er-cha-shu-xi-lie-200-dao-yu-shu-liang-python3-bfs/)
- [863. 二叉树中所有距离为 K 的结点](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/solution/tree-bfs-863-er-cha-shu-zhong-suo-you-ju-chi-wei-k/)


### BFS
指路：[102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/) 的题解

**重点**：`树即为directed graph`，层次遍历就可以用`Breadth Search First`完成

**区别**：需要单独一个变量`dep`保存当前层数，根据层数的奇偶来决定是保存当前层的节点值的正序还是逆序：当`dep`是偶数时，保存正序，当`dep`是奇数时，保存逆序

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        res = []
        queue = [root]  # 保存每一层要bfs的节点
        dep = 0  '''用于记录每一层的层数'''
        
        while queue:
            cur = []  # 保存当前层的遍历值，因为queue保存的是TreeNode类型
            nxt = []  # 保存下一层的节点
            for node in queue:
                cur.append(node.val)
                if node.left:
                    nxt.append(node.left)
                if node.right:
                    nxt.append(node.right)
            
            '''根据层数的奇偶来决定保存正序还是逆序'''
            if dep % 2 == 0:
                res.append(cur)
            else:
                res.append(cur[::-1])
            queue = nxt  # 每次更新queue
            dep += 1
            
        return res
```

### 复杂度
`n`是树的节点个数
- 时间复杂度：`O(n)`
  我们遍历了所有节点
- 空间复杂度：`O(n)`
  保存输出结果的数组包含 n 个节点的值