```
class Codec:
    def encode(self, strs):
        if not strs:
            return ''
        count,i,indices,J=0,0,[],''.join(strs)
        for i in range(len(J)):
            if J[i]=='|':
                cur=0
                while J[i]=='|':
                    cur+=1
                    i+=1
                count=max(count,cur)
        cur=0
        for s in strs:
            cur+=len(s)
            indices.append(cur)
        div='|'*(count+1)
        res=div+' '.join(map(str,indices))+div+J
        return res

    def decode(self, s):
        strs=[]
        if s:
            count=0
            while count<len(s) and s[count]=='|':
                count+=1
            div='|'*count
            dummy,indices,meat=s.split(div)
            start=0
            for end in map(int,indices.split()):
                strs.append(meat[start:end])
                start=end
        return strs
```
