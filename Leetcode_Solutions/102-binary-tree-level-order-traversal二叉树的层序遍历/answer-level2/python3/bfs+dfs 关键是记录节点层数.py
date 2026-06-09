```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        
        # def bfs(node):
        #     level=0
        #     queue=collections.deque()
        #     queue.appendleft((node,level))
        #     while(len(queue)!=0):
        #         node,level=queue.pop()
        #         if node==None:
        #             continue
        #         temp.append((node,level))
        #         queue.appendleft((node.left,level+1))
        #         queue.appendleft((node.right,level+1))


        def dfs(node,level):
            if node==None:
                return 
            else:
                temp.append((node,level))
                dfs(node.left,level+1)
                dfs(node.right,level+1)

        if root==None:
            return []
        temp=[]
        dfs(root,0)
        res=[[] for i in range(max(temp,key=lambda i:i[1])[1]+1)]
        for item in temp:
            res[item[1]].append(item[0].val)
        return res
```
