```
str1 = A + ' ' + B
dict1 = {}
list1 = []
for i in str1.split(' '):
    if i in dict1.keys():
        dict1[i] += 1
    else:
        dict1[i] = 1
for v, n in dict1.items():
    if n == 1:
        list1.append(v)
return list1
```
