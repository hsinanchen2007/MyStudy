因为没有考虑，偶数和奇数的位置问题，所以如果是偶数，添加到列表的头部，否则，添加到列表的尾部
 
```
        b = []
        for x in A:
            if x %2 == 0:
                b.insert(0,x)
            else:
                b.append(x)
        return b
```
