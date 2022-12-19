题目：在给定 m×n 的矩阵中，找到在矩阵中由 1 组成的最大正方形。

本体的[官方题解](https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode/)给出了的动态规划解法没讲明白，容易看晕。

实际可以降维理解，两者本质是一样的：
- 本题要求：在二维数组中，求正方形内部全部为1的最大正方形面积。
- 降维理解：在一维数组中，求线段内部全部为1的的最大线段长度。

对于后者，再简单不过了。例如，给出数组nums [1, 0, 1, 1, 1]，求连续1的最长长度。

## 一维数组

### 普通解法

设定两个变量，ans表示最终答案（最长长度），tmp表示当前连续1的长度，遍历nums：若当前字符为1，则tmp+1，更新ans；若为0，则tmp重置为0。最后ans即是最大长度。
```
ans = 0
tmp = 0
for i in range(nums):
    if nums[i] == 0:
        tmp = 0
    else:
        tmp += 1
        ans = max(ans, tmp)
return ans
```
对于[1, 0, 1, 1, 1]，ans和tmp变量变化如下所示：
```
i       /   0   1   2   3   4
nums[i] /   1   0   1   1   1
tmp     0   1   0   1   2   3   
ans     0   1   0   1   2   3 
```

### 动态规划

dp[i+1]表示nums中从0到i区间内最近一次连续1的长度，也就是上表中tmp变量的含义，区别在于动态规划把单变量tmp扩展成了一个长度为len(nums)+1的连续序列。
```
ans = 0
dp = [0 for _ in range(len(nums)+1)]
dp[0] = 0
for i in range(nums):
    if nums[i] == 0:
        dp[i+1] = 0
    else:
        dp[i+1] = dp[i] + 1
        ans = max(ans, dp[i+1])
return ans
```
对于[1, 0, 1, 1, 1]，ans和dp[]变量变化如下所示：
```
i       /   0   1   2   3   4
nums[i] /   1   0   1   1   1
dp[i+1] 0   1   0   1   2   3   
ans     0   1   0   1   2   3 
```
这样看来，dp[]和tmp就是一模一样的，而且tmp更省空间。

## 二维数组

### 动态规划

再来看本题，二维数组中的动态规划怎么理解。
类似的，dp[i+1][j+1]表示matrix中从0到i行、从0到j列范围内最近一次连续1的正方形边长。
设matrix的行数为m，列数为n，则dp行数为m+1，列数为n+1，dp的第0行、第0列可以理解为最开始tmp的初值，均为0。

```
if len(matrix) == 0 or len(matrix[0]) == 0:
    return 0

m = len(matrix)
n = len(matrix[0])

ans = 0
dp = [[0 for _ in range(n+1)] for _ in range(m+1)]

for i in range(m):
    for j in range(n):
        if matrix[i][j] == '0':
            dp[i+1][j+1] = 0
        else:
            dp[i+1][j+1] = min(dp[i][j], dp[i+1][j], dp[i][j+1]) + 1
            ans = max(ans, dp[i+1][j+1])
return ans ** 2
```
二维代码结构与一维完全一样，区别在于递推公式
- 一维：`dp[i+1] = dp[i] + 1`
- 二维：`dp[i+1][j+1] = min(dp[i][j], dp[i+1][j], dp[i][j+1]) + 1`

怎么理解呢？回到dp定义，dp[i+1][j+1]表示matrix中从0到i行、从0到j列范围内**最近一次连续1的正方形**边长。
可以把dp[i][j], dp[i+1][j], dp[i][j+1]看做当前遍历到的字符matrix[i][j]的左上角、左边、上边的三个正方形，正方形面积可以为0，可以为正数，如果为正数，正方形会有重叠部分。dp[i+1][j+1]是一个新的正方形，这个新正方形的面积为三个正方形的交集+1，可以理解为一个木桶中能装的水取决于最短的那块木板，所以进行min操作。

### 优化空间

与一维空间dp[]、tmp类似，动态规划空间复杂度为O(mn)，可以优化为O(m)或O(n)。