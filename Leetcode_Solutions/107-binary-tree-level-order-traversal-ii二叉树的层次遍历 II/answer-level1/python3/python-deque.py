```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        '''
自底向上遍历
        '''
        from collections import deque
        if not root: return []
        queue = deque()
        queue.appendleft(root)
        #print("queue.appendleft=",queue)
        res=[]
        while queue:
            tmp=[]
            n = len(queue)
            #print("len(queue)=",n)
            for _ in range(n):
                node = queue.pop()
                #print("node=",node)
                tmp.append(node.val)
                #print("tmp=",tmp)
                if node.left:
                    queue.appendleft(node.left)
                    #print("queue.appendleft=(left)",queue)
                if node.right:
                    queue.appendleft(node.right)
                    #print("queue.appendleft=(right)",queue)
            res.insert(0,tmp)
        return res
```
