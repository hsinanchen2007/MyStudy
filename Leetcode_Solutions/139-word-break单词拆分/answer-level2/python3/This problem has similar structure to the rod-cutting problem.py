
PS: In the text below, notation like `a[i:j]` means the subarray from `a[i]` to `a[j]` _inclusive_. 

##### Rod-cutting

This word break problem is very similar to the rod-cutting problem, so let's first review the problem briefly. Let $f(i)$ denote the value function for the rod `r[:i]`. We want to calculate $f(n)$, where $n$ is the size of the input. For any cut point $j$ we choose, the rod would be divided into two parts: a part that has value $p_j$, the price for a piece of length $j$, and a remaining part which has value $f(n-j)$. We choose the cut point that yields highest value. Thus

$\displaystyle f(n) = \max_{1\leq j \leq n}\{p_j + f(n - j)\}$.

##### Word break

Now let 

$f:\{1,2,\ldots, n\}\to\{T, F\}$ 

denote the value function for this word break problem, where $n$ is the size of the string. We have to choose a break in the string, just like we have to choose a cut point in the rod-cutting problem. Any such break $j$ would divide the string into two parts: a part that has Boolean value $\texttt{[s[j:n] in wordDict]}$, and a part that has Boolean value $f(j)$. The value of such break is 

$\texttt{[s[j:n] in wordDict]} \wedge f(j)$.  

Remamber that the function has only two values: True ($T$) or False ($F$). Any break that has True value is the optimal one. Thus the DP equation is


$\displaystyle f(n) = \bigvee_{1\leq j\leq n}\left\{\texttt{[s[j:n] in wordDict]} \wedge f(j)\right\}$.

Looking at those two DP equations, we see that the _any_ operation "$\bigvee$" in the bottom one corresponds to the $\max$ operation in the top one, and the _and_ operation "$\wedge$" corresponds to the plus operation "$+$" in the top one.


Python code below. Credit to [Stefan Pochmann](https://leetcode.com/stefanpochmann/).

```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        f = [True]
        for i in range(1, len(s)+1):
            f += any(f[j] and s[j:i] in wordDict for j in range(i)),
        return f[-1]
```