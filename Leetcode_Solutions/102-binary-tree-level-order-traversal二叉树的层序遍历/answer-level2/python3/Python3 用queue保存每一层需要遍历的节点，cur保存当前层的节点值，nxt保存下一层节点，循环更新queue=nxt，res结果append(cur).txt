```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        queue = [root]  # 当前层，保存结果
        res = []
        
        # 添加每一层的每一个节点的左右孩子，按顺序，BFS按层
        while queue:
            '''把queue里面的当前层的节点保留，用于res保存值，cur里面保存的是节点的val，nxt保存的是下一层的节点，用于queue遍历'''
            cur = []  # 保存当前层的节点值，val的内容
            nxt = []  # 保存下一层的节点，是node，用于queue遍历
            
            for node in queue:
                cur.append(node.val)
                
                if node.left:
                    nxt.append(node.left)
                if node.right:
                    nxt.append(node.right)
            
            res.append(cur)
            # 更新每一层，queue用来遍历
            queue = nxt
            
        return res
```
