```
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.children = []

class Solution:

    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        
        dicts = {}
        for p in pid:
            node = TreeNode(p)
            dicts[p] = node
            
        for i in range(len(ppid)):
            if ppid[i] > 0:
                node = dicts.get(ppid[i])
                node.children.append(dicts.get(pid[i]))
        kills = []
        kills.append(kill)
        kills = self.getChildren(dicts[kill], kills)
        return kills
                
        
    def getChildren(self, node, kills):
        if node.children ==[]:
            return kills
        for child in node.children:
            kills.append(child.val)
            kills = self.getChildren(child, kills)
        return kills
```
