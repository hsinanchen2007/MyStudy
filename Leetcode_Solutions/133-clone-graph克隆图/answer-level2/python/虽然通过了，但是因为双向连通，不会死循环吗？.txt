### 解题思路
假设图是 1<-->2
这两个节点相互连接
那返回的形式不是1的邻居有2,2的邻居有1,1的邻居有2，这样无限循环下去吗
哦哦。莫非在死循环之前存就可以了。我调整下存history的位置看一看
没错。先存node，再设置邻居
这样邻居回到这个节点的时候就不会继续循环了

### 代码

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""
class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        history={}
        def get_node(node):
            if not node:
                return node
            if   node.val in history:
                return history[node.val]
            
            
            newnode=Node(node.val,[])
            history[node.val]=newnode
            # print newnode
            newnode.neighbors=[get_node(x) for x in node.neighbors]
            return newnode
        
        return get_node(node)


```