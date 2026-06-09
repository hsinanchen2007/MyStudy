### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        # self.res=""
        # q=deque()
        # if root:
        #     q.append(root)
        #     self.res+=str(root.val)+'#'
        # while q:
        #     node=q.popleft()
        #     if node.left:
        #         q.append(node.left)
        #         self.res+=str(node.left.val)+'#'
        #     if node.right:
        #         q.append(node.right)
        #         self.res+=str(node.right.val)+'#'
        def trace(root):
            if not root :return 
            self.res+=str(root.val)+'#'
            if root.left:trace(root.left)
            if root.right:trace(root.right)
        self.res=""
        trace(root)
      #  print(self.res)
        return self.res





    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
#插入时要转为int，否则会报错
        def dfs_insert(root,i):
            if i>root.val:
                if root.right:
                    dfs_insert(root.right,i)
                else:
                    root.right=TreeNode(i)
            elif i<=root.val:
                if root.left:
                    dfs_insert(root.left,i)
                else:
                    root.left=TreeNode(i)
        if data:
            data=data[:-1]
            data1=data.split('#')
            root=TreeNode(int(data1[0]))
            for i in data1[1:]:
                dfs_insert(root,int(i))
        else:return 
        return root
            
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```