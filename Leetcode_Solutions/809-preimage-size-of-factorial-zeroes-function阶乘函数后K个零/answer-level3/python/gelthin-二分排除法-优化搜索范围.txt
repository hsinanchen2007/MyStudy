### 解题思路
10^9 被当成了异或运算，所以没报错，不是10的9次方， 10**9

利用习题 [172. 阶乘后的零](https://leetcode-cn.com/problems/factorial-trailing-zeroes/)，这个题目可以变为二分搜索题，但是要注意控制搜索的范围。

我们知道如果存在数，其阶乘后有 K 个0，那么 K = f(5a) = f(5a+1) = f(5a+2) = f(5a+3) = f(5a+4) < K+1 = f(5a+5)。
我们需要来找 5a 这个数，其是最小的满足 f(x)= K 的数。
设 x = 5a (可以整除 5),  K = f(x) = x//5 + x//(5^2) + x//(5^3) + ...<= 4/5x, 于是  K >= x//5， 另一边，K <= 4/5 x， 推出 x 的取值范围  K <= x <= 5K+1. 这里设为 5K+1, 而不是 5K, 是避免 K=0， 出现问题。

我最初的代码，还加了个叠加搜索，找出 x=5a, 然后累加1，统计次数，判断是否整除5，然后 break。
其实这里可以直接返回 5 了，因为必然是 5。

我这里的代码把 check 放到了外面，和官方代码不一样，在这时候 用 5K 也是可以的。而官方代码因为用 5K，当 K=0, 会导致不进入循环，直接出错。官方二分代码也是排除法，写的还不错，多加了一个判断，while 循环可以改为 left<=right? 。
```python3
 while lo < hi: # 这里可以写为 lo <=hi?
    mi = (lo + hi) / 2
    zmi = zeta(mi)
    if zmi == K: # 这里加了个快速跳出机制
        return 5
    elif zmi < K: 
        lo = mi + 1
    else: 
        hi = mi  # 这里可以写为？ hi = mi+1?
```



### 代码

```python3
class Solution:
    def preimageSizeFZF(self, K: int) -> int:
        # 利用上一个习题，这个习题可以变为 二分查找类习题
        def f(n):
            # calculate 0 number
            count = 0
            k = 5
            while k<=n:
                count += (n//k)
                k *=5
            return count

        left, right = K, 5*K+1 # 10^9  # 10^9 居然没报错？
        while left<right: # 找到从左到右 第一个为 x, 满足 f(x) >= K (注意，这里不一定是 K)
            mid = left + (right-left)//2
            if f(mid)<K:
                left = mid+1
            else:
                right = mid
        # check 一下
        if f(left) != K:  # 这里可能会出错，没找到
            return 0

        # 其实这里可以直接返回 5 了，因为必然是 5
        num = 1
        while True:
            if (left+num) %5 == 0:
                break
            num += 1
        return num

class Solution:
    def preimageSizeFZF(self, K: int) -> int:
        # 利用上一个习题，这个习题可以变为 二分查找类习题
        def f(n):
            # calculate 0 number
            count = 0
            k = 5
            while k<=n:
                count += (n//k)
                k *=5
            return count

        left, right = K, 5*K # 10^9  # 10^9 居然没报错？
        while left<right: # 找到从左到右 第一个为 x, 满足 f(x) >= K (注意，这里不一定是 K)
            mid = left + (right-left)//2
            if f(mid)<K:
                left = mid+1
            else:
                right = mid
        # check 一下
        if f(left) != K:  # 这里可能会出错，没找到
            return 0

        return 5
```