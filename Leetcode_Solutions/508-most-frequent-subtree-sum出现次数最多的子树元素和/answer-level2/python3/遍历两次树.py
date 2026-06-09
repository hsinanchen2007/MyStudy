```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        def treeSum(node:TreeNode):
            now_node=node
            now_val=node.val
            # rs=node.val
            list1=[(now_node)]
            rs=0
            while list1:
                now_node=list1.pop(0)
                rs=rs+now_node.val
                if now_node.left:
                    list1.append((now_node.left))
                if now_node.right:
                    list1.append((now_node.right))
            
            return rs
        
        if root==None:
            return []
        
        now_node=root
        list1=[(now_node)]
        dic={}
        while list1:
            now_node=list1.pop(0)
            tmp=treeSum(now_node)
            if dic.get(tmp)==None:
                dic[tmp]=1
            else:
                dic[tmp]+=1
            if now_node.left:
                list1.append((now_node.left))
            if now_node.right:
                list1.append((now_node.right))
        
        dic=sorted(dic.items(), key=lambda x: -x[1])
        max_val=dic[0][1]
        rs=[]
        for key,val in dic:
            if val==max_val:
                rs.append(key)
            else:
                return rs
        return rs
```