### 解题思路
思路主要是层序遍历，先建立一个队列，然后循环一层一层的加node。
唯一的不同点是我们需要知道队列的长度，即最右边的节点标号-最左边的节点标号+1
我们可以通过如下方法给每一层每个节点赋值，并把它放在队列中，假设一个节点当前标号是pos，那么它的左子树标号为
2 * pos，右子数标号为
2 * pos+1，这样就解决了

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        from collections import deque
        q=deque()
        q.append([root,0])
        res=0
        while q:
            width=[]
            for i in range(len(q)):
                node,pos=q.popleft()
                width.append(pos)
                if node.left:
                    q.append([node.left,pos*2])
                if node.right:
                    q.append([node.right,pos*2+1])
            res=max(res,width[-1]-width[0]+1)
        return res
            



       
```