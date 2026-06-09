### BFS
![image.png](https://pic.leetcode-cn.com/2d2f64fb872da7017424a1991f353ec04430fe1cd33ebda772f5753e4b632cd7-image.png)

- 我们使用BFS的思路进行存储二叉树中的节点,在打印,其中使用了队列的性质
- 首先将第一个结点放入我们的`deque`中,如果节点不为空,我们很容易的知道第一层的输出就是这个节点.我们把这个节点存入到第一层的结果中,接着遍历当前的左右节点,若果不是空的话就把它加入到临时数组`out`中,然后更新`deque = out`,这时的`deque`就是我们下一层的节点,以此类推,直到我们的`deque`中没有节点,说明遍历完成.

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
        if not root:
           return []
        deque = [root]
        result = []
        while deque:
            out = []
            temp = []
            for i in deque:
                temp.append(i.val)
                if i.left:
                    out.append(i.left)
                if i.right:
                    out.append(i.right)
            result.append(temp)
            deque = out  
        return result





```