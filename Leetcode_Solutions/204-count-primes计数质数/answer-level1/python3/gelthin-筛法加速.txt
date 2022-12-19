### 解题思路
这里使用传说中的埃拉托斯特尼筛法，求素数，不知道是从那本书里看到的，应该是大四上算法课的时候在图书馆里读的算法书。

不过我这里实现的可能不太好，感觉效率不是很高。[参看了 labuladong 大佬的解法][https://leetcode-cn.com/problems/count-primes/solution/ru-he-gao-xiao-pan-ding-shai-xuan-su-shu-by-labula/]
优化：
+ 1. 如果 sqrt(n) 只是作为上界的话， 没有必要计算出 sqrt(n), 只需要用 i*i<n来判断即可。
+ 2. 内循环，j 没必要从 2 开始， j 可以从 i 开始，因为 2*i, 在用 2 筛的时候已经被筛掉了。
+ 3. 百度上还有进一步对内循环的优化，每次考虑将将 两个素因子相乘，作为筛子。



### 代码

```python3
class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 1:
            return 0
        hash_set = [1]*(n+1)
        # import math  # 超时 499979
        # for i in range(2, int(math.sqrt(n))+1):
        #     for j in range(i+1, n+1):
        #         if hash_set[j]==1 and j%i == 0:  #已经为 0 就不用判断了
        #             hash_set[j] = 0
    
        # return sum(hash_set[2:-1]) # 小于n 的素数个数 

        import math
        for i in range(2, int(math.sqrt(n))+1):
            if hash_set[i] == 1:  # 潜在质数，作为筛子
                for j in range(2, n//i+1): # 这里 j 错写成 i 也不冲突
                    if hash_set[j*i] == 1:  #加了这一句不知道是否会加速
                        hash_set[j*i] = 0  #所有 x 的倍数置为 0
        return sum(hash_set[2:-1])
             
```
### 加速代码
``` python3
i = 2
while i*i < n:
    if hash_set[i] == 1:  # 潜在质数，作为筛子
        j = i
        while j <= n//i:  # j 的范围是 [i, min(n//i, n//j)]
            if hash_set[j*i] == 1:  #加了这一句不知道是否会加速
                hash_set[j*i] = 0  #所有 x 的倍数置为 0
            j = j+1
    i += 1
return sum(hash_set[2:-1])
```