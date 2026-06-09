
```python []
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if s=="" or words==[]:
            return []
        dict1={}
        for a in words:
            if a in dict1.keys():
                dict1[a]+=1
            else:
                dict1[a]=1
        len1=len(words[0])*len(words)
        i=[]
        for b in range(0,len(s)-len1+1):
            c=0
            dict2={}
            while c<len1:
                word1=s[b+c:b+c+len(words[0])]
                if word1 in dict2.keys():
                    dict2[word1]+=1
                else:
                    dict2[word1]=1
                c+=len(words[0])
            if dict1!=dict2:
                continue
            
            i.append(b)
        return i
```
