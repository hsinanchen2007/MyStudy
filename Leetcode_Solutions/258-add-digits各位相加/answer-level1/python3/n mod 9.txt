The  answer is $~~n\bmod 9$, as explained in the Wikipedia article ([https://en.wikipedia.org/wiki/Digital_root](https://en.wikipedia.org/wiki/Digital_root)). The reason is simple, all is because $10=1 \bmod 9$ and so $10^k = 1\bmod 9$ as well. Let $f(n)$ denote the function we want to compute. Let 

$n = a_k\cdot 10^k + a_{k-1}\cdot 10^{k-1} + \cdots + a_0$.

Take modulo $9$ we find

$\bar{n} = \overline{a_k + a_{k-1} + \cdots + a_0}$.

If the sum of $a_k,\ldots,a_0$ is smaller than $10$, then we are done. The numerical result is equal to $f(n)$. If it is larger than or eqiual to $10$, then we can express the number as, say

$b_j \cdot 10^j + \cdots + b_0$

so taking modulo $9$ we will have $\overline{b_j+\cdots+b_0}$. If the sum of $b_j,\ldots,b_0$ is smaller than $10$ we are done; otherwise we continue to apply the modulo operation. This is exactly what we wanted: sum digits recursively until a single number is left. Thus the number we obtained from $\bar{n}$ (i.e. $n\bmod 9$) should be $f(n)$. 

Lastly, for $n=0$ we should return $0$. If $n$ is nonzero and $\bar{n} = \bar{0}$ (i.e. it is divisible by $9$), then $f(n)$ shall be set to $9$.


```
class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0:
            return 0
        if num % 9 == 0:
            return 9
        else:
            return num % 9
```
