### 解题思路
来自[字节跳动面经分析](https://www.***.com/discuss/383236?type=2&order=3&pos=31&page=1)
参见[题解](https://leetcode-cn.com/problems/airplane-seat-assignment-probability/solution/ju-ti-fen-xi-lai-yi-bo-by-jobhunter-4/)
使用 动态规划，令 P[n] 代表有n个人时，第n个人能够坐正确的概率。
考虑第一个人的三种情况：
1. 第一个人坐在第一个位置上，那么第 n 个人必然正确。
2. 第一个人坐在第n 个位置上，那么第 n 个人必然失败
3. 第一个人坐在第 i 个位置上 (2<=i<=n-1), 那么从 [2,i-1] 人都能坐正确，考虑第 i 个人的座位，第 i 个人将会随机选一个位置，有如下的可能：
+ 第 i 个人坐在第一个位置上，
+ 第 i 个人坐在第 n 个位置上，
+ 第 i 个人坐在 [i+1, n-1] 的位置上，
这三种情况相当于第 i 个人成为了第 1 个人，等价于问题 P[n-i+1]

如此就有： P[n] = 1/n*0 + 1/n*1 +1/n*(P[n-1] + ... + P[2])
P[1] = 1
P[2] = 0.5
P[3] = 0.5
递推下去， P[n] = 0.5


### 代码

```python3
class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        ## 字节跳动面试题，在字节群里的面经里看到过
        # P[n] 代表问题的解，则 考虑第一个人的做法，
        # P[n] =1/n*1 + 
        if n == 1:
            return 1
        else:
            return 0.5 

```