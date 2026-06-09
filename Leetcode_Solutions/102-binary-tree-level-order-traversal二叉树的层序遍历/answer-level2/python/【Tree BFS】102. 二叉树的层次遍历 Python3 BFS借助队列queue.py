
### 2020/4/4 更新
这是五个多月前写的题解了，仍要继续努力，只要努力，多远都可以到达。

### 解题思路
- 相似题型
- BFS
- 代码
- 复杂度

### 相似题型
- [107. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/solution/er-cha-shu-xi-lie-107-er-cha-shu-de-ceng-ci-bian-l/)
- [103. 二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/er-cha-shu-xi-lie-103-er-cha-shu-de-ju-chi-xing-ce/)
- [637. 二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/solution/er-cha-shu-xi-lie-637-er-cha-shu-de-ceng-ping-jun-/)
- [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/er-cha-shu-xi-lie-111-er-cha-shu-de-zui-xiao-shen-/)
- [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/er-cha-shu-xi-lie-116-tian-chong-mei-ge-jie-dian-d/)
- [117. 填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/er-cha-shu-xi-lie-117-tian-chong-mei-ge-jie-dian-d/)
- [199. 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/tree-bfs-199-er-cha-shu-de-you-shi-tu-python3-bfs-/)
- [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/solution/er-cha-shu-xi-lie-200-dao-yu-shu-liang-python3-bfs/)
- [863. 二叉树中所有距离为 K 的结点](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/solution/tree-bfs-863-er-cha-shu-zhong-suo-you-ju-chi-wei-k/)



### BFS
这是一棵树的每一层：
![image.png](https://pic.leetcode-cn.com/a710ed69cc228dfc7b612fb051e54d6421fd91db9f81d264bea04cdff86c41b9-image.png)


将它旋转一下，其实看起来就是`一个graph`，一个`directed connected graph`，而我们想要的每一层，就是`breadth search first`：

![image.png](https://pic.leetcode-cn.com/41a21d9ca9b304fa69289744828db5e56867f97a40d87289b2f1a8f8f773cf3d-image.png)

那么我们就可以用一个`BFS`来完成层次遍历，对于`BFS`，我们需要用一个辅助队列`queue`，【附：对于`DFS`我们需要用一个辅助栈`stack`】，那么我们就可以完成我们的代码了

### 代码

```python
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        
        if not root:
            return []
        
        queue = [root]  # 保存每一层要bfs的节点
        res = []
        
        while queue:
            cur = []  # 保存当前层的遍历值，因为queue保存的是TreeNode类型
            nxt = []  # 保存下一层的节点
            for node in queue:
                cur.append(node.val)
                if node.left:
                    nxt.append(node.left)
                if node.right:
                    nxt.append(node.right)
            res.append(cur)
            queue = nxt  # 每次更新queue
            
        return res
```

![image.png](https://pic.leetcode-cn.com/42cd6bcbe63eaa697cbbbb24382bd2df0c2673b457f40ee55d05560c982b06f8-image.png)

### 复杂度
`n`是树的节点个数
- 时间复杂度：`O(n)`
  我们遍历了所有节点
- 空间复杂度：`O(n)`
  保存输出结果的数组包含 n 个节点的值

### 2.叨叨
写不动了，留个坑，希望领导批我的电子流【2019.11.06】拜托了！
