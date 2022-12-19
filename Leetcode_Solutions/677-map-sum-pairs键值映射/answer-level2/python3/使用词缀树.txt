### 解题思路
运用词缀树来解决问题，值得一提的是python3中有现成的collections库来实现；中间节点的value为0，这样在加和的时候不会影响结果。
sum()分为两步，首先遍历单词（如果出现找不到结点的情况就意味着根本不存在这样的前缀）得出末尾节点；第二步是针对以末尾节点为头节点的子树，统计子树中所有节点的value之和（使用dfs搜索即可）。
最后需要注意一点，如果sum的参数恰好是整个单词，那就意味着末尾节点恰好是叶节点，如果传入dfs()就忽略了该节点的值（一般时刻因为value=0所以无所谓），因此要在一开始就赋值s=root.value以防万一

### 代码

```python3
from collections import defaultdict
class node:
    def __init__(self):
        self.value=0
        self.next=defaultdict(node)
class MapSum:
    def __init__(self):
        self.item=node()
    def insert(self, key: str, val: int):
        temp=self.item
        for i in key:
                temp=temp.next[i]
        temp.value=val
    def sum(self, prefix: str):
        temp=self.item
        for i in prefix:
            if(i in temp.next.keys()):
                temp=temp.next[i]
            else:
                return 0
        res=temp.value
        res+=self.dfs(temp,0)
        return res
    def dfs(self,root,s):
        for i in root.next:
            s+=root.next[i].value
            s=self.dfs(root.next[i],s)
        return s
```