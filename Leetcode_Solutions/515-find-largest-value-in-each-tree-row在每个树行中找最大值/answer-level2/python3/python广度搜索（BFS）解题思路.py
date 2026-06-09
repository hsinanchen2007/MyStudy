### 解题思路
求每一行最大解一看就是广度搜索的题目。
使用一个先进先出的堆栈。
push到堆栈中的数据为[第n行的节点,n]
这样不管这一行有多少数据都不会弄错，可以根据行来判断。
然后每次把队首pop出来进行处理即可
有多少子节点搜push到队尾中待处理

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
    def largestValues(self, root: TreeNode):
        q = deque()
        result = []
        if root != None:
            q.append([root,0])
            while(len(q)>0):
                node,level = q.popleft()
                if level == len(result):
                    result.append(node.val)
                result[level] = max(result[level],node.val)

                if node.left:
                    q.append([node.left,level+1])
                if node.right:
                    q.append([node.right,level+1])
        return result
```