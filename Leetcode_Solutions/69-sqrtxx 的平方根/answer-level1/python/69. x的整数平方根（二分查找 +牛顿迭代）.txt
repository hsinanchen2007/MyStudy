## 二分查找


### 解题思路
比起暴力搜索，用二分查找效率更高一些，二分查找主要在于确定搜索上下界以及取左中位数还是右中位数。

开始的上下界为了简洁，可以直接设为 0和 $x$ 。
进一步讨论，一个数 $x$ 的平方根$\sqrt x$一般小于等于$\frac{x}{2}$,即 $0\leq\sqrt x\leq\frac{x}{2}$ 。解这个方程可得 $x\geq4$ 。所以当 $x\geq4$ 时，在 $0$ 和 $\frac{x}{2}$ 之间进行二分查找即可。如果把 0，1，2，3都考虑进去，可以把上下界分别设为整数 0 和  x//2 + 1  。

### 代码：
```python```
```python  
class Solution:
    def mySqrt(self, x: int) -> int:
        
        left = 0    # 为了照顾到 0 把左边界设置为 0
        right = x // 2 + 1  # 为了照顾到 1 把右边界设置为 x // 2 + 1

        while left < right: 
            # mid = left + (right - left + 1) // 2 # 注意：这里一定取右中位数，如果取左中位数，代码可能会进入死循环
            mid = (left + right + 1) >> 1 
            square = mid * mid

            if square > x:
                right = mid - 1
            else:
                left = mid

        return left

```

在计算中位数时，有两种方法
1. ```mid = left + (right - left + 1) // 2```
2.  ```mid = (left + right + 1) >> 1``` 又快又好

```>> ```是右移运算，在计算机中是一种运算操作，但是他的运算结果正好能对应一个整数的二分之一值，这就正好能代替数学上的除2运算，但是比除2运算要快。

### 复杂度分析
- 时间复杂度 $O(logn)$ （二分法的时间复杂度是对数级别的）
- 空间复杂度 $O(1)$ （使用了常数个数的辅助空间用于存储和比较）

## 牛顿迭代法

### 解题思路
牛顿迭代法的思想：
    在迭代过程中，以直线代替曲线，用一阶泰勒展式（即在当前点的切线）代替原曲线，求直线与 $x$ 轴的交点，重复这个过程直到收敛。
具体：
- 求平方根，即求解 $x^2=a$ ，令 $f(x)=x^2-a$  , $f'(x)=2x$ 
- $f(x)$在点 $x_0$ 一阶泰勒展开式代替原曲线：$f(x) \approx f(x_0)+(x-x_0)f'(x_0)$
- 求直线与 $x$ 轴的交点：令 $f(x_0)+(x-x_0)f'(x_0)=0$ 得：$x=x_0-\frac{ f(x_0)}{f'(x_0)}$ 带入得为：$x=\frac{1}{2}(x_0+\frac{a}{x_0})$
- 所以迭代公式为：$x_{n+1}=\frac{1}{2}(x_n+\frac{a}{x_n})$

![e6550b4a77fbe722a9a4634619ece70e8b7e60ef7eb2e5b7af7bba3037308879-file_1563817671864.gif](https://pic.leetcode-cn.com/7b96219da63bf998a93f4dd818f4ab31b244b4fb3391b36822f133005ab8b2ba-e6550b4a77fbe722a9a4634619ece70e8b7e60ef7eb2e5b7af7bba3037308879-file_1563817671864.gif)

### 代码：
```python```
```python 
 class Solution:

    def mySqrt(self, x):
        if x < 0:
            raise Exception('不能输入负数')
        if x == 0:
            return 0
        
        cur = 2 # 起始值任意
        while True:
            pre = cur
            cur = (pre + x / pre) / 2
            if abs(cur - pre) < 1e-6:
                return int(cur)
```