### 解题思路
设g(n)为爬n节台阶的方法数，则有g(n)=g(n-1)+g(n-2)，所以可以考虑采用Fibonacci sequence来解决，具体就用了一个同时赋值，但感觉和排列组合直接算速度没啥差别

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        i=0
        j=1
        counter=1
        while counter<=n:
            f_s=i+j
            i,j=j,f_s
            counter+=1
        return f_s



```