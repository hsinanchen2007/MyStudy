### 解题思路
二叉树的右视图，通俗一点来说就是输出二叉树每一层最右边的节点————又是层次遍历出马的时候！
利用层次遍历，每一层遍历到最后一个节点时将该节点的值保存在数组中，最后将该数组输出即可。
**具体思路：**
1. 首先导入deque函数，然后判空，接着将根节点添加到双端队列queue中，再定义一个数组res用来存储每一层的最后一个节点值；
2. 当队列不为空时，计算当前队列的长度（也就是当前层的节点数），然后遍历当前层：
     · 弹出队列最左边的元素，但不做任何操作；
     · 判断取出节点的左右节点是否存在，若存在就追加进队列queue中；
3. 退出for循环时，当前层已经遍历完毕，此时的node是最后一次循环得到的节点（也就是当前层最右边的节点），这时就可将该节点值存入数组中；
4. 退出while循环时，表示队列已为空，已经遍历完毕，返回res即为所得。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        queue = deque([root])
        res = []
        while queue:
            n = len(queue)           
            for i in range(n):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.append(node.val)
        return res

```