### 解题思路
深搜遍历，按照坐标记录点，用字典保存，最后排序即可!

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.d={}
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        def DFS(root, x, y):
            if not root:
                return 

            if y in self.d:
                if x in self.d[y]:
                    self.d[y][x].append(root.val)
                else:
                    self.d[y][x]=[root.val]
            else:
                self.d[y]={x:[root.val]}
            DFS(root.left, x+1, y-1)
            DFS(root.right, x+1, y+1)
        
        DFS(root, 0, 0)
        res=[]
        d=[v for c,v in sorted(self.d.items())]
        for subD in d:
            temp=[]
            for _, v in sorted(subD.items()):
                temp+=sorted(v)
            res.append(temp)
        return res

```