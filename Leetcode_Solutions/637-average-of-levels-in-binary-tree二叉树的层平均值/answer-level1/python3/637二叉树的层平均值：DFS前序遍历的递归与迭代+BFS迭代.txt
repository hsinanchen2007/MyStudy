一 DFS前序遍历的迭代形式
1.collections.defaultdict(list)：当字典中不存在key时返回list：[]
  traverse：记录深度及该深度所有节点，字典的key是深度，value是节点列表
2.栈stack记录遍历的节点及深度
时间复杂度O(N)，空间复杂度O(H)
```
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        traverse = collections.defaultdict(list)
        stack,node,n=[],root,-1
        while stack or node:
            while node:
                n +=1
                stack.append((n,node))
                traverse[n] += [node.val]
                node=node.left
            n,node=stack.pop()
            node=node.right
        return [sum(vals) / len(vals) for vals in traverse.values()]
```
        
        
二 DFS前序遍历的递归形式

```
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        traverse = collections.defaultdict(list)
        def dfs(node, n):
            if node:
                traverse[n] += [node.val]
                dfs(node.left,n+1)
                dfs(node.right,n+1)
        dfs(root, 0)
        return [sum(vals)/len(vals) for vals in traverse.values()]
```

        
        
三 BFS层次遍历，队列的迭代形式
时间复杂度O(N)，空间复杂度O(B)， B是最大的层节点数

```
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:       
        #BFS层次遍历的队列迭代形式
        res=[]
        queue=deque([root])#用于层次遍历的队列
        while queue:
            nodesum=0
            n=len(queue)
            for _ in range(n):
                node=queue.popleft()#队列FIFO
                nodesum += node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.append(nodesum/n)
        return res
```
