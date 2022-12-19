```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        ## BFS  层次遍历
        ret = []
        queue =  collections.deque()
        if root == None:
            return []
        queue.append(root)
        depth = 0

        while queue:
            temp = []
            depth = depth+1 
            for _  in range(len(queue)):
                node = queue.popleft()
                temp.append(node.val)
                if node.left !=None:
                    queue.append(node.left)

                if node.right !=None:
                    queue.append(node.right)
            #
            if depth%2==1:
                ret.append(temp)
            else:
                temp.reverse()
                ret.append(temp)
        return ret 
```
