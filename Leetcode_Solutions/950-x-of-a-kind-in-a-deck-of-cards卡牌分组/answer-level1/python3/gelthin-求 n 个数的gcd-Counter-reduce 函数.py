### 解题思路
首先用一个 hash_set, 记录所有数字的出现次数，
然后把这些不为0的出现次数导入到数字val中，然后求 val 中所有数字的最大公约数。
这里 
+ gcd(a1, a2, a3, a4) = gcd(gcd(a1,a2,a3), a4) = gcd(gcd(gcd(a1,a2), a3), a4)

最初错误的想法：
1. 对 deck排序，然后求出第一个值对应出现的次数，然后对后面所有值的出现次数都要整除这个值，错误 [1,1,1,1,2,2]
2. 对 val 进行排序， 然后求最小的两个值的 gcd, 然后要求后面的所有值都要整除这个 gcd. 错误： [6,12,27]

#### 官方代码很神奇, 为啥这样使用 reduce 函数把 gcd 用到了所有值上面，且提到了gcd(a,b) 的复杂度为 O(log(max(a,b)))
``` python3
class Solution(object):
    def hasGroupsSizeX(self, deck):
        from fractions import gcd
        vals = collections.Counter(deck).values()
        return reduce(gcd, vals) >= 2
```
来自[官方题解下评论](https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/solution/qia-pai-fen-zu-by-leetcode-solution/311471)

math.gcd求两个数的最大公约数，返回整数；

collections.Counter统计字符串（数字）种类及数量，返回字典；

functools.reduce逐次对上次函数结果与当前序列元素应用函数； reduce 不同于 map

reduce(function, sequence)
例如 reduce(lambda x, y: x+y, [1, 2, 3, 4, 5]) 计算为((((1+2)+3)+4)+5)

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        def gcd(a, b):  #a, b>=0  当 a<b 也能work, 负数似乎不 work
            while b!=0:
                a, b = b, a%b
            return a

        hash_set =[0]*10001
        for x in deck:
            hash_set[x] += 1
        val = [x for x in hash_set if x!=0]

        if len(val) == 1:
            if val[0]>1:
                return True
            else:
                return False
        # len(val) >2
        #val.sort()
        g = gcd(val[0], val[1])  # 这里 6， 12， 27 就过不了
        if g == 1:
            return False
        else:
            for x in val[2:]:
                g = gcd(g, x)
                if g == 1:
                    return False
                #if x%g != 0:
                #    return False
            return True
```

#### 开始的错误代码
``` python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        # 过不了 例子 [1,1,1,1,2,2] [1,1,2,2,2,2a]
        
        deck.sort()
        tmp = deck[0]
        num = 1
        
        i = 1
        while i<len(deck):
            if deck[i] == tmp:
                num += 1
            else:
                break
            i += 1
        X = num
        if X == 1:
            return False
        if len(deck)%X !=0:
            return False
        if len(deck) == X:  # 特例 [1,1]
            return True

        tmp = deck[X]
        num = 1
        i = X+1
        while i<len(deck):
            if deck[i] == tmp:
                num += 1
            else:
                if num != X:
                    return False
                tmp = deck[i]
                num = 1
            i += 1
        return num == X
```