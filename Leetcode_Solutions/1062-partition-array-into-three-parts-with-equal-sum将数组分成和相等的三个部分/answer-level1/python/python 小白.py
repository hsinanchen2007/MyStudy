```
1. 分成三段，首先算出平均值
2. 用遍历累加的方式，如果累加值等于平均值计数加一，并将累加值重置为0
3. 返回统计的次数，如果等于三次返回True否则返回False

ave = sum(A) / 3
count, num = 0, 0
for i in A:
    num += i
    if num == ave:
        num = 0
        count += 1
return count == 3
```
