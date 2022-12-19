### 解题思路
思路：BFS，这次不止要将左右结点送入队列，且加上深度
结构：队列+反转

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        listnew=[]
        result=[]
        n=0
        if not root:
            return []
        result.append([root.val])
        a=[0]
        listnew.append((n,root.left,root.right)) #n为深度
        while listnew:
            n,node1,node2=listnew.pop(0)
            print(n)
            if n!=a[0]:  
                if len(a)>1:                           
                    result.append(a[1:])
                #换层时添加值，然后重置这一行数据
                a=[n]   
            if not node1 and not node2: #左右结点不错在，什么都不做
                continue               
            elif not node1 and node2:              
                a.append(node2.val) 
                n+=1
                listnew.append((n,node2.left,node2.right))  
            elif not node2 and node1:
                a.append(node1.val) 
                n+=1
                listnew.append((n,node1.left,node1.right))
            else:                           #左右结点都存在时
                a.append(node1.val)
                a.append(node2.val)                     
                n+=1
                listnew.append((n,node1.left,node1.right))
                listnew.append((n,node2.left,node2.right))
        result.reverse()
        return result
```