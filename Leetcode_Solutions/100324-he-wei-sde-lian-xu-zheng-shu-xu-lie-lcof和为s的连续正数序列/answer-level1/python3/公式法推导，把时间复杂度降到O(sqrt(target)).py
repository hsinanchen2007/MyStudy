![image.png](https://pic.leetcode-cn.com/efb220094dacd6172f4459030dbd6717dd94e16e96c96282e6ccc72f2d17aa1d-image.png)
思路是这样的：
我们知道满足一个长度为$k$的序列的和为$s$的序列$A_n$在给定的$k$下有且只有一个。
这个唯一性是显然的。
然后我们就可以从这个$k$下手
从高中的知识我们知道，已知等差数列首项$a_1$，公差为$d$，其和为：
$$
S_k = ka_1+\frac{k(k-1)}{2}
$$
那么，最大的$k$在哪里取得呢？
我们知道，对于给定的$k$，和由$a_1$决定
那我们不妨固定$a_1$，找最大的$k$。
当$a_1=1$时，满足
$$
k+\frac{k(k-1)}{2}<=target
$$
解这个方程，因为有$k>=2$的约束，所以根只取一边，也就是
$$
k<=\frac{\sqrt{1+8*target}-1}{2}
$$
又有$k\in Z$的约束，所以就是
$$
2<=k<=\lfloor{\frac{\sqrt{1+8*target}-1}{2}}\rfloor\ (k\in Z)
$$
那我们就得到了$k$的迭代范围。
然后我们再来探究$k$的解可行性，当我们知道，给定$k$的时候，和为：
$$
target = ka_1+\frac{k(k-1)}{2}
$$
那只要$a_1$不为整数，这个$k$就无效了。
所以，我们把上式变一下形，得到：
$$
a_1 = \frac{target-\frac{k(k-1)}{2}}{k}
$$

所以只需要判断：
$$
[target-\frac{k(k-1)}{2}]\ \%\ k\ =\ 0
$$
是否成立即可，若成立，这就是一个可行解。
因为需要使用$a_1$从小到大的顺序输出，我们又知道，$k$越小，$a_1$越大，所以我们让$k$从大到小遍历就好了。

这样的时间复杂度就是$O(\sqrt{target})$，没有使用额外的存储空间，所以空间复杂度是$O(1)$。
代码如下：
```
from math import floor
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        # 数学法
        # 设队列长度为k，那么队列之和就是a1*k+k*(k-1)/2=target
        # 所以就可以知道a1应该是多少了
        # 比如target=9，k=2，那么a1*2+2*1/2=9，解得a1=4
        # 比如target=15,k=5，那么a1*5+5*4/2=15，解得a1=1
        # 直接走起
        # 队列最大长度是多少？就是a1取1的时候k的最大值，也就是k+k*(k-1)/2<=target的值，
        # 解方程，就是k^2/2+2/k<=target
        # 解得2<=k<=floor((sqrt(1+8*target)-1)/2)
        result = []
         for k in range(floor(((1+8*target)**0.5-1)/2),1,-1):
            # a1取不到整数的情况为：(target-k*(k-1)/2) % k != 0
            if (target-k*(k-1)/2) % k != 0:
                continue
            else:
                length = floor((target-k*(k-1)/2)/k)
                result.append([i for i in range(length,length+k)])
        return result
```

