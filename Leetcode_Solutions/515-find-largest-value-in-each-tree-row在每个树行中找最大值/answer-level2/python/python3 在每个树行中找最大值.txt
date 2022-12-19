### 解题思路
看见行，首先想到层次遍历，然后就是双端队列。
1. 层次遍历每一行，最开始将最大值初始化为负无穷，然后依次将遍历到的节点值与最大值进行比较，取其中较大的一个赋给最大值，这之前可以判断该节点的左右节点是否存在，若存在就添加到队列中；
2. 每一层遍历完之后就将得到的maxium添加到数组result中保存；
3. 整个树遍历完也即队列为空后，返回result即可。

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
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        queue = deque([root])
        result = []
        while queue:
            n = len(queue)
            maxium = float('-inf')
            for i in range(n):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                maxium = max(maxium, node.val)
            result.append(maxium)
        return result
            


```