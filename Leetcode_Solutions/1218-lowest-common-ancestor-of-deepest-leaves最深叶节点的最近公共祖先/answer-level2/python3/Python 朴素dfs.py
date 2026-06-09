![image.png](https://pic.leetcode-cn.com/905d953d88be7595e7b5c7aea6785f7d38dad814adc42d440f1748df2a81bbee-image.png)


```
'''
先把最深的叶子和叶子的所有祖先节点求出来，然后所有祖先结合求交集
找交集中的节点中深度最深的节点
'''

from typing import List, Dict, Any
class Solution:

    def dfs(self, root: TreeNode, path: List[int], leaf_rec: Dict[TreeNode, Any], depth, max_depth, node_depth):
        node_depth[root] = depth

        if root.left is None and root.right is None:
            leaf_rec[root] = (depth, set(path))
            max_depth[0] = max(max_depth[0], depth)
            return

        path.append(root)
        for child in [root.left, root.right]:
            if child:
                self.dfs(child, path, leaf_rec, depth+1, max_depth, node_depth)

        path.pop(-1)


    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        leaf_rec = {}
        node_depth = {}
        max_depth = [0]
        self.dfs(root, [], leaf_rec, 0, max_depth, node_depth)

        max_dep_leaf = [x for x in leaf_rec.keys() if leaf_rec[x][0] == max_depth[0]]
        if len(max_dep_leaf) == 1:
            return max_dep_leaf[0]

        all_parent_node = None
        for leaf in max_dep_leaf:
            if all_parent_node is None:
                all_parent_node = leaf_rec[leaf][1]
            else:
                all_parent_node = all_parent_node & leaf_rec[leaf][1]

        ans = None
        max_dep = -1
        for parent in all_parent_node:
            if node_depth[parent] > max_dep:
                max_dep = node_depth[parent]
                ans = parent
        return ans
```
