用dict代替了循环，给定list中（数:数出现的次数）作为（key:value）。
将整个list分为正数dict，负数dict，0 三部分。
三个数的组合，只有000，负0正，负负正，正正负，四种情况。
000只有list中存在三个及以上的0才可能出现，分类时检查0的个数即可。
负0正，只用检查每个负数是否存在对应正数，用dict查询效率很高。
同样的，负负正是先定下两个负数，用dict查询的办法确定正数dict中是否存在符合要求的正数；这里有个分支，要检查一下存在两个负数相同时的情况。
正正负同理。
因为分类处理了各种情况，所以不会出现重复。

代码如下


```

def list4(lst):

    b = []

    if len(lst) < 3:
        return b

    if min(lst) >0 or max(lst) < 0:
        return b


    lst1 = dict()
    lst2 = dict()
    lst3 = []
    lst4 = []
    cnt0 = 0

    # 三个数的组合，000，负0正，负负正，正正负，只有这几种情况
    # 将数分为3个集合，大于0，小于0，和0
    # 这里用到了dict，用数作为key，数出现的次数作为value
    for x in lst:
        if x < 0:
            if x in lst1:
                lst1[x] += 1
            else:
                lst1[x] = 1
                lst3.append(x)

        if x > 0:
            if x in lst2:
                lst2[x] += 1
            else:
                lst2[x] = 1
                lst4.append(x)

        if x == 0:
            cnt0 += 1


    #先将有0情况处理
    #3个0
    if cnt0 >= 3:
        b += [(0, 0, 0)]

    #1个0
    if cnt0 > 0:
        #循环负数集合
        for x in lst3:
            #只需要检查正数集合中，是否存在一个key，和负数相加为0
            if lst2.get(-x, 0) > 0:
                b.append((x, 0, -x))

    #3个数都非0

    # 负负正，从负数集合取2个数
    i=0
    for x in lst3:
        #两个数相同，检查另一个集合是否存在需要的key
        if lst1[x] > 1 and lst2.get(-2 * x, 0) > 0:
            b.append((x, x, -2 * x))

        #从负数集合再取一个数
        i += 1
        for y in lst3[i:]:
            #检查正数集合是否有符合条件的key
            if lst2.get(-(x + y), 0) > 0:
                b.append((x, y, -(x + y)))

    #类似的从正数集合中取2个数的情况
    i=0
    for x in lst4:
        if lst2[x] > 1 and lst1.get(-2 * x, 0) > 0:
            b.append((x, x, -2 * x))

        i += 1
        for y in lst4[i:]:
            if lst1.get(-(x + y), 0) > 0:
                b.append((x, y, -(x + y)))


    return b
```
