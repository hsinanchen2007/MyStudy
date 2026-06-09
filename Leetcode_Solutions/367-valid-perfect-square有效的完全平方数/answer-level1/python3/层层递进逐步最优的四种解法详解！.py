> 参考了 https://leetcode-cn.com/problems/valid-perfect-square/solution/si-chong-jie-fa-pan-duan-wan-quan-ping-fang-shu-by/ 这篇题解，作了Python化地处理以及作了更多的内容上的补充。

## 第一招：暴力解法
+ 首先i从1开始，判断这个数是不是i的平方
+ 不是的话，i 每次加1
+ 直到超过了num
```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = 1
        while i * i < num:
            i += 1
        return i * i == num
```
+ 这个方法的时间复杂度是`O(sqrt(N))`
## 第二招：二分查找
+ 第一种方式显得不够优雅。
+ 因为找到符合条件的i实在是太慢了
+ 所以我们可以想到使用二分查找的方法来加快这一过程。
```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        l, r = 1, num
        while l < r:
            mid = (l + r) // 2
            if mid * mid < num:
                l = mid + 1
            else:
                r = mid
        return l * l == num
```
+ 这个方法的时间复杂度是`O(log(N))`，比第一种方法好，因为开log比根号小
## 第三招：等差数列
+ 有一个公式
$$
1 + 3 + 5 + 7 + ... (2N-1)= N^2
$$
+ 所以任意一个平方数可以表示成这样的奇数序列和。
```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = 1
        while num > 0:
            num -= i
            i += 2
        return num == 0
```
+ 这个方法的时间复杂度是`O(sqrt(N))`，这个比第一种方法好，但是就复杂度而言，两者是一样的。

## 第四招：牛顿迭代法

+ 方法是这样
+ 我们整一个方程，想必我们要求的就是这个x
$$
x ^ 2 = num
$$
+ 它可以变换为
$$
x^2 - num = 0
$$
+ 你可以画一下左边部分的函数图像，即一个凹的弧，与x轴有两个交点，在右侧的节点就是我们所想要的解，很明显。
+ 我们不知道这个x是多少，先初始化任意一个值，比如说num
+ num * num 自然是远远大于num了。这时候我们要缩小x。
+ 怎么缩小呢？
+ 我们对准这个点（num,num*num）作关于这个函数图像的切线，它与x轴有一个新的交点。这个交点的横坐标便是更接近我们的目标值的点。
+ 往复这个过程，便能得到越来越接近的值。
+ 那么切线方程怎么整呢？
+ 我们知道对函数图像上一点求导，得到的就是这个点的斜率。
+ 知道了一个点和斜率，便可以得到这根直线，便可以得到它与x轴的交点。
+ 那么这根切线可以表示成$y = f'(x_n)x+ b$
+ 代入已知点，可得
+ $f(x_n) = f'(x_n)x_n +b$
+ 得到$b = f(x_n) - f'(x_n)x_n$
+ 所以这根切线就是
+ $y = f'(x_n)x+ f(x_n) - f'(x_n)x_n$
+ 我们代入$y =0$，就可以得到新的x值
+ $x_{n+1} = (f'(x_n)x_n - f(x_n))/f'(x_n) = x_n - \frac{f(x_n)}{f'(x_n)}$
+ 所以！我们利用这个公式就可以求出来下一个x啦！代入约分以后可得
$$
x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)} = x_n - \frac{x^2_n - a}{2x_n} = \frac{x^2_n + a}{2x_n} = \frac{1}{2} (x_n + \frac{a}{x_n})
$$
```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = num
        while i * i > num:
            i = (i + num / i) // 2
        return i * i == num
```
+ NP问题设定好了maximum iteration和epsilon之后，当然收敛速度才是最重要的指标。所以时间复杂度是一个无关紧要的概念。