使用字典保存树节点关系，自底向上求和，碰到和为0的节点，自上而下DFS删除节点，最后返回剩余节点数目

提交结果    执行用时    内存消耗    语言
通过       656 ms	  30.9 MB	Python3

```
class Node:
    def __init__(self,val):
        self.val=val

class Solution:
    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) -> int:
        
        if not value:
            return 0
        km={}
        self.nl=[Node(i) for i in value]
        head=None
        for i in range(nodes):
            if parent[i]==-1:
                head=self.nl[i]
            else:
                key=self.nl[parent[i]]
                value=self.nl[i]
                if key in km:
                    km[key].append(value)
                else:
                    km[key]=[value]
        
        def find(h,km):
            if not h:
                return 0
            if h not in km:
                if h.val==0:
                    remove(h,km)
                return h.val
            val=h.val
            if h in km:
                for node in km[h]:
                    val+=find(node,km)
            if val==0:
                remove(h,km)
            return val
            
        def remove(node,km):
            if not node:
                return
            if node in self.nl:
                self.nl.remove(node)
            if node in km:
                for n in km[node]:
                    remove(n,km)
        find(head,km)
        
        return len(self.nl)
```
