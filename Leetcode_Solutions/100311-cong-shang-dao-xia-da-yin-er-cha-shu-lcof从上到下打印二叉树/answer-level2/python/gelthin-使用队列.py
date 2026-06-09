### 解题思路
使用一个 list 来模拟队列
+ 每次从头部添加 queue = [new_val] + queue
+ 每次从末尾返回 queue.pop(-1),
但这样非常缓慢，list 使用链表实现的

+ 每次从尾部添加 queue.append(new_val)
+ 但似乎也可以 queue.pop(0)啊

进队列加一个判断，对于 None 值不进入队列，只有有效值才进入队列
这一做法有点类似习题 [695. 岛屿的最大面积 gelthin-DFS](https://leetcode-cn.com/problems/max-area-of-island/solution/gelthin-dfs-by-gelthin/)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        result = []
        if root == None:
            return result
        queue = [root]  # 每次往头部添加   
        while queue:
            A = queue.pop(-1) # 从最后面弹出
            result.append(A.val)
            if A.left:
                queue = [A.left] + queue
            if A.right:
                queue = [A.right] + queue
        return result



```
#### 重新用 list 模拟队列， 快不少
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        result = []
        if root == None:
            return result
        queue = [root]  # 每次往尾部添加   
        while queue:
            A = queue.pop(0) # 从最前面弹出
            result.append(A.val)
            if A.left:
                queue.append(A.left)
            if A.right:
                queue.append(A.right)
        return result
```