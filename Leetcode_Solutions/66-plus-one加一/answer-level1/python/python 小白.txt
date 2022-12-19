我使用的方法比较俗气， 主要是str和int之间的来回转换即可
```
list1 = []
num = ''
for i in digits:
    num += str(i)
for i in str(int(num)+1):
    list1.append(int(i))
return list1
```
