148ms,93.38%，没用递归，树转表是从前往后，表转树是从后往前，翻评论看到了可以用self.root来做，吐血了。

```
def serialize(self, root):
        if not root:return []
        d=[root]
        i=0
        n=1
        while i<n:
            if d[i]:
                d.append(d[i].left)
                d.append(d[i].right)
                n+=2
            i+=1
        i=n-1
        while i>=0:
            if d[i]:
                break
            d.pop()
            i-=1
        s=','.join([str(r.val) if r else 'null' for r in d])
        return s
        
        
    def deserialize(self, data):
        if not data:return 
    
        d=data.split(',')
        
        n=len(d)
        if n==1:return TreeNode(int(d[0]))
        a=[0]*n
        k=1
        for i in range(n):
            if d[i]!='null':
                a[i]=k
                k+=2
                if k>=n:
                    break
        
        b=[None]*n
        for i in range(n-1,-1,-1):
            if d[i]!='null':
                b[i]=TreeNode(int(d[i]))
                if a[i]>0:
                    if d[a[i]]!='null':
                        b[i].left=b[a[i]]
                    if a[i]+1<n:
                        if d[a[i]+1]!='null':
                            b[i].right=b[a[i]+1]
        
        return b[0]
```
