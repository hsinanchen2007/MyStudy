# 两两查找一定会超时，因此需要考虑二进制位上的规律

例如有很多数，如果要求他们之间的汉明距离，可以考虑把所有数的每一位二进制列出来
例如
    1 1 0 0
    1 0 1 1
    1 0 0 1
    0 1 0 0
DIF 3 4 3 4
可以看出每一位的汉明距离求和就是1的个数*0的个数，这样本题就化成了“统计所有数字每一位上1和0的个数”

```
    nums2 = list(map(lambda x:bin(x)[2:].zfill(30),nums)) #zfill填充30位，避免位数不统一
    nums3 = [''.join([y[x] for y in nums2]) for x in range(30)] #将n个30位数字转化为30个n维数字
return sum(collections.Counter(x)['0']*collections.Counter(x)['1'] for x in nums3) # 1的个数乘0的个数
```
