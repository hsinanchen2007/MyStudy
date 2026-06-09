首先我们判断数字的位数。
比如123，就是三位数，1234，就是四位数
我这里偷懒，将数字转为字符串，直接测len
```
s = str(N)
len_s = len(s)
```
比如数字1234，那么他的排列组合只可能在1000-9999之间，我们就求出1000到9999之间2的幂次可能出现的数字，这个数字最多只有4个结果。
```
min_s = math.ceil(math.log(10 ** int(len_s-1), 2))
max_s = math.ceil(math.log(10 ** int(len_s), 2))
```

然后再偷个懒，用counter求出各数字出现的次数，穷举min_s和max_s之间2的幂次数字的次数，作比较
```
counts = collections.Counter(s)
for i in range(min_s, max_s):
    counts_i = collections.Counter(str(2 ** i))
    if counts_i == counts:
        return True
```

最终代码
```
class Solution:
    def reorderedPowerOf2(self, N: int) -> bool:
        s = str(N)
        len_s = len(s)
        min_s = math.ceil(math.log(10 ** int(len_s-1), 2))
        max_s = math.ceil(math.log(10 ** int(len_s), 2))
        counts = collections.Counter(s)
        for i in range(min_s, max_s):
            counts_i = collections.Counter(str(2 ** i))
            if counts_i == counts:
                return True
        else:
            return False

```

