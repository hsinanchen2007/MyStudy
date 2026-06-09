### 解题思路
1. 分别序列化每一层 
2. 用不同的符号分隔层，每一层的结点，每个节点内的值和子节点的索引
3. 例子 '1-0,1,2|2-+3-0,1+4-|7-+8-'

### 代码

```python3
class Codec:
    
    def serialize(self, root: 'Node') -> str:
        """Encodes a tree to a single string.

        :type root: Node
        :rtype: str
        """
        if not root:
            return ''
            
        levels = []
        q = [root]
        while q:
            nq = []
            children = []
            for node in q:
                cs = []
                for c in node.children:
                    cs.append(len(nq))
                    nq.append(c)
                children.append(cs)
            
            s = '+'.join(['-'.join([str(v), ','.join(map(str, c))]) for v, c in zip([node.val for node in q], children)])
            levels.append(s)
            q = nq
        
        ans = '|'.join(levels)
        
        return ans
        

    
    def deserialize(self, data: str) -> 'Node':
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: Node
        """
        if not data:
            return None
        
        levels = data.split('|')
        prelevel = []
        for level in reversed(levels):
            
            nodesstr = level.split('+')
            nprelevel = []
            for nodestr in nodesstr:
                ns = nodestr.split('-')
                val = ns[0]
                children = []
                if len(ns) > 1 and len(ns[1]) > 0:
                    childrenIndex = [int(x) for x in ns[1].split(',')]
                    children = [prelevel[i] for i in childrenIndex]
                
                node = Node(val, children)
                nprelevel.append(node)
            prelevel = nprelevel
            
        return prelevel[0]
        
```