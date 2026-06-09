### 解题思路
二叉树的层次遍历要用到队列。
1. 首先定义一个数组res用来保存每一层的节点数组，定义一个队列queue，将根节点添加进去；
2. 需要有一个循环while，什么时候队列空了，就代表遍历结束了：
     **·**记录下当前队列的长度，也就代表这一层的节点数；
     **·**定义一个数组list用来保存当前队列也即当前层的节点值；
     **·**遍历完这一层的所有节点：
        ---弹出队首的节点 cur = queue.pop(0)
        ---将弹出的节点的val值添加到list数组中 list.append(cur.val)
        ---若当前节点的左孩子不为空（当前节点的左孩子肯定属于下一层），就将左孩子添加到队列里去
        ---同理若当前节点的右孩子不为空，也将右孩子添加到队列里去
     **·**遍历完之后要将list添加到res里 res.append(list)
3. 最后返回res即可。

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
        if not root:
            return []    
        res = []
        queue = [root]
        while queue:
            n = len(queue)
            list = []
            for i in range(0, n):
                cur = queue.pop(0)
                list.append(cur.val)
                if cur.left:
                    queue.append(cur.left)
                if cur.right:
                    queue.append(cur.right)
            res.append(list)
        return res

```