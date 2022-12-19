
Let $p(r, c, k)$ be the probability that the knight _still_ remains on the chessboard _after it starts at $(r, c)$ and moves $k$ steps_. The 8 possible moves are

* $(+2, +1)$;
* $(+2, -1)$;
* $(-2, +1)$;
* $(-2, -1)$;
* $(+1, +2)$;
* $(+1, -2)$;
* $(-1, -2)$;
* $(-1, +2)$.


In the first step, it can take one of the 8 moves. If it takes the first move $(+2, +1)$, then we come to the point $(r+2, c+1)$. The probability $p(r, c, k)$ is then $p(r+2, c+1, k-1)$, i.e. the probability that the knight will remain on the board after $k-1$ moves, starting at $(r+2, c+1)$. Similarly, if it takes the second move $(+2, -1)$, then the probability $p(r, c, k)$ would become $p(r+2, c-1, k-1)$. Of course we don't know in advance which move it will take. Each direction is taken with equal probability ($1/8$), so we should take the expectation:

$\displaystyle p(r, c, k) = p(r+2, c+1, k-1)\cdot\frac{1}{8} + p(r+2, c-1, k-1)\cdot\frac{1}{8} + \cdots + p(r-1, c+2, k-1)\cdot\frac{1}{8}$.


The above is the DP transition equation. The final answer is

$\displaystyle \sum_{r=0}^{N-1}\sum_{c=0}^{N-1}p(r, c, K)$.


Python code below. This short and elegant code comes from [https://leetcode.com/problems/knight-probability-in-chessboard/discuss/108193/Python](https://leetcode.com/problems/knight-probability-in-chessboard/discuss/108193/Python). Note that $p(\cdot, \cdot, k)$ only depends on $p(\cdot, \cdot, k-1)$, so we do not maintain the third variable $k$ in the program. 
```
class Solution:
    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        p = {(r, c): 1}
        for _ in range(K):
            p = {(r, c): sum(p.get((r+i, c+j), 0) + p.get((r+j, c+i), 0) for i in (1, -1) for j in (2, -2)) / 8 
                 for r in range(N) for c in range(N)}
        
        return sum(p.values())
```