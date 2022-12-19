```
# 优化：//2+1 超时
class Solution:
    def countPrimes(self, n: int) -> int:
        if n<=2:
            return 0
        elif n==3:
            return 1
        elif n==4:
            return 2
        num = 2
        for i in range(4,n):
            if i%2==0:
                continue
            for j in range(2,i//2+1):
                if i%j==0:
                    break
                if j==i//2:
                    num+=1
        return num

# 优化：开方
# 执行用时 :3940 ms, 在所有 python 提交中击败了5.04%的用户
# 内存消耗 :59 MB, 在所有 python 提交中击败了26.72%的用户
class Solution(object):
    def countPrimes(self, n):
        if n<=2:
            return 0
        elif n==3:
            return 1
        prime = [2]
        n_sqrt = int(n**0.5)
        for i in range(2,n_sqrt+1):
            for j in prime:
                if i%j == 0:
                    break
                if j == prime[-1]:
                    prime.append(i)
        num = len(prime)
        for i in range(2,n):
            for j in prime:
                if i%j == 0:
                    break
                if j == prime[-1]:
                    num+=1
        
        return num

# 优化：使用筛法，厄拉多塞筛法，Sieve of Eratosthenes
# 执行用时 :492 ms, 在所有 python 提交中击败了49.30%的用户
# 内存消耗 :47.1 MB, 在所有 python 提交中击败了28.65%的用户
class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return 0
        is_prime = [1]*n
        is_prime[0] = 0
        is_prime[1] = 0
        for i in range(2,int(n**0.5)+1):
            if is_prime[i]:
                a = i*i
                for j in range((n-a-1)//i+1):
                    is_prime[a+i*j] = 0
        return sum(is_prime)


# 执行用时 :348 ms, 在所有 python 提交中击败了57.98%的用户
# 内存消耗 :23.2 MB, 在所有 python 提交中击败了90.08%的用户
class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return 0
        is_prime = [1]*n
        is_prime[0] = 0
        is_prime[1] = 0
        for i in range(2,int(n**0.5)+1):
            if is_prime[i]:
                a = i*i
                while a<n:
                    is_prime[a] = 0
                    a += i
                    
        return sum(is_prime)

# 执行用时 :112 ms, 在所有 python 提交中击败了93.08%的用户
# 内存消耗 :34.9 MB, 在所有 python 提交中击败了50.96%的用户

class Solution(object):
    def countPrimes(self, n):
        if n < 2:
            return 0
        isPrime = [1] * n
        isPrime[0] = isPrime[1] = 0   

        for i in range(2, int(n ** 0.5) + 1):
            if isPrime[i]:
                isPrime[i * i:n:i] = [0] * ((n - 1 - i * i) // i + 1)
        return sum(isPrime)
```
