### 解题思路
1、使用queue来搞定，先入根节点，然后一直判断不为空则进行（循环中会更新的）；
2、每次处理一层的所有节点；
3、每次先算出队列中的所有元素，其实就是一层的所有元素；然后写内部for循环遍历所有该层的节点；
4、因为每次先算出来level_size，所以for循环中的新增，并不会影响该层的输出；

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


import collections

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        # 这是一个list[list]，返回最终结果
        result = []
        # 这是一个queue
        queue = collections.deque([root])
        # 只要queue不为空，则循环
        while queue:
            level_size = len(queue)

            curr_level_datas = []
            for _ in range(level_size):
                node = queue.popleft()
                curr_level_datas.append(node.val)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            result.append(curr_level_datas)
        return result

```