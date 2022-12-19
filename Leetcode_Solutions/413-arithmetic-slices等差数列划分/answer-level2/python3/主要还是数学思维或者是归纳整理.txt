### 解题思路
这道题的关键点是归纳出来的，对于如下连续数据的等差数列个数如下：
1 2 3 4 5 6  7  8
0 0 1 3 6 10 15 21
如果用dp来表示，则dp[i] = dp[i-1] + tmpcount，其中tmpcount为等差数列的长度-2

这样代码就比较容易整理了：
1. 首先排除A长度不够的情况。
2. 从第三个数(i=2)开始，比较A[i]-A[i-1]，A[i-1]-A[i-2]，两个差值相等，则等差数列的长度增加1，或者tmpcount+=1，同时dp[i] = dp[i-1]+tmpcount
3. 遇到差值不一致的情况，则tmpcount=0，dp[i] = dp[i-1]
4. 最后dp[-1]就是答案。


### 代码

```python3
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        n = len(A)
        if n < 3:
            return 0
        
        dp = [0] * n
        diff = A[1] - A[0]
        dp[1] = 0
        tmpcount = 0
        for i in range(2, n):
            tmpdiff = A[i] - A[i-1]
            if tmpdiff == diff:
                tmpcount += 1
                dp[i] = dp[i-1] + tmpcount
                # if dp[i-1] == 0:
                #     dp[i] = 1
                # else:
                #     dp[i] = dp[i-1] + tmpcount
            else:
                tmpcount = 0
                diff = tmpdiff
                dp[i] = dp[i-1]
        
        # print(dp)
        return dp[-1]


            
        
```