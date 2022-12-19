```
#一种原地修改字符串的做法 在就字符串后补上2*num_blank个空格
# 使用双指针p2指向新字符串的末尾，p1指向旧字符串的末尾，依次把p1处的值转移到p2处 直到p1 p2相等
def inplace(s):
    num_b = 0
    for i in range(len(s)):
        if s[i]==' ':
            num_b+=1
    
    l = len(s)
    nl = len(s)+2*num_b
    for i in range(l,nl):
        s += ' '
    p1,p2 = l-1,nl-1

    while p1 < p2 and p1 >=0:
        if s[p1] ==' ':
            s = s[:p2]+'0'+s[p2+1:nl]
            p2 -= 1
            s = s[:p2]+'2'+s[p2+1:nl]
            p2 -= 1
            s = s[:p2]+'%'+s[p2+1:nl]
            p2 -= 1
            p1 -= 1
        else:
            ch = s[p1]
            s = s[:p2] + ch + s[p2+1:nl]
            p2 -= 1
            p1 -= 1
    return s

print(inplace("  "))
```
