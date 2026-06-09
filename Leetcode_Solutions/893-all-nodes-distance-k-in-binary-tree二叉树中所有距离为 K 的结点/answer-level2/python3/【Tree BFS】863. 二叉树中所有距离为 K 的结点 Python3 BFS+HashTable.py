### 解题思路
- 相似题型
- BFS
- 代码
- 复杂度

### 相似题型
- [102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/)
- [107. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/solution/er-cha-shu-xi-lie-107-er-cha-shu-de-ceng-ci-bian-l/)
- [103. 二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/er-cha-shu-xi-lie-103-er-cha-shu-de-ju-chi-xing-ce/)
- [637. 二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/solution/er-cha-shu-xi-lie-637-er-cha-shu-de-ceng-ping-jun-/)
- [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/er-cha-shu-xi-lie-111-er-cha-shu-de-zui-xiao-shen-/)
- [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/er-cha-shu-xi-lie-116-tian-chong-mei-ge-jie-dian-d/)
- [117. 填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/er-cha-shu-xi-lie-117-tian-chong-mei-ge-jie-dian-d/)
- [199. 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/tree-bfs-199-er-cha-shu-de-you-shi-tu-python3-bfs-/)
- [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/solution/er-cha-shu-xi-lie-200-dao-yu-shu-liang-python3-bfs/)


### BFS
占坑


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, K: int) -> List[int]:
        if not root:
            return []
        
        pmap = self.get_graph(root, None, {})
        
        res = []
        '''区别：是从target开始BFS，而不是root'''
        queue = [target]
        '''用于判断是否check过这个节点，用in能够达到O(1)的查询'''
        check = {}
        cur_level = 0
        
        '''BFS每一层就代表distance的距离，第一层就是distance=1'''
        while cur_level != K:
            nxt = []
            for node in queue:
                if node not in check:
                    check[node] = 1
                    if node.left and node.left not in check:
                        nxt.append(node.left)
                    if node.right and node.right not in check:
                        nxt.append(node.right)
                    if node in pmap and pmap[node] not in check:
                        nxt.append(pmap[node])
            cur_level += 1
            queue = nxt
            
        return [node.val for node in queue]
                    
        
    '''将tree转为undirected graph，记录父节点'''
    def get_graph(self, root, parent, pmap):
        if not root:
            return pmap
        if parent:
            pmap[root] = parent
        self.get_graph(root.left, root, pmap)
        self.get_graph(root.right, root, pmap)
        return pmap
```