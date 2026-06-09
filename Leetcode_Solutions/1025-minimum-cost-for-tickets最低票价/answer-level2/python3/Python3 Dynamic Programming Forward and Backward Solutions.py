
#### Backward Solution

Let $f(i)$ be the minimal cost from day $i$ to day $365$, where $1\leq i\leq 365$. Standing on day $i$, let's consider what we can do. If day $i$ is not in our travel plan, then we have no reason to purchase ticket on this day. We can purchase tickets when we need them. Thus $f(i) = f(i+1)$. If day $i$ is in the travel plan, then we have three choices: 

1. We can spend `cost[0]` to satisfy the need on day $i$. In this case $f(i) = \texttt{cost[0]} + f(i+1)$.
2. We can spend `cost[1]` to get a 7-day pass. If we decide to do so, then for the consecutive 6 days we do not need to spend money again, so the total cost in the period $[i, 365]$ is equal to the cost of the 7-day pass plus the cost 7 days later. In this case $f(i) = \texttt{cost[1]} + f(i+7)$.
3. We can spend `cost[2]` to get a 30-day pass. Then for 30 days we do not need to spend additional money, so the total cost in $[i, 365]$ is `cost[2]` plus $f(i+30)$.

Since $f(i)$ is optimal, we should select the one that has the least cost:

$f(i) = \min\left\{ \texttt{cost[0]}+f(i+1),~~\texttt{cost[1]}+f(i+7),~~\texttt{cost[2]}+f(i+30)\right\}$.

Of course, we cannot have days greater than $365$, so in the code we should change 
* $i+1$ to $\min(i+1, 365)$;
* $i+7$ to $\min(i+7, 365)$;
* $i+30$ to $\min(i+30, 365)$.

See code below.


```
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        f=[0] * 366
        for i in range(365, 0, -1):
            if i not in days:
                f[i]=f[min(i+1, 365)]
            else:
                f[i]=min(cost[0] + f[min(i+1, 365)], 
                         cost[1] + f[min(i+7, 365)], 
                         cost[2] + f[min(i+30, 365)])
        return f[1]
```

#### Forward Solution

The foward solution is symmetric. Here we define $f(i)$ as the minimal cost from day $1$ until $i$. If day $i$ is not in the travel plan, then again we have no reason to purchase ticket on this day. We may have purchased some tickets several days earlier, or we haven't purchased tickets for some days. In any case, $f(i) = f(i-1)$, i.e. the two day should have the same cost. Remember here day $i$ is the _last_ day we're considering. If day $i$ is in the travel plan, then we should have purchased tickets earlier, otherwise we can purchase a 1-day pass to cover this last day. This corresponds to three costs $f(i-1) + \texttt{cost[0]}$, $f(i-7) + \texttt{cost[1]}$, and $f(i-30) + \texttt{cost[2]}$ respectively. By the optimality principle, the minimal one among the three should be $f(i)$:

$f(i) = \min\left\{f(i-1) + \texttt{cost[0]},~~f(i-7) + \texttt{cost[1]},~~f(i-30) + \texttt{cost[2]}\right\}$.

This way we can calculate $f(i)$ in a forward fashion, from small $i$ until the last day. Python code is below. Again, to prevent $i-1, i-7$ and $i-30$ from falling below $0$ we change the dates to $\max(0, i-1)$, $\max(0, i-7)$ and $\max(0, i-30)$ respectively.

```
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        f= [0] * 366
        for i in range(366):
            if i not in days:
                f[i]=f[max(0, i-1)]
            else:
                f[i]=min(f[max(0, i-1)] + costs[0],
                         f[max(0, i-7)] + costs[1],
                         f[max(0, i-30)] + costs[2])
        return f[365]
```