The solution by [@duadua](/u/duadua) is already clear enough. Here I re-state his answer. First we observe that the binary representation of any even number must have a $0$ in the end, like $2=10$, $4=100$, $6=110$, $8=1000$ etc. This is because the binary representation of $2$ is $10$, and all even numbers are divisible by $2$. Similarly, since all odd numbers are not divisible by $2$, they always have $1$ in the end of their binary representations.

Let $f(i)$ be the number of ones in binary number $i$. An odd number $i$ is always equal to its previous even number $i-1$ plus one, add from above we can deduce that the number of ones in $i$ is equal to $f(i-1)+1$. If $i$ is an even number, then dividing it by $2=10$ will remove the $0$ in the end but will not alter the number of ones in $i$, so we have $f(i) = f(i/2)$. In summary,

$f(i) = \begin{cases}f(i-1) + 1 & \text{ if }i\text{ is odd,}\\ f(i/2) & \text{ if }i\text{ is even.} \end{cases}$

Again, solutions to bigger problems depend on solutions to smaller problems, and this is what we called dynamic programming. 

Python code:
```
class Solution:
    def countBits(self, num: int) -> List[int]:
        result = [0]*(num+1)
        for i in range(1, num+1):
            if i % 2 == 1:
                result[i] = result[i-1] + 1
            else:
                result[i] = result[i//2]
        return result
```
