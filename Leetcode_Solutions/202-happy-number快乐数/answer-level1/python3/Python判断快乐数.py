直观上，不论给出的是几位数，经过几轮快乐后都会变成个位数（例如37 → 58 → 89 → 145 → 42 → 20 → 4），所以问题转化为判断10以内的快乐数：
```
    #  1
    #  2 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4
    #  3 → 9 → 81 → 65 → 61 → 37 → ··· → 4
    #  4
    #  5 → 25 → 29 → 85 = 58 → ··· → 4
    #  6 → 36 → 45 → 41 → 17 → 50 = 5 → ··· → 4
    #  7 → 49 → 97 → 130 → 10 → 1
    #  8 → 64 → 52 = 25 → ··· → 4
    #  9 → 81 → 65 → ··· → 4
```
由此可见，10以内只有1和7为快乐数。

一个直接的蠢办法，写一个子函数，每调用一次返回“快乐”一次后的结果，反复调用知道变成个位数。
```
    def nextn(nn):
        tmp=list(str(nn))
        tmp=[int(tmp[i]) for i in range(len(tmp))]
        m=0
        for i in range(len(tmp)):
            m=m+tmp[i]**2
        return m
```
以上是原始代码，本人初学算法，看到有大佬用一句话解决`n = sum([int(i)**2 for i in str(n)])`，接受我的膝盖...

完整代码如下：
```

class Solution:
    def isHappy(self, n: int) -> bool:
        def nextn(nn):
            ······
            return m
        while True:
            n=nextn(n)
            if n<10 and n!=1 and n!=7:
                return False
            if n==1 or n==7:
                return True
```
运行结果如下：
![QQ截图20191108160453.png](https://pic.leetcode-cn.com/420dedfbd09d641eba45505172fd73020d2efd6b28f145fcd2f05a4313f6b551-QQ%E6%88%AA%E5%9B%BE20191108160453.png)

emmmmmm，对我来说，这个结果已经算不错了，记录一下~~~