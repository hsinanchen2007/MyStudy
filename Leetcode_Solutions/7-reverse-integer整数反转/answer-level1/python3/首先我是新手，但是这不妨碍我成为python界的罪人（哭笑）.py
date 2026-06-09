### 解题思路
搞得跟个原始代码似得，我敲出来的时候看到诸位大神的py3如此的简洁，瞬间觉得侮辱了这语言的灵魂，晒出来求虐

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if -2**31<=x<=2**31-1:
            if x>=0:
                m=str(x)
            else:
                m=str((-x))
            line=[None]*len(m)
            a=-1
            for i in m:
                a+=1
                line[a]=i
            for i in range(len(m)):
                t=line[i]
                line[i]=line[len(m)-1-i]
                line[len(m)-1-i]=t
                if (i==len(m)-1-i)|(i==len(m)-2-i):
                    break
            s=""
            for i in line:
                s=s+i
            if x>=0:
                if int(s)<=2**31-1:
                    return(int(s))
                else:
                    return 0
            else:
                if -int(s)>=-2**31:
                    return (-int(s))
                else:
                    return 0
        else:
            return 0
```