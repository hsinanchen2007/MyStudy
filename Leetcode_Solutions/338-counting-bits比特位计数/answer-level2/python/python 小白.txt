```
# 1. 遍历出所有的数
# 2. 转化成二进制
# 3. 进行切割取出没个数的二进制值
# 4. 用count()函数来统计其中包含1的个数
list1 = []
for i in range(0, num+1):
    list1.append(bin(i).split('b')[-1].count('1'))
return list1
```

