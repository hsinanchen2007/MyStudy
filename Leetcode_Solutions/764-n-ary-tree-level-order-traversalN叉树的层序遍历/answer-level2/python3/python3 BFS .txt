广度优先搜索题，在搜索的同时加上层次信息，根据层次信息判断当前搜索结点的所属子列表。


```
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root: return []
        res = []
        queue = [(0,root)]                        #初始化
        while queue:
            level,node = queue.pop(0)
            if len(res) == level:                   #判断当前结点的层次信息
                res.append([node.val])
            else:
                res[level].append(node.val)
            if node.children:                       #将当前结点的子节点全部加到队列中
                for i in node.children:
                    queue.append((level+1,i))
        return res
```
