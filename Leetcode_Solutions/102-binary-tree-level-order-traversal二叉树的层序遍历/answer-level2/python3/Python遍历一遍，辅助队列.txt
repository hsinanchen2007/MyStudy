### 解题思路
两点需要注意 1、用元组记录当前节点的层数；2、当辅助队列为None时，还有最后一层的节点没有加入到结果集中，需要单独加入   时间复杂度O（N），空间复杂度O（N）

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        from collections import deque
        res = []
        if not root:
            return res
        queue = deque()
        queue.append((root,0))
        floor = 0
        floor_nodes = []
        while queue:
            tmp,tmp_f = queue.popleft()
            if tmp_f>floor:
                res.append(floor_nodes)
                floor_nodes = []
                floor+=1
            if tmp_f==floor:
                floor_nodes.append(tmp.val)
                if tmp.left:
                    queue.append((tmp.left,tmp_f+1))
                if tmp.right:
                    queue.append((tmp.right,tmp_f+1))
        res.append(floor_nodes)   
        return res

```