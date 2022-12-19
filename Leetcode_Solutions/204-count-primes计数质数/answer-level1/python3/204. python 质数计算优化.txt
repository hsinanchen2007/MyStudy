### 解题思路

对于优化的算法，也就是埃拉托色尼筛选法，循环中置对应值的倍数为0，最后统计为1的个数，也就是质数的个数。

不过看了其他人的优化，发现`i*2`可以优化成`i*i`,确实减少了循环次数，例如6,可以由2的倍数置为0，也可以由3的倍数置为0，因此`i*i`在面对较大的值时效率明显会高于`i*2`!


### 代码

```python
class Solution:
    def countPrimes(self, n: int) -> int:
        '''超时算法，应对大量数据的时候会超时'''
        
        import math
        nums = 0
        for i in range(2,n):
            if i == 2:
                nums += 1
                continue
            for j in range(2,int(i**0.5)+1):
                if i%j == 0:
                    break
            else:
                print(i)
                nums += 1
        return nums
        



        '''优化算法'''
        if n < 3:
            return 0
        results = [1]*n
        results[0],results[1] = 0, 1
        for i in range(2,int(n**0.5)+1):
            if results[i] == 1:
                results[i*2:n:i] = [0]*len(results[i*2:n:i])
        return sum(results)-1
```