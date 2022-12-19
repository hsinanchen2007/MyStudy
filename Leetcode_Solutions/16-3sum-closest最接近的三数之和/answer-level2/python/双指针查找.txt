### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def threeSumClosest(self,n,t):
        n.sort() ;l=len(n)
        f=sum(n[:3])
        if f>t:ma=f ;mi=2*t-f
        else:mi=f ;ma=2*t-f#找出可更新的上下界
        for k in range(l-2):
            i=k+1 ;j=l-1
            while i<j:#可以在数轴上画出条件中的区域便于理解
                s=n[i]+n[j]+n[k]
                if s<mi:#如果小于更新下指针:i+1（i增加s增加）
                    i+=1
                    while i<j and n[i]==n[i-1]:i+=1
                elif s>ma:#如果小于更新上指针：j+1（j减小s减小）
                    j-=1
                    while i<j and n[j]==n[j+1]:j-=1
                elif s<t:#（s值可更新，但是要判断更新下指针还是上指针）这种情况更新下指针
                    f=s
                    mi=f ;ma=2*t-f
                    i+=1
                    while i<j and n[i]==n[i-1]:i+=1
                elif s>t:#这种情况更新上指针
                    f=s
                    ma=f ;mi=2*t-f
                    j-=1
                    while i<j and n[i]==n[j+1]:j-=1
                else:#f等于t毫无疑问直接返回
                    return t
        return f
```