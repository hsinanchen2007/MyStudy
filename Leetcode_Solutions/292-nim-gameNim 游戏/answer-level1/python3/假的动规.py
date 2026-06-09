```
    a=[1]*n #1代表胜
    for i in range(3,n):
        a[i]=1-min(a[i-3:i])#如果剩下i-1，i-2，i-3都必胜那么i就输了
    return a[-1]==1
```
