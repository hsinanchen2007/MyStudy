这题可以用暴力法解决，但是当target非常大时估计会超时。但其实这题可以用高中数学的思想解决。

首先，这题是连续的正整数相加等于target，那就是高中数学的等差公式差为1的和是target。

这里n是项数，m是第一项，n-1+m是最后一项。
```
target = (n-1+m + m) * n / 2 

即 2*target = n*(n - 1+2m)
```
根据极限的思想，那就是m越小，n越大，当m趋向于1时，2*target=n*(n+1),所以 n <  √(2target)。 这样就可以确定可能存在的连续正整数长度范围了是[2,√(2target))。这样范围已经小了很多了。

然后当n已知时，那 m 就可以确定了。根据上面的公式推出：
```
m = (2*target + n - n*n) / (2*n)
```

当 m 为正整数时，就判定这个m开头，有n个正整数的序列是满足条件。

下面是代码：
```
class Solution(object):


    def findContinuousSequence(self, target):
        
        if target == 1 or target == 2:
            return []

        result = []
        # 求出最大的正整数序列长度
        maxlength = int(pow(2*target, 1.0/2))
        for i in reversed(range(2, maxlength+1)):
            m = float(2 * target + i - i*i) / (2 * i)
            #判定m是否为正整数
            if m - int(m) == 0:
                result.append(list(range(int(m), int(m)+i)))


        return result
```
