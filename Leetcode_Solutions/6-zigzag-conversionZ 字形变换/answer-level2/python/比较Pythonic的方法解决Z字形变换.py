大致思路比较简单粗暴

1.从头到尾遍历一次字符串，通过每个element的下标计算出其在变换前的矩阵中的坐标（x,y)，此时还是从上到下，从左到右
2.然后按照计算出来的坐标，采取从左到右，从上到下的顺序join在一起就可以了

性能一般般

```
        if numRows == 1:
            return s
        if len(s)<=numRows:
            return s
        if numRows == 2:
            return s[::2]+s[1::2]
        v = [[] for _ in range(numRows)]
        for _, i in enumerate(s):
            m = _ // (2 * numRows - 2)
            r = _ % (2 * numRows - 2)
            x = r if r < numRows else 2 * numRows - 2 - r
            y = m * (numRows-1) if r < numRows else m*(numRows-1) + r-numRows+1
            v[x].append(i)
        return ''.join([''.join(_) for _ in v])
```
