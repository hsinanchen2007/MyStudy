### 解题思路
求解质数的三种常用方法，效率从低到高：
1、暴力求解，循环
2、开方循环
3、筛选法
其中，开方循环比暴力求解没有提高很多，只是降低了循环的上界。
筛选法的思路比较清晰。当n>=2时，从2开始计算质数的个数。当i是质数的时候，i的所有的倍数必然是合数。如果i已经被判断不是质数了，那么再找到i后面的质数来把这个质数的倍数筛掉。
需要注意的有两点：
1. 题干要求“统计所有小于非负整数 n 的质数的数量”，实际上是从0开始计算，虽然0，1不是质数也不是合数。
2. 当i为质数时（在循环的前面没有被标注为0），说明i没有其他公约数，所以i也为质数，不需要单独判断。只需要用i过滤i^2及其以后的数值即可。

### 代码

```python3
class Solution:
    def primeFilter(self, n: int) -> list:
        l = [1]*(n)
        l[0]=0
        l[1]=0
        for i in range(2, int(math.sqrt(n))+1):
            if l[i]==1:
                for j in range(i*i, n, i):
                    if j%i == 0:
                        l[j] = 0
            else:
                continue
        return l


    def countPrimes(self, n: int) -> int:
        if n<2:
            return 0
        counter = 0
        l = self.primeFilter(n)
        print(l)
        for i in range(n):
            if l[i]==1:
                counter+=1
        return counter
```