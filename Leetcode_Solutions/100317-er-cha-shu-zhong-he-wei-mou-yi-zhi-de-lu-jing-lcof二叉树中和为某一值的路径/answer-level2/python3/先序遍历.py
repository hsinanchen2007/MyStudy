### 解题思路
先序遍历，从根节点往下访问一直到子节点所经过的一条路径，找出所有的路径，判断路径之和是否等于给定的整数

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def findRoad(root,num,sums,v,vList):
    if root != None:

        sums += root.val
        v.append(root.val)
        if root.left == None and root.right == None and num == sums:
            test = list(v)
            vList.append(test)
    
        if root.left != None:
            findRoad(root.left,num,sums,v,vList)
        if root.right != None:
            findRoad(root.right,num,sums,v,vList)
       
        #清除遍历路径
        sums -= v[-1]
        v.pop(-1)
        
    
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        v = []
        vList =[]
        findRoad(root,sum,0,v,vList)
        return vList
        
         


```