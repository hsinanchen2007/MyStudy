### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def search(self, n, t):
        if len(n)==0:return -1
        if len(n)==1:
            if n[0]==t:return 0
            else:return -1
        if t==n[-1]:return len(n)-1
        elif t==n[0]:return 0
        if t>n[-1] and t<n[0]:return -1
        if t>n[0]:
            i=0 ;j=len(n)-1
            while i<j:
                m=int((i+j)/2)
                if t==n[m]:return m
                elif t>n[m]:
                    if n[m]>=n[0]:
                        i=m+1
                    else:
                        j=m-1
                elif t<n[m]:j=m-1
            if n[i]==t:return i
            else:return -1
        else:
            i=0 ;j=len(n)-1
            while i<j:
                m=int((i+j)/2)
                if t==n[m]:return m
                elif t>n[m]:i=m+1
                elif t<n[m]:
                    if n[m]>=n[-1]:
                        i=m+1
                    else:j=m-1
            if n[i]==t:return i
            else:return -1
```