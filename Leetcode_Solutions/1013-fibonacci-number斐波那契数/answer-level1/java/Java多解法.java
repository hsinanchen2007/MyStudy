- 斐波那契数列，简单来说，就是除了前两个数字，每个数字等于前面两个数字之和。

### 解法一、递归

- 递归法简单，但是存在大量重复计算，可以用记忆化进行优化。

代码：

```java
class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        return fib(N - 1) + fib(N - 2);
    }
}
```



### 解法二、记忆化递归

- 记忆化是一种优化技术，主要用于**加快**计算机程序的速度，方法是**存储**昂贵的函数调用的结果，并在相同的输入再次出现时返回缓存的结果。
- 我们在之前递归的基础上，在计算之前判断是否已计算过，在计算完之后，先不要直接返回结果，而应先以当前 N 为 key，结果为 value 保存到 HashMap 中。

代码：

```java
class Solution {
    Map<Integer, Integer> map = new HashMap<>();

    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        if (map.containsKey(N)) {
            return map.get(N);
        }
        int result = fib(N - 1) + fib(N - 2);
        map.put(N, result);
        return result;
    }
}
```



### 解法三、动态规划

- 记忆化数组是自顶向下的，动态规划就把这个数组自底向上的生成。

代码：

```java
class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        int[] dp = new int[N + 1];
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
}
```



### 解法四、优化动态规划

- 要计算的状态只和前两个状态有关，只记录这两个状态，能进一步优化空间。

代码：

```java
class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        int pre = 0, cur = 1;
        for (int i = 2; i <= N; i++) {
            int next = pre + cur;
            pre = cur;
            cur = next;
        }
        return cur;
    }
}
```



### 解法五、常规矩阵乘法

$$
\begin{matrix}
\left[
	\begin{matrix}
	1 & 0\\
	0 & 0
	\end{matrix}
\right] 
\left[
	\begin{matrix}
	1 & 1\\
	1 & 0
	\end{matrix}
\right]  = 
\left[
	\begin{matrix}
	1+0 & 1+0\\
	0+0 & 0+0
	\end{matrix}
\right] = 
\left[
	\begin{matrix}
	1 & 1\\
	0 & 0
	\end{matrix}
\right]
\end{matrix}
$$

$$
\begin{matrix}
\left[
	\begin{matrix}
	1 & 1\\
	0 & 0
	\end{matrix}
\right] 
\left[
	\begin{matrix}
	1 & 1\\
	1 & 0
	\end{matrix}
\right]  = 
\left[
	\begin{matrix}
	1+1 & 1+0\\
	0+0 & 0+0
	\end{matrix}
\right] = 
\left[
	\begin{matrix}
	2 & 1\\
	0 & 0
	\end{matrix}
\right]
\end{matrix}
$$

$$
\begin{matrix}
\left[
	\begin{matrix}
	F_n & F_{n-1}\\
	0 & 0
	\end{matrix}
\right] 
\left[
	\begin{matrix}
	1 & 1\\
	1 & 0
	\end{matrix}
\right]  = 
\left[
	\begin{matrix}
	F_n+F_{n-1} & F_n\\
	0 & 0
	\end{matrix}
\right] = 
\left[
	\begin{matrix}
	F_{n+1} & F_n\\
	0 & 0
	\end{matrix}
\right]
\end{matrix}
$$

- 用矩阵的第一行记录两个数，再和$\left[
  \begin{matrix}
   	1 & 1\\
   	1 & 0
   	\end{matrix}
  \right]$相乘得出下一个矩阵。

代码：

```java
class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        int[][] matrix = { { 1, 0 }, { 0, 0 } };
        int[][] func = { { 1, 1 }, { 1, 0 } };
        for (int i = 2; i <= N; i++) {
            matrix = multiply(matrix, func);
        }
        return matrix[0][0];
    }

    private int[][] multiply(int[][] a, int[][] b) {
        int[][] c = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
}
```



### 解法六、优化矩阵乘法

- 在上一个方法中，每次都是乘一个相同的矩阵；而同一数字多个相乘即幂运算，可以用二分法优化成快速幂，而矩阵也同样可以使用，先计算$M^{n/2}$，然后在用矩阵相乘的公式即可。

  [快速幂运算题目：[LeetCode] 50. Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)


- 矩阵的起始乘积不再是 1，而是单位矩阵$\left[
  \begin{matrix}
   	1 & 0\\
   	0 & 1
   	\end{matrix}
  \right]$。

- 在这题我们就要把矩阵初始为$\left[
  \begin{matrix}
   	1 & 1\\
   	1 & 0
   	\end{matrix}
  \right]$，即从`F(2)`开始，才可以使用，矩阵结构改为$\left[
  	\begin{matrix}
  	F_n & F_{n-1}\\
  	F_{n-1} & F_{n-2}
  	\end{matrix}
  \right]$。又因为下标 2 才是第一个，所以传入时参数需要减一。

代码：

```java
class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        int[][] matrix = { { 1, 1 }, { 1, 0 } };
        int[][] result = pow(matrix, N - 1);
        return result[0][0];
    }

    private int[][] pow(int[][] matrix, int n) {
        int[][] result = { { 1, 0 }, { 0, 1 } };
        for (int i = n; i > 0; i /= 2) {
            if ((i & 1) != 0) {
                result = multiply(matrix, result);
            }
            matrix = multiply(matrix, matrix);
        }
        return result;
    }

    private int[][] multiply(int[][] a, int[][] b) {
        int[][] c = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
}
```



### 解法七、斐波那契公式

$$
F(n) = \cfrac{((\cfrac{1+\sqrt[2]{5}}{2})^n-(\cfrac{1-\sqrt[2]{5}}{2})^n)}{\sqrt[2]{5}}
$$

代码：

```java
class Solution {
    public int fib(int N) {
        double sqrt5 = Math.sqrt(5);
        return (int) ((Math.pow((1 + sqrt5) / 2, N) - Math.pow((1 - sqrt5) / 2, N)) / sqrt5);
    }
}
```



### 解法八、作弊

- 呃，先用动态规划的方式，生成 dp 数组，输出一下前 30 个，然后直接用这 30 个数就好。
- 题目说了 N 的范围。

代码：

```java
class Solution {
    public int fib(int N) {
        int[] result = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040 };
        return result[N];
    }
}
```

