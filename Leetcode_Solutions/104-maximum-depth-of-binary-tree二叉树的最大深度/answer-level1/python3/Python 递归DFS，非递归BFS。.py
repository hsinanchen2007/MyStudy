### 解题思路
套用二叉树遍历的深度优先模板（代码上有解析），实现DFS。当然，也可以借助栈实现DFS，留给你实现。

使用Python内置的队列实现BFS。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import collections

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        '''
        # 52 ms	15.5 MB
        方法1：递归实现的DFS
        if root is None:
            return 0
        
        lenth = 0

        # DFS function
        lenth = self.helper(root, lenth)  

        return lenth
    
    def helper(self, node, lenth):
        
        # end of recursion 
        if node is None:
            return lenth
        
        # do some operation
        lenth += 1  

        # recursive left child follwed right child
        left_lenth = self.helper(node.left, lenth)
        right_lenth = self.helper(node.right, lenth)

        return max(left_lenth, right_lenth)
    '''

        '''
    
        方法二：非递归实现的BFS
        '''
        if root is None:
            return 0
        
        # initialize the queue and lenth
        queue = collections.deque()
        queue.append(root)
        lenth = 0
        
        # loop over the queue 
        while queue:
            lenth += 1
            for i in range(len(queue)):
                # print("lenth:{}, i:{}".format(lenth, i))
                node = queue.popleft()
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
        
        return lenth



```