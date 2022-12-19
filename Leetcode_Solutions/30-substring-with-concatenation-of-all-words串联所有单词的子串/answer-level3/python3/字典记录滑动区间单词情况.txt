![image.png](https://pic.leetcode-cn.com/4e43e589bb774202a00d33a70c071a79d5ef010f672ea4dea86f1e9e4f77ef3f-image.png)

起点分别是[0,words[0].length-1]，每次滑动words[0].length，通过一个字典记录滑动区间内按words[0].length来分割的单词情况，滑动一次就减去首单词加上新单词，然后跟words对比。

```
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n=len(words)
        if n==0:
            return []
        m=len(words[0])
        l=m*n
        ans=[]
        N=len(s)-l+1
        
        d=collections.defaultdict(int)
        for c in words:
            d[c]+=1
            
        for i in range(m):
            t=collections.defaultdict(int)
            for j in range(i,i+l,m):
                t[s[j:j+m]]+=1
            for j in range(i,N,m):
                if t==d:
                    ans+=[j]
                t[s[j:j+m]]-=1
                if t[s[j:j+m]]==0:
                    t.pop(s[j:j+m])
                t[s[j+l:j+l+m]]+=1
                
                
        return ans
```

暴力法，排序后元组化哈希也可以过，大概800-1000ms这样，但是理解比较简单


```
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n=len(words)
        if n==0:
            return []
        m=len(words[0])
        l=m*n
        ans=[]
        N=len(s)-l+1
        
        d=tuple(sorted(words))
        
        i=0
        while i<N:
            w=tuple(sorted([s[j:j+m] for j in range(i,i+l,m)]))
            if w==d:
                ans+=[i]
            i+=1
        
        return ans
```


乐色代码纯暴力算法也可以过，大概2000ms左右，其实主要费时在添加删除元素上，哈希后本质上就变成最顶上那种算法了

```
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n=len(words)
        if n==0:
            return []
        m=len(words[0])
        
        
        i=0
        while i<N:
            if i in ans:
                i+=1
                continue
            if s[i:i+m] in words:
                d=words.copy()
                j=i
                while s[j:j+m] in d:
                    d.remove(s[j:j+m])
                    j+=m
                if not d:
                    ans+=[i]
                    l=i
                    r=j
                    while s[r:r+m]==s[l:l+m] and l+m<N:
                        l+=m
                        r+=m
                        ans+=[l]
            i+=1
        return ans
```
