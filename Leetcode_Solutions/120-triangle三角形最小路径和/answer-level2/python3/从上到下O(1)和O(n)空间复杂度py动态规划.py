原列表修改，空间复杂度为O(1)
```
def minimumTotal(triangle):
    i = 1
    while i < len(triangle):
        triangle[i][0] += triangle[i-1][0]
        triangle[i][-1] += triangle[i-1][-1]
        for j in range(1,len(triangle[i])-1):
            triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j])
        #print(triangle[i])
        i += 1
    return min(triangle[-1])
```
动规分析的时候还是自底向上，写的时候是从上到下，两端值分别为上面两端累加，中间的值为对应上一层和上一层前一个小的值加上自身

新开dp列表每次循环赋值并更新，空间复杂度为O(n)
```
def on(triangle):
    dp = [float('inf')]*len(triangle)
    dp[0] = triangle[0][0]
    i = 1
    while i < len(triangle):
        for j in range(len(triangle[i])-1,0,-1):
            dp[j] = min(dp[j],dp[j-1]) + triangle[i][j]
        dp[0] += triangle[i][0]
        #print(dp)
        i += 1
    return min(dp)
```
因为要取小值，所以dp列表初始化为正无穷，每次循环从后向前更新不影响前面值得判断，从前往后可能出现前面的值修改后影响后面值的更新，具体自己画图尝试即可明白
最后更新首项
最后给出样例的输出结果
```
[5, 6]
[11, 10, 13]
[15, 11, 18, 16]
11

[5, 6, inf, inf]
[11, 10, 13, inf]
[15, 11, 18, 16]
11
```


