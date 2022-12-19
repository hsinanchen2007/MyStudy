#### 理解题目

```
# 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
# 
#  每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
# 
#  注意：给定 n 是一个正整数。 
# 
#  示例 1： 
# 
#  输入： 2
# 输出： 2
# 解释： 有两种方法可以爬到楼顶。
# 1.  1 阶 + 1 阶
# 2.  2 阶 
# 
#  示例 2： 
# 
#  输入： 3
# 输出： 3
# 解释： 有三种方法可以爬到楼顶。
# 1.  1 阶 + 1 阶 + 1 阶
# 2.  1 阶 + 2 阶
# 3.  2 阶 + 1 阶
#  
#  Related Topics 动态规划


# leetcode submit region begin(Prohibit modification and deletion)
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
# leetcode submit region end(Prohibit modification and deletion)

```
理解：楼梯n阶 ，从0  可以跨1步或者2步。统计所有可能方法。

#### 解题思路
* 法1：循环求斐波那契数列
* 法2：递归+缓存求斐波那契数列

#### 法1

```
class Solution:
    def climbStairs(self, n: int) -> int:
        # 法1：数学归纳法找递推公式，假设已经跳到第n阶，因为一次只能跳1阶或者2阶
        # f(n) = f(n-1) + f(n-2) ---> 发现是斐波那契数列
        if n <= 2:
            return n
        f1, f2, f3 = 1, 2, None
        for _ in range(3, n+1):
            f3 = f1 + f2
            f1, f2 = f2, f3
        return f3
```
#### 复杂度分析
* 时间复杂度：O(n)
* 空间复杂度：O(1)


#### 法2

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        def out_func():
            cache = {}  # 缓存
            def in_func(n):
                nonlocal cache
                if n <= 2:
                    return n
                if n in cache:
                    return cache[n]
                else:
                    res = in_func(n - 1) + in_func(n - 2)
                    cache[n] = res
                return res

            return in_func

        return out_func()(n)   
```
#### 复杂度分析
* 时间复杂度：O(n)
* 空间复杂度:O(n)