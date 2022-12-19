![image.png](https://pic.leetcode-cn.com/0e17a8111baa3be96bc0efbff174fe6ea1d46cb03cef368b52f1b34d8ad8a1c8-image.png)


```
'''
动态规划
dp(i, j) 表示前i行中，最后一行选择位置j时候的最小路径和，如果只是这么单纯的
定义，dp(i, j) = arr[i][j] + min(dp(i-1, jj)) 其中jj != j

整个枚举是三层枚举，i, j和 jj 复杂度太高了

其实题目要求相邻的两行选的列是不一样的，比较烦人的情况就是冲突的情况
但是如果能知道上一层i-1中最小的和出现的列以及和的次小值，(次小值和最小值可能是值一样，但是在i-1层出现位置不同)
情况就不同了，如果j和上一层出现和最小值的位置是冲突的，那上一层选和的次小值就行了，次小值在上一层可能有多个可选位置
但是不管是哪个位置，都和最小值位置不同，那肯定是根j不冲突的，这个时候dp[i][j] 就是 arr[i][j]和上一层次小值
的和，反之，j和上一层最小值所在位置不冲突的话，dp[i][j]就是arr[i][j]和上一层和最小值的和

还有一种操蛋的情况是上一层最小值有多个可选位置是什么情况呢？那其实就是上一层在多个同等地位的最小值位置位置中
选了两个位置，分别作为最小值位置和次小值位置，不管这两个位置选的是哪两个，都不会影响到下一层的运算结果，
假设这两个位置是k1作为最小值位置, k2作为次小值位置，k1 不论在i-1层选到哪，dp[i][k1]的值都等于上一层次小
值(其实这个时候上一层最小值和次小值相等)加上arr[i][k1]，k1选不同的值，只是在下一层发生冲突的位置不同，
但是不管冲突在哪个位置，冲突位置的第i层dp值算出来都是一样的，其他不冲突的位置的值也不会受到上一层k1选在同等位置
中哪一个而受影响，所以根本不用考虑多个同等位置到底选哪个的问题，选哪个算出来最后结果都是一样的，因为下一层
的运算结果根本不会受这个影响，最终结果自然也就跟这个选择无关了，所以每一层都只维护最小值和最小值
出现位置，次小值位置可以不感知不维护，可以保证最终递推结果的正确性，这个正确性的原因想了半天

'''

from typing import List
class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        first_min_val = 0      # 到上一层为止的最小和
        second_min_val = 0     # 到上一层为止的次小和
        first_min_pos = -1     # 上一层最小值出现的位置

        for i in range(len(arr)):
            first_min, second_min, first_pos = 0x7fffffff, 0x7fffffff, -1
            for j, val in enumerate(arr[i]):
                dp_val = second_min_val + arr[i][j] if j == first_min_pos else first_min_val + arr[i][j]
                if dp_val < first_min:
                    second_min, first_min, first_pos = first_min, dp_val, j
                elif dp_val < second_min:
                    second_min = dp_val

            first_min_val, first_min_pos, second_min_val = first_min, first_pos, second_min
        return first_min_val

```
