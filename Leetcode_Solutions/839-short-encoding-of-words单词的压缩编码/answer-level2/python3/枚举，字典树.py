### 解题思路
思路其他题解说的很好了，我集中了一下枚举法，包调用，和手写字点树三种方法的代码

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        # way 1 : set 枚举
#         good = set(words)
#         for word in words:
#             for i in range(1,len(word)):
#                 good.discard(word[i:])
        
#         return sum(len(ele)+1 for ele in good)
    
    
        # way 2 : trie 前缀树
#         words = list(set(words))
#         Trie = lambda:collections.defaultdict(Trie)
#         trie = Trie()
        
#         nodes = [reduce(dict.__getitem__, word[::-1], trie) for word in words]
#         # 实例dictDemo["key0"]就类似上面的的操作

#         return sum(len(word) + 1
#                    for i, word in enumerate(words)
#                    if len(nodes[i]) == 0)
    
        # 手写前缀树
        class Node:
            def __init__(self,l):
                self.l = l
                self.children = {}
                
        def build(t,w):
            if not w:
                return 
            if w[-1] not in t.children:
                t.children[w[-1]] = Node(t.l + 1)
            build(t.children[w[-1]],w[:-1])
         
        ans = 0 
        def vis(t):
            nonlocal ans 
            if len(t.children) == 0:
                if t.l > 0:
                    ans += (t.l + 1)
            # 如果是没用value函数，返回的就是键，是字符型的
            for c in t.children.values():
                vis(c)
    
        root = Node(0)
        for w in words:
            build(root,w)
        #print(root.children) 
        vis(root) 
        
        return ans
```