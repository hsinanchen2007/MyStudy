### 解题思路
就这?

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        self.returnList=[]
        leafLock=False
        nowsum=root.val if root else 0
        path=[root]
        while len(path)>0 and path[-1]:
            node=path[-1]
            
            if node.left is None and node.right is None:
                if not leafLock:
                    leafLock=True
                    if nowsum==sum:
                        self.returnList.append([i.val for i in path])
                nowsum-=node.val
                path.pop()
            if node.left is not None:
                nowsum+=node.left.val
                path.append(node.left)
                node.left=None
                leafLock=False
                continue
            if node.right is not None:
                nowsum+=node.right.val
                path.append(node.right)
                node.right=None
                leafLock=False
                continue

        return self.returnList

   
```