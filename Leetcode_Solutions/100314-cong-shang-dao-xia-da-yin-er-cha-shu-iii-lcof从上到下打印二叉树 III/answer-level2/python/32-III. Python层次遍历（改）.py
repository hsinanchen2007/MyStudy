### 解题思路
对于树的层次遍历常用的方法是用队列的方法，这道题也不例外，只不过因为要区分每一层所以在向队列中存储节点的时候还要存储节点所在的层数，而“之”字形输出说白了就是根据层数的奇偶性改变新节点在那一行的插入位置，即如果层数为偶数（从0开始编号）则插在当前层节点列表尾部，否则插在头部。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        queue = [(root, 0)]
        cur_level = 0
        res = [[]]
        while len(queue):
            node, level = queue[0]
            if level == cur_level:
                if level & 1 == 0:
                    res[-1].append(node.val)
                else:
                    res[-1].insert(0, node.val)
            else:
                res.append([node.val])
                cur_level += 1
            if node.left:
                queue.append((node.left, level + 1))
            if node.right:
                queue.append((node.right, level + 1))
            del queue[0]
        return res
```