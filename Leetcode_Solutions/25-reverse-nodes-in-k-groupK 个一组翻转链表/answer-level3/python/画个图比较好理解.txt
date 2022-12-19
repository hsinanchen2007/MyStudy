### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reverseKGroup(self, l, k):
        if k==1:return l
        state=0
        n=l
        for i in range(k-1):
            n=n.next
            if not n:return l
        p0=None
        while True:
            if state==1:
                state=0
                if p0:p0.next=p[-1]
                p[0].next=p[-1].next
                for i in range(k-1):
                    p[i+1].next=p[i]
                p0=p[0] ;l=p[0].next
                if not l:return n
            else:
                print(1)
                state=1
                p=[l]
                for i in range(k-1):
                    l=l.next ;p.append(l)
                    if not l:return n
        return n
```