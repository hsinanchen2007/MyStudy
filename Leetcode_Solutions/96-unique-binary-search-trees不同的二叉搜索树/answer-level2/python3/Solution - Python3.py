The official solution is very clear. Let $G(n)$ be the number of unique BSTs for nodes $1,\ldots,n$. Let $F(i, n)$ denote the number of unique BSTs for nodes $1,\ldots,n$ with $i$ as root. We have

$G(n) = F(1, n) + F(2, n) + \cdots + F(n, n)$.

 By the recursive definition of BST, the left subtree and right subtree of a BST with root $i$ are again BSTs, so we have

$F(i, n) = G(i-1)\cdot G(n-i)$.

Thus the dynamic programming equation is

$G(n) = \sum_{i=1}^nG(i-1)\cdot G(n-i)$.

Python code:
```
class Solution:
    def numTrees(self, n: int) -> int:
        G = [0]*(n+1)
        G[0], G[1] = 1, 1

        for m in range(2, n+1):
            for i in range(1, m+1):
                G[m] += G[i-1] * G[m-i]

        return G[n]
```

Time complexity is $O(n^2)$ and space complexity is $O(n)$.