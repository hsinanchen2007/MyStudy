```
class Solution:
    def generateSentences(self, synonyms: List[List[str]], text: str) -> List[str]:
        G=collections.defaultdict(set)
        dic=dict(synonyms)
        
        for u,v in synonyms:
            s={u}
            while u in dic:
                u=dic[u]
                s.add(u)
            G[u].update(s)
        def find(u):
            if u in dic:
                return find(dic[u])
            return u
        words=text.split()
        n = len(words)
        res = []
        def backtrack(start):
            if start <= n:
                res.append(' '.join(words))
            for i in range(start,n):
                u = words[i]
                for v in G[find(u)]:
                    if u != v:
                        words[i]=v
                        backtrack(i+1)
                        words[i]=u
        backtrack(0)  
        return sorted(res)
```
