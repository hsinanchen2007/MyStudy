### 解题思路
用一个栈stack来实现后序遍历。

后续遍历，需要先输出每个子树的左节点，然后右节点，最后输出父节点。
这里需要有一个数据结构记录住当前节点的的父节点和兄弟节点。

例如树：
        1
    2        3
4       5      6   7

1.  节点（1）的右存在，我们把 节点（3）推入stack，然后推入节点（1），把root设为节点（1）的左。
    stack [3, 1]
    root: (2)
    res： []

2.  节点（2）的右存在，我们把节点（5）推入stack，然后推入节点（2），把root设为节点（2）的左。
    stack: [3, 1, 5, 2]
    root: (4)
    res: []

3. 节点（4）的右不存在，我们把节点（4）推入栈。root设为（4）的左。
    stack: [3, 1, 5, 2, 4]
    root: None
    res: []

此时，第一步完成，因为节点有自己对数据结构，我们的栈叶保留了处理的顺序。

4.  当前root 是 None。所以从stack 里面 pop 出 节点（4），保存为root。
    root 没有 右节点，说明这个 root 是 leaf，
    将 root的值输出，将root 设为 None。此时：
    stack: [3, 1, 5, 2]
    root: None 
    res: [4]

5. 当前 root 是 None， 所以从 stack pop 出 节点 （2）存为 root。
    此时 stack： [3, 1, 5]
    root （2） 有右元素 （5）， 这个（5）正好与 stack 顶端的 （5）一样，说明我们该处理这个（5）节点。把（5）从stack pop掉，然后把 （2）推入stack， 然后将root设为root的右节点（5）。
    stack: [3, 1, 2]
    root: (5)
    res: [4]

6. 当前 root 是（5）， root没有右节点，把root推入stack， 把root设为当前root的左节点。
    stack: [3, 1, 2, 5]
    root: None
    res: [4]

7. 当前 root 是None, stack pop （5）设为 root， 此时root没有右分支。输出5， 将root设为root的右分支。
    stack: [3, 1, 2]
    root: None
    res: [4, 5]

8. 当前 root 是None， stack pop （2）设为root。
    stack： [3, 1]
   root的右分支是（5），与当前stack顶端的元素（1）不一样，说明当前root的右分支已经处理完毕。
    输出 (2), root 设为 None.
    stack: [3, 1]
    root: None
    res: [4, 5, 2]

9. 当前 root 是 None，stack pop (1) 设为 root。 
   stack: [3]
    root (1) 的右分支 （3） 与 stack 顶部的元素（3）一样，所以stack pop 掉 （3）。
    stack：[]
    将 root （1）存入stack， 将root设为 root（1）的右 （3）。
    stack: [1]。

10. 重复6， 7， 3 就会清空stack，root为None，res：【4，5，2，3，1】


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        res = []
        stack = []
        while(True):

            # Loop to the most left node
            # during the loopping, push node's right and self 
            # to stack, that remeber the processing order
            while(root):
                # Push root right child and then root to stack
                if root.right is not None:
                    stack.append(root.right)
                stack.append(root)
                # set root as root's left child
                root = root.left
            
            # Pop an item from stack and set it as root
            root = stack.pop()

            # If the popped item has a right child 
            # and the right child is not processed yet,
            # then mack sure the right child is processed before toot
            if (root.right is not None) and len(stack) > 0  and (stack[-1] == root.right):
                stack.pop()
                stack.append(root)
                root = root.right 
            else:
                res.append(root.val)
                root = None
            
            if (len(stack) <= 0):
                break
        return res
```