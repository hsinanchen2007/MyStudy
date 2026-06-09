### 法一:递归$\mathcal{qpow}$

&emsp;这里举一个例子来说明**快速幂**的原理:
$eg:7^{10}$  
&emsp;假如我们正常的理解下,不就是$7$乘个十次嘛，这样当然可以，也足以应对很多场景了。但是当$a^n$中的$\mathcal{n}$非常大时，这个$O(n)$的幂运算好像不太够，那有没有什么办法能够降低幂运算的时间复杂度呢？
- 方法1：先算7的5次方，即$7*7*7*7*7$，再算它的平方，共进行了$5$次乘法。但这并不是最优解，因为对于“7的5次方”，我们仍然可以拆分问题。
- 方法2：先算$7*7$得$49$，则7的5次方为$49*49*7$，再算它的平方，共进行了$4$次乘法。模仿这样的过程，我们得到一个在  时间内计算出幂的算法，也就是**快速幂**。(此处借用了部分知乎上的内容)

&emsp;方法二，运用的无非是一个**二分**的思路，因此我们可以很轻松的得到一个**递归方程**:
$$
a^n = \left\{\begin{aligned}
&1 & if\;n == 0 \\
&a^{n-1} * a &if\; n\;is\;odd\\
&a^{\frac{n}{2}} * a^{\frac{n}{2}} & if \; n \; is \; even\\
\end{aligned}
\right.
$$
&emsp; 因此我们可以比较自然的写出递归解法，**有一点需要注意**(不过你可以先试着写写然后看是否犯错)!!
```cpp
using LL = long long;
using db = double;
class Solution {
    db qpow(db a, LL n){
        if (n < 0) return qpow(1/a, -n);
        if (!n) return 1.0;
        else if (n & 1) return qpow(a, n - 1) * a;
        else {
            double tmp = qpow(a, n / 2);
            return tmp * tmp; // 🚩
        }
    }
public:
    double myPow(double x, int n) {
        return qpow(x, n);
    }
```
&emsp;**标旗子的地方有没有写错呢**，假如直接`return qpow(a, n/2) * qpow(a, n/2)`，那还是计算了两次，对于复杂度就没有降低了~
### 法二:迭代优化~
&emsp;但是递归会有额外的空间开销，那我们得想办法把他转为**迭代**如下图，我们可以把$7^{10}$分为两种来看，一种是正常的就是一次次乘，另一种就是看起来比较抽象的：**把10转为二进制，你可以跟着下图走一遍过程再看看代码**！！。
![image.png](https://pic.leetcode-cn.com/e98b14a638b73eddf8120b5a4aa6cf7f128abd5a6d2728a004a92d40ea4a9903-image.png)
![image.png](https://pic.leetcode-cn.com/06878402c987d9296af1258720e57c716574d09e77e880e7fa65b7a4ee8f000c-image.png)

```cpp
using LL = long long;
class Solution {
public:
    double myPow(double x, int n) {
        LL t;
        double ans(1.0); // initialize

        if (n < 0) x = 1/x;
        t = LL(std::abs(n));
        while (t){
            if (t & 1) ans *= x; // 假如低位为1,则乘上x
            x *= x; // x自乘
            t = t >> 1; // 右移一位
        }

        return ans;
    }
};
```
&emsp;最后用一张我最近看网课的时候看到的一段话做结尾,其中$\mathcal{Karatsuba}$算法是用于解决大数乘法的算法,其在解决问题时也用了**二分这个性质**,但之所以用这个是因为这句对于我这种算法小白来说很贴合也很有启示:

&emsp;**我可能会看不懂这魔术般的算法,但没关系,浸淫其中,即使未能如所愿,但也见过,那广袤而瑰丽的算法世界；**
![image.png](https://pic.leetcode-cn.com/89ba37c7bf7acd72beb8f5873385cc520b562ced81f204925e9c939a22749ff4-image.png)
