### 解题思路
参考了题解 [详细通俗的思路分析，多解法](https://leetcode-cn.com/problems/different-ways-to-add-parentheses/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-5-5/)

有点像是矩阵乘法加括号。
考虑最后一次运算所对应的运算符，以此运算符为界，把数组分为两部分，左边求出所有可能，右边求出所有可能，再组合起来。

### 延后处理
先从字符串中提取出所有的数组和运算符，构成两个数组 nums, opers。
注意到这里for 循环收集 nums 的过程是延后处理（else 才处理），因此经常会导致最后一步后仍然需要再处理一下

二维动态规划:

DP[i][j] 代表了数组 nums[i:j] 的所有可能。

使用 DP 时就是要注意，规划次序，这里要画一下图思考一下。
+ 当 i == j: DP[i][i] = [nums[i]]
+ 当 i<j:
    DP[i][j] = [ DP[i][i]#DP[i+1][j], DP[i][i+1]#DP[i+2][j], ..., DP[i][j-1]#DP[j][j] ]
+ 计算次序，沿着次对角线 (j-i = k) 逐个从下往上计算
    计算 DP[n-2][n-1], DP[n-3][n-2], ..., DP[1][2], DP[0][1]
    计算               DP[n-3][n-1], ..., DP[1][3], DP[0][2]

    最后计算出                                       DP[0][n-1]
一直调试一个弱智的 bug 调了好久。


### 代码

```python3
class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        operators = {'+', '-', '*'}
        nums, opers = [], []
        i = 0
        for j in range(len(input)):
            if input[j] in operators: 
                nums.append(int(input[i:j]))  # 延后处理当碰到 input[j] 是 oper, 才处理 [i:j]
                opers.append(input[j])  
                i = j+1
        ## 一直以来，bug 在这里, 统计漏了最后一个数
        nums.append(int(input[i:]))  # 延后处理
        n = len(nums)

        DP = []
        for i in range(n):
            DP.append([])
            for j in range(i):  # 对 j<i DP[i][j] = None
                DP[i].append(None)
            DP[i].append([nums[i]])    # DP[i][i] = [nums[i]]
            for j in range(i+1, n):
                DP[i].append([])   # 当前为空，待填


        for k in range(1, n):   # j-i = k
            for i in range(n-k-1,-1,-1): # i 从 n-2 到 0
                j = i + k   # 计算 DP[i][j] nums[i...j] 的所有可能
                for t in range(i, j):  # DP[i][t], DP[t+1][j]
                    if opers[t] == '+':
                        DP[i][j] += [x+y for x in DP[i][t] for y in DP[t+1][j]]
                    elif opers[t] == '-':
                        DP[i][j] += [x-y for x in DP[i][t] for y in DP[t+1][j]]
                    else:
                        DP[i][j] += [x*y for x in DP[i][t] for y in DP[t+1][j]]


        return DP[0][n-1]
```