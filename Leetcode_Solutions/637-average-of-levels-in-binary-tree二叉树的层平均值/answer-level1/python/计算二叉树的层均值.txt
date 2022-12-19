### 解题思路
此处撰写解题思路
1.层次遍历
2.使用last和nlast指针，last指针指向每一层的最后一个节点，nlast指针最终去定位下一层的last指针
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
       last=root
       last_index=0
       if(root==None):
           return []
       level=[]
       level.append([])
       qeueue=[root]
       average1=[]
       while(len(qeueue)!=0):
           k=qeueue.pop(0)
           level[last_index].append(k.val)
           if(k.left):
               qeueue.append(k.left)
               nlast=k.left
           if(k.right):
               qeueue.append(k.right)
               nlast=k.right
           if(k==last and qeueue):
               level.append([])
               last=nlast
               last_index+=1
       print(level)
       for i in range(len(level)):
           if(len(level[i])>0):
               average1.append(sum(level[i])/len(level[i]))
       return average1
            

```