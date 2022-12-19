### 解题思路
其实用迭代方法也就是变相地实现一下递归而已，那么递归是怎么实现的呢？用栈，所以迭代方法也是用栈。这里需要注意的是，要保存每个节点的状态，拿中序遍历来说就是**记录当前节点的左子树是否遍历过**，如果不记录该状态会造成死循环。
以如下树为例：
```
    1
     \
      2
     /
    3
我们模拟压栈的过程：
（1）将1压栈。栈内为：[Node(1)]
（2）访问栈顶元素为Node(1)。由于没有左孩子，所以输出1，删除Node(1)并将其右孩子压入栈中。之所以删除Node(1)是因为其本身且左右孩子都已访问，该节点已经没有用处。栈内为：[Node(2)]
（3）访问栈顶元素为Node(2)。有左孩子，将左孩子压栈。栈内为：[Node(2), Node(3)]
（4）访问栈顶元素为Node(3)。没有左孩子，输出值3，删除Node(3)，同样因为没有右孩子所以也不需要压栈。栈内为：[Node(2)]。
（5）访问栈顶元素为Node(2)。注意，此时的状态和（3）步骤的状态一样，这就是为什么要用flag记录该节点的左孩子是否访问过，如果不记录并且分情况处理，就会陷入（3）（4）步骤的死循环。当我们记录后，此时我们会输出2，删除Node(2)，由于没有右孩子也不需要压栈。栈为空，退出程序。

下面代码给出递归方法和迭代方法的实现。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal_2(self, root):
        """ 递归方法
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []
        
        def get_res(node):
            if node is None:
                return 
            get_res(node.left)
            res.append(node.val)
            get_res(node.right)
        res = []
        get_res(root)
        return res
    
    def inorderTraversal(self, root):
        """ 迭代方法
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []
        stack = []
        res = []
        stack.append([root, 0])
        while len(stack):
            node = stack[-1][0]
            flag = stack[-1][1]
            if node.left and flag == 0:
                # 只有左子树存在并且未访问过才应该访问左子树
                stack[-1][1] = 1
                stack.append([node.left, 0])
            else:
                res.append(node.val)
                del stack[-1]
                if node.right:
                    stack.append([node.right, 0])
                flag = 0
        return res
```