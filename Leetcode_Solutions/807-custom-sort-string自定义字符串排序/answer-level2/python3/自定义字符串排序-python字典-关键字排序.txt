两行python解决自定义排序
```
d = {s:i for i,s in enumerate(S)}
return ''.join(sorted(T,key=lambda x:d.setdefault(x,30)))
```
