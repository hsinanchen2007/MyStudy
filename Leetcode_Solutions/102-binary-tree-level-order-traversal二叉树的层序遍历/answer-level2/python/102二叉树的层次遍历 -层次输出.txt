### 解题思路
二叉树的层次遍历，理解为特殊的BFS。
题目要求是层次的输出结果：[[3],[9,20],[15,7]]表示第一层是3，第二层是[9,20],第三层是[15,7]。
如果只是顺序输出：[3,9,20,15,7],则直接使用标准的BFS（visited可以省略）：
### 代码 --标准BFS输出1维数组表示访问顺序，如[3,9,20,15,7]
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        from collections import deque
        queue=deque()
        visited=set()
        queue.append(root)
        #visited.add(root)#visited可以不需要
        while queue:
            curNode=queue.popleft()
            res.append(curNode.val)
            if curNode.left:
                #if curNode.left not in visited:
                queue.append(curNode.left)
                    #visited.add(curNode.left)
            if curNode.right:
                #if curNode.right not in visited:
                queue.append(curNode.right)
                    #visited.add(curNode.right)
        return res

```
对于层次输出，需要做一点改变。应使**每一层次的节点等于当前队列里的节点**，这样则**需要每次都把当前层所有节点都弹出并处理完再处理下一层**

### 代码 --二维列表层次表示,如[[3],[9,20],[15,7]]

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        #层次遍历-->特殊的BFS：
        #这里需要输出不同的层次
        from collections import deque
        #special case
        if not root : return []
        queue=deque()
        visited=set()
        res=[]
        level=0#不同的层次
        queue.append(root)
        visited.add(root)
        while queue:
            res.append([])#增加一个层次的结果
            level_len=len(queue)#每层的节点数目为队列里的数目
            for i in range(level_len):#对一个层次的所有节点进行处理进行处理
                curNode=queue.popleft()
                res[level].append(curNode.val)
                #判断左右节点是否存在，若存在判断是否曾被扫描过，若没被扫描过且存在，入队加标记
                if curNode.left :
                    if curNode.left not in visited: 
                        queue.append(curNode.left)   
                        visited.add(curNode.left)
                if curNode.right:
                    if curNode.right not in visited:
                        queue.append(curNode.right) 
                        visited.add(curNode.right)
            level+=1#层次加1
        return res
```