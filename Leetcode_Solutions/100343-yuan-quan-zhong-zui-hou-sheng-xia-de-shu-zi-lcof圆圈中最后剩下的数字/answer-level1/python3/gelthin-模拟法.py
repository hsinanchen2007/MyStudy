### 解题思路
这里不能直接取  m = m%n

例如: [0,1,2] n=3, m=4, 在前进过程中 n 的值会变化，导致 m%n 不对，除非每一步对新的 n 进行调整。


#### 1. 模拟法
每次直接删除一个数字，然后再处理。

这一题有一点像直接 swap 数字一步到位的题目，通过复杂的计算，可以得到闭式最优解。


#### 2.约瑟夫环问题 递归分析

记 f(n, m) 为 (n, m) 问题的解，那么考虑 f(n-1, m) 是 (n-1, m) 的解
设n第一次拿走了第 m 个数 (m-1)，那么接下来对 n-1 个数来求解子问题，实际上是对这样的数组 [m, m+1,..., n-1, 0, ..., m-2], 把 m 当做了 0, 执行了运算 (x+n-m)%n 得到 [0, 1, 2, ..., n-2]， 对于解 f(n-1, m), 我们再做处理，
(f(n-1, m) + m)%n 即可。 于是有 f(n, m) = (f(n-1,m)+m)%n
这有点像[1227. 飞机座位分配概率](https://leetcode-cn.com/problems/airplane-seat-assignment-probability/)。 
第一个人坐在了第 k 个人的位置上， 则第 k 个人又来解决相当于第一个人的子问题。








### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        ## 双向队列
        nums = [x for x in range(n)]
        i = -1
        for _ in range(n-1): # 删除 n-1 次
            i = (i+m)%len(nums)  # 这里 len(nums) 在变化
            nums.pop(i)
            i -= 1  # 这里是由于删了一个数字 i 就指到了下一个数字，不妥
        
        return nums[0]
```