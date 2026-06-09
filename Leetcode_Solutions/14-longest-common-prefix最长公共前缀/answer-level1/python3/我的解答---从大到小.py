```

def a(s):
    min1=find_short(s)
    a1=[]
    max=0
    for min2 in range(min1,0,-1):
        for s1 in s:
            a2=s1[:min2]
            a1.append(s1[:min2])
        if corr(a1)==1:
            max = min2
            break

        a1=[]
    if max==0:return ''
    return s[0][:max]

def find_short(s):
    a=[]
    for s1 in s:
        a.append(len(s1))
    min1=min(a)
    return min1
def corr(a1):
    b=set(a1)
    if len(b)==1:
        return 1
    return 0

```
最后调用函数模块就行，我的解答时间和空间复杂度都一般
![1.png](https://pic.leetcode-cn.com/bedd6bba65a5c28514f885d368ded04432c448a85d6cbad0a1adc0d6c4cce6aa-1.png)

