```
dict1 = {0: 0, 1: 1, 2: 1}
for i in range(3, 38):
    res = dict1[i-1] + dict1[i-2] + dict1[i-3]
    dict1[i] = res
return dict1[n]
```
