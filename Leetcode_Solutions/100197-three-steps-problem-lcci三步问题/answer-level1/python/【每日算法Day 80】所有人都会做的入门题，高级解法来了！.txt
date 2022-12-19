> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/5da42820faaf66f01adec224113d9c7442f3e6bd9cd1342d7c3b933f3fec36a0-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)


> 题目还是昨天的题，昨天已经介绍了三种解法了，今天介绍一个最快的方法。

## 题目链接
[LeetCode 面试题 08.01. 三步问题](https://leetcode-cn.com/problems/three-steps-problem-lcci/ "LeetCode 面试题 08.01. 三步问题")

## 题目描述
三步问题。有个小孩正在上楼梯，楼梯有 $n$ 阶台阶，小孩一次可以上 $1$ 阶、$2$ 阶或 $3$ 阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模 $1000000007$。


**示例1**
```text
输入：
n = 3 
输出：
4
解释：
有四种走法
```

**示例2**
```text
输入：
n = 5
输出：
13
```

## 题解
昨天的题解地址：  
[韦阳的博客：【每日算法Day 79】所有人都会做的入门题，但是能看出你的代码能力！](https://godweiyang.com/2020/03/24/leetcode-inteview-08-01/ "韦阳的博客：【每日算法Day 79】所有人都会做的入门题，但是能看出你的代码能力！")

[知乎专栏：【每日算法Day 79】所有人都会做的入门题，但是能看出你的代码能力！](https://zhuanlan.zhihu.com/p/115799226 "知乎专栏：【每日算法Day 79】所有人都会做的入门题，但是能看出你的代码能力！")

昨天是通过动态规划来解决的，转移方程为：
$$
f[i] = f[i-1] + f[i-2] + f[i-3]
$$
初始情况是 $f[1] = 1, f[2] = 2, f[3] = 4$ 。

如果通过递推的方式来求解的话，时间复杂度是 $O(n)$ ，但是我们还可以用矩阵快速幂的方法加速到 $O(\log n)$ 。

相信大家快速幂一定听说过（没听说过当我没说），如果让你求 $a^n$，那么可以分两种情况。如果 $n$ 是偶数，那么可以计算 $a^{n/2}$，然后求它的平方 $(a^{n/2})^2$ 就行了。如果 $n$ 是奇数，那么可以计算 $a^{(n-1)/2}$，然后求它的平方 $a \cdot (a^{(n-1)/2})^2$ 就行了。这样只需要用 $O(\log n)$ 的复杂度就可以计算出 $a^n$ 了。

类似的，如果我们要计算一个矩阵的幂 $A^n$，也可以将其拆分成两半，然后计算一半再平方就行了。

那么这题跟矩阵有什么关系呢？如果我们把转移方程右边三项写成向量形式：
$$
\begin{bmatrix}
    f_{i-3} & f_{i-2} & f_{i-1}
\end{bmatrix}
$$
那么给它右边乘上一个矩阵 $A$：
$$
\begin{bmatrix}
    0 & 0 & 1 \\
    1 & 0 & 1 \\
    0 & 1 & 1
\end{bmatrix}
$$
那么就会得到向量：
$$
\begin{bmatrix}
    f_{i-2} & f_{i-1} & f_{i-1}+f_{i-2}+f_{i-3}
\end{bmatrix}
$$
即：
$$
\begin{bmatrix}
    f_{i-2} & f_{i-1} & f_{i}
\end{bmatrix}
$$
所以乘一次矩阵 $A$ 就可以得到下一个 $f$ 值，那么从初始的向量 $\begin{bmatrix}1 & 2 & 4\end{bmatrix}$ 开始，乘上 $A^{n-3}$ 就可以得到 $\begin{bmatrix}f_{n-2} & f_{n-1} & f_{n}\end{bmatrix}$ 了。

而这里的 $A^{n-3}$ 就可以通过矩阵快速幂来计算得到。

## 代码
### c++
```cpp
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
const ll p = 1e9+7;

class Solution {
public:
    vvl mat_mul(vvl& A, vvl& B) {
        int a = A.size(), b = B.size(), c = B[0].size();
        vvl C(a, vl(c, 0));
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int k = 0; k < b; ++k) {
                    (C[i][j] += A[i][k] * B[k][j]) %= p;
                }
            }
        }
        return C;
    }

    vvl mat_pow(vvl& A, int n) {
        int m = A.size();
        vvl B(m, vl(m, 0));
        for (int i = 0; i < m; ++i) B[i][i] = 1;
        while (n > 0) {
            if (n&1) B = mat_mul(B, A);
            A = mat_mul(A, A);
            n >>= 1;
        }
        return B;
    }

    vvl mat_pow_rec(vvl& A, int n) {
        if (n == 1) return A;
        vvl B = mat_pow_rec(A, n/2);
        B = mat_mul(B, B);
        if (n&1) return mat_mul(A, B);
        return B;
    }

    int waysToStep(int n) {
        vl f = {1, 2, 4};
        if (n <= 3) return f[n-1];
        vvl A = {{0, 0, 1}, {1, 0, 1}, {0, 1, 1}};
        vvl B = mat_pow(A, n-3);
        ll res = 0;
        for (int i = 0; i < 3; ++i) {
            (res += f[i] * B[i][2]) %= p;
        }
        return res;
    }
};
```


### python
```python
import numpy as np

class Solution:
    def mat_pow(self, A, n):
        m = A.shape[0]
        B = np.eye(m, dtype=np.int64)
        while n > 0:
            if (n&1)!=0:
                B = np.mod(np.matmul(B, A), self.p).astype(np.int64)
            A = np.mod(np.matmul(A, A), self.p).astype(np.int64)
            n >>= 1
        return B;

    def waysToStep(self, n: int) -> int:
        self.p = int(1e9+7)
        f = [1, 2, 4]
        if n <= 3: return f[n-1]
        A = np.array([[0, 0, 1], [1, 0, 1], [0, 1, 1]], dtype=np.int64)
        B = self.mat_pow(A, n-3)
        res = 0
        for i in range(3):
            res += f[i] * B[i][2]
        return int(res%self.p)
```