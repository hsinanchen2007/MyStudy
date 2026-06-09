### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:

    meno = []
    def climbStairs(self, n: int) -> int:
        if n < 0:
            return 0
        self.meno = [-1 for i in range(n+1)]
        return self.getStep(n)
    def getStep(self,n:int) -> int:
        # 状态转移方程 f(n) = f(n-1) + f(n-2) 
        # 自顶向下 递归
        # 程序结束条件
        if n == 0 or n == 1:
            return 1
        if self.meno[n] != -1:
            return self.meno[n]
        res = self.getStep(n-1) + self.getStep(n-2)
        self.meno[n] = res
        return res 

        
```
# 1.状态转移方程
每次可以爬 1 或者 2 个台阶，所以爬第3个台阶时，就是用爬1个台阶 和 爬2个台阶 的和
**状态转移方程 f(n) = f(n-1) + f(n-2) **
# 2.剪枝
有大量的重复计算
![Snip20200204_1.png](https://pic.leetcode-cn.com/289fc43c195deafc3bd3090b393285e9bf208feea719fc8d98f017424ab8eedf-Snip20200204_1.png)

用memo列表记录已经计算过的f(n),大大减少了计算次数

# 3.复杂度
时间复杂度:O(n)
空间复杂度:O(n)