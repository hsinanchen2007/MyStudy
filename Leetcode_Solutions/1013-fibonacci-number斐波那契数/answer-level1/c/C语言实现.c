# 1. 迭代方法

$$
\begin{array}{c|rr}
n & \text{curr} & \text{next}\\
\hline
0 & 0 & 1\\
1 & 1 & 1\\
2 & 1 & 2\\
3 & 2 & 3\\
4 & 3 & 5\\
5 & 5 & 8\\
6 & 8 & 13\\
...&...&...
\end{array}
$$

时间复杂度为 $O(n)$，空间复杂度为 $O(1)$。

```C []
int fib(int n){
    int curr = 0, next = 1;
    while (n-- > 0) {
        next = next + curr; // 辗转相加法，F(n) = F(n-1) + F(n-2)
        curr = next - curr; // 记录前一项，F(n-1) = F(n) - F(n-2)
    }
    return curr;
}
```

# 2. 时间复杂度为 $O(\text{log}n)$ 的实现

```C []
int fib_iter(int a, int b, int count) {
    if (0 == count) return b;
    return fib_iter(a + b, a, count - 1);
}

int fib(int n) {
    return fib_iter(1, 0, n);
}
```

在这种算法中，时间复杂度为 $O(n)$，我们每次递归都将 $a+b$ 的值赋给 $a$，把 $a$ 的值赋给 $b$，通过观察可以发现，从 1 和 0 开始将规则反复应用 $n$ 次，将产生一对数 $f_{n+1}$ 和 $f_n$，现在将这种规则看成：

$$
\begin{aligned}
\left(
\begin{array}{l}
f_{n+1} \\
f_n
\end{array}
\right)
&=
\begin{pmatrix}
p+q & q \\
q   & p
\end{pmatrix}
\left(
\begin{array}{l}
f_n \\
f_{n-1}
\end{array}
\right)\\
&=
T
\left(
\begin{array}{l}
f_n \\
f_{n-1}
\end{array}
\right)\\
&=
T^n
\begin{pmatrix}
f_1 \\
f_0
\end{pmatrix}\\
&=
T^n
\begin{pmatrix}
1 \\
0
\end{pmatrix}
\end{aligned}
$$

其中 $p=0$，$q=1$ 把这种变换称为 $T$ 变换，$T$ 的二次方如下：

$$
\begin{aligned}
T^2
&=
\begin{pmatrix}
p+q & q \\
q   & p
\end{pmatrix}
\begin{pmatrix}
p+q & q \\
q   & p
\end{pmatrix}\\
&=
\begin{pmatrix}
(p^2+q^2)+(2pq+q^2) & 2pq+q^2 \\
2pq+q^2   & p^2+q^2
\end{pmatrix}\\
&=
\begin{pmatrix}
p'+q' & q' \\
q'   & p'
\end{pmatrix}
\end{aligned}
$$

其中 $p'=p^2+q^2$，$q'=2pq+q^2$

根据 $T^n$ 中 $n$ 的奇偶性，如果为奇则更新状态，如果为偶则更新转移矩阵 $T$，可以实现时间复杂度为 $O(\text{log}n)$ 的算法。

## 2.1 递归实现

时间复杂度为 $O(\text{log}n)$，空间复杂度 $O(\text{log}n)$。

```C []
int fib_iter(int a, int b, int p, int q, int count) {
    if (count == 0)
        return b;
    else if (count & 1) // T 的奇数次方，更新状态 a, b
        return fib_iter((p + q) * a + q * b, q * a + p * b, p, q, count - 1);
    else // T 的偶数次方，更新转移矩阵
        return fib_iter(a, b, p * p + q * q, 2 * p * q + q * q, count / 2);
}

int fib(int n) {
    // 初始状态 f(1) = 1, f(0) = 0
    // 初始转移矩阵 p = 0, q = 1
    return fib_iter(1, 0, 0, 1, n); 
}
```

## 2.2 迭代实现

时间复杂度为 $O(\text{log}n)$，空间复杂度 $O(1)$。

```C []
int fib(int n) {
    // 初始状态 f(1) = 1, f(0) = 0
    // 初始转移矩阵 p = 0, q = 1
    int tmp, a = 1, b = 0, p = 0, q = 1;
    while (n > 0) {
        if (n & 1) { // T 的奇数次方，更新状态 a, b
            tmp = a;
            a = (p + q) * a + q * b;
            b = q * tmp + p * b;
            --n;
        } else { // T 的偶数次方，更新转移矩阵
            tmp = p;
            p = p * p + q * q;
            q = 2 * tmp * q + q * q;
            n >>= 1;
        }
    }
    return b;
}
```