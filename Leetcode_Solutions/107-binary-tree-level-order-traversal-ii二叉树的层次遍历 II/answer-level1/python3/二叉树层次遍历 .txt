```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        # BFS   利用队列
        ret = []
        queue = collections.deque() #双端队列
        if root==None: return []  
        queue.append(root)

        while queue:
            temp = []
            for _ in range(len(queue)):
                node = queue.popleft()
                temp.append(node.val)
                if node.left : queue.append(node.left)
                if node.right : queue.append(node.right)
            ret.insert(0,temp)
        return ret
```
