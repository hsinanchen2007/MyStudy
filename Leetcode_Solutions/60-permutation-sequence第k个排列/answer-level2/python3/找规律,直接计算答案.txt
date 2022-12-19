一开始写了一个暴力枚举的解法，但超时了，仔细分析呢总结了一下规律，得出了此解法，耗时56ms，算是比较慢，但空间复杂度很小为O(n).

当有n位集合时，可以知道第一位显然有n个可能，而每一个第一位确定后，引申出来的可能性有  __(n-1)!__ 个。

所以反过来呢，第k个排列的第一位，就是 __k/(n-1)!__  余数记为mod。

于是第二位的答案也呼之欲出： __mod/(n-2)!__。

看到这里相信同学们已经理解了最核心的计算方法。下面讲解下实现的一些小细节。


1. 需要先定义从1到n的数组。上文中说的 __k/(n-1)!__ 和 __mod/(n-2)!__ 其实并不严谨，第二位实际上应该是算完第一位后排除第一位的答案后，剩余数组的第 __mod/(n-2)!__ 个元素。
2. 由于引入了数组，第一位计算前mod 应该为 k-1。
3. 当余数为0时，实际上没有必要继续计算了，只需将剩余数组元素，依次添加进答案即可。(join方法报错，没理解为什么，写了循环添加)


```
class Solution:
    import math
    def getPermutation(self, n: int, k: int) -> str:
        result = ''
        mod = k-1
        if n==1:return '1'
        n_set = [str(i) for i in range(1,n+1)]
        fac_n = math.factorial(n-1)
        for i in range(n):
            val,mod = divmod(mod,fac_n)
            #print(i,fac_n,val,mod,result,n_set)
            fac_n = fac_n//(n-i-1)
            result+=n_set[val]
            del n_set[val]
            if mod==0:
                for i in n_set:result+=i
                return result
            
        return result
```