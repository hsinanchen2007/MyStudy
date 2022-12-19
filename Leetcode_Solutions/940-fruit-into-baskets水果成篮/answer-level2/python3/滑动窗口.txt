有一个向前搜的过程，所以复杂度会大于o(n)我觉得
```
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        if len(tree)<=2:
            return len(tree)
        for i in range(1,len(tree)):
            if tree[i]!=tree[i-1]:
                break
        i-=1
        j=i+1
        res=0
        tmp=i+1
        d={tree[i],tree[i+1]}
        while j<len(tree):
            while j<len(tree) and tree[j] in d:
                tmp+=1
                res=max(res,tmp)
                j+=1
            if j==len(tree):
                break
            else:
                i=j-1
                d={tree[j],tree[i]}
                while tree[i]==tree[i-1]:
                    i-=1
                tmp=j-i
        return res
```