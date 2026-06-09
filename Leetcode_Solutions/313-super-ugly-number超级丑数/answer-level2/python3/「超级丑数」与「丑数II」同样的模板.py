如果你做了[264.丑数II](https://leetcode-cn.com/problems/ugly-number-ii/solution/)，那么本题也不在话下，都是同样的思路。只要记录质数列表primes中的每一个质数下次应该去乘已求丑数列表中的哪一个，然后每次取最小值加入丑数列表就好了。直接看代码
```
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        if n == 1:return 1
        nprimes,length = [1],len(primes)
        pointers = [0] * length
        count = 1
        while count < n:
            nextPrime = min([primes[i] * nprimes[pointers[i]] for i in range(length)])
            for i in range(length):
                if nextPrime == primes[i] * nprimes[pointers[i]]:
                    pointers[i] += 1
            nprimes.append(nextPrime)
            count += 1
        return nprimes[-1]
```
