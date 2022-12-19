建两个字典,dict01放{单词:单词出现的次数},按定长(所有单词的长度)遍历s,把遍历到的单词放入dict02,此时次数不能超过dict01中的值
```
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        res=[]
        if not words or len(s)<len(words[0]):
            return res
        dict01={}
        for v in words:
            if v in dict01:
                dict01[v]+=1
            else:
                dict01[v]=1
        n=len(words)
        w=len(words[0])
        l=n*w
        for i in range(len(s)-l+1):
            dict02 = {}
            t=i
            while t<=i+(n-1)*w:
                if s[t:t+w] in dict01:
                    if s[t:t+w] in dict02:
                        dict02[s[t:t+w]]+=1
                        if dict02[s[t:t+w]]>dict01[s[t:t+w]]:
                            break
                        else:
                            t+=w
                    else:
                        dict02[s[t:t+w]]=1
                        t+=w
                else:
                    break
            if t==i+l:
                res.append(i)
        return res
```
