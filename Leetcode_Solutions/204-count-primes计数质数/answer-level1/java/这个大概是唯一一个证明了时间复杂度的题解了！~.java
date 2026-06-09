### 前言

素数这个概念人类已经研究了上千年，但是的具体的起源却不得而知。早在公元前300年，欧几里得就在他的著作*元素*中证明了有无穷多个素数，同时也证明了任何一个整数都能够被某一个素数整除。时至今日，素数在计算机科学这样一个和数学联系紧密的学科中也有这个广泛的应用，比如布隆过滤器、伪随机数、RSA加密算法等等，所以掌握素数的特性以及应用能够帮助我们解决不少实际问题。

### 简介

素数（又称质数）是一个只能被1和它自己整除的整数，换句话说他只有两个因数——1和它自己。比如3是一个素数，因为3只能被1和3整除，但是6不是素数因为它能被2和3整除。迄今为止发现的最大的素数是$2^{57885161}-1$，由中央密苏里大学的数学家Curtis Cooper发现，大概有17,425,170位数字。

在公元前200年，古希腊数学家埃拉托色尼（Eratosthenes）创造了一套算法用来计算素数，这就是大家熟知的埃拉托色尼筛选法（the Sieve of Eratosthenes），这是最早的用来计算素数的方法。就拿100以内素数的方法来简单介绍一下这个筛选法：

首先我们找到第一个素数2，用圆圈标出来，然后划掉所有2的倍数4、6、8等等。然后我们找到下一个没有被划掉的数字（这个数字肯定不是前面更小数字的倍数），也就是3，用圆圈标出来，再划掉所有的3的倍数，注意这里6已经被划掉了，但是9可以继续被划掉。接下来再用圆圈标出下一个没有被划掉的数字5，划掉所有的5的倍数。如此往复，直到100的平方根10截止，所有的100以内的素数就都被圆圈圈起来了。

![the Sieve of Eratosthenes](https://pic.leetcode-cn.com/83bc6882d2ae6e64159f81229bdad4c9a845a61e0e69c610305dce4e4ad14dda-1.jpg)

### 计数质数

来看看素数计算的最简单的版本，Leetcode第204题[计数质数](https://leetcode-cn.com/problems/count-primes/)。

统计所有小于非负整数 n 的质数的数量。

示例：
> 输入: 10
> 输出: 4
> 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

这道题通过我们在上面介绍的埃拉托色尼筛选法可以很轻松的做出来，只需要创建一个小于`n`的数组，从索引`2`开始一直到`Math.sqrt(n)`对整个队列进行筛选，最后统计一遍整个数组里面所有的素数就行了。

```java
public int countPrimes(int n) {
    if (n <= 2) return 0;
    boolean[] primes = new boolean[n];  //创建整个素数数组
    Arrays.fill(primes, true);      //初始化全部位素数
    primes[0] = false;
    primes[1] = false;                  //划掉0和1
    int sqrt = (int)Math.sqrt(n);       //设置上界
    for (int i = 2; i <= sqrt; i++) {
        if (!primes[i]) continue;       //不是素数，可以跳过
        for (int multi = i<<1; multi < n ; multi += i){
            primes[multi] = false;      //划掉倍数
        }
    }
    int count = 0;
    for (boolean prime : primes) {      //统计数组中素数的数量
        if (prime) count++;
    }
    return count;
}
```

运行了上面的代码之后，执行时间17ms，才击败了60%的用户，代码还有很大的优化空间。我们从上一个小节的筛选法中就可以看到，我们经常要划掉已经被划掉的数字，比如在划掉了所有的2的倍数6之后，我们在划掉3的倍数的时候又划掉了6一次，这样就浪费了我们的资源，能不能直接跳过6去划掉9呢？所以这里就是需要考虑要从哪个数字开始划数字。在划掉2的倍数的时候，我们是划掉2x2、2x3、2x4、2x5等等，在划掉3的时候是划掉3x2（在素数2的那一轮已经被划掉了）、3x3、3x4、3x5等，在划掉5的时候是划掉5x2（素数2的一轮已经被划掉了）、5x3（素数3的一轮被划掉了）、5x4（等于10x2也在素数2的一轮被划掉了）、5x5等等。现在这个规律应该十分明显了，在划掉素数`i`的倍数的时候，所有比`i`小的数字的和`i`的乘积已经被划掉了，所以下一轮直接从`i*i`开始就行了，于是我们可以把上面代码里面的`multi`初始化为`i*i`，代码我就不贴出来了。

其实这道题还有挺多的改进方法的，比如使用`BitSet`来代替`boolean`的数组、用`false`代表是位置`i`是质数来缩短数组的初始化时间或者在第一个for循环里面就统计所有非质数省去最后一个循环，可以用很多方法减少冗余操作的时间，不过整体最终的时间复杂度是$O(NloglogN)$，第一个for循环是不可避免的，下面我们来用一些数学知识来解释一下这个时间复杂度。

首先我们有数字`n`代表素数的上边界（不包含），`p`代表小于`n`的最大素数，内部循环设置`false`的时间是恒定的。

当`i==2`时，内部的筛除操作进行了$\frac{n}{2}$次

当`i==3`时，筛除了$\frac{n}{3}$次

当`i==4`时，直接跳过，筛除了$0$次（所有的非素数都会跳过）

当`i==5`时，筛除了$\frac{n}{5}$次

当`i==p`时，筛除了$\frac{n}{p}$次

所以总体的运行时间可以看作：

$$\frac{n}{2}+\frac{n}{3}+\frac{n}{5}+...\frac{n}{p}$$

等效于

$$n\times(\frac{1}{2}+\frac{1}{3}+\frac{1}{5}+...\frac{1}{p})$$

现在就是要证明

$$\frac{1}{2}+\frac{1}{3}+\frac{1}{5}+...\frac{1}{p} = loglogn$$

在进行下面的证明的时候，我们需要用到**调和级数**、**泰勒级数**、**欧拉乘积公式**，这几个公式的证明过程感兴趣的可以自己去看看（在我的参考文档里面，纯数学部分，比写代码难多了），就先说我们要用到的定理。

---

**调和级数**（Harmonic series）是一个发散的无穷级数，当$n$趋近于无穷大时，有一个近似公式：

$$ 1 + \frac{1}{2} + \frac{1}{3} + ... = \sum_{i=1}^{n}\frac{1}{i} = ln(n)+\gamma$$

其中$\gamma$为欧拉常数，$\gamma \approx 0.57721$

---

**泰勒级数**（Taylor series）是1715年英国数学家布鲁克·泰勒提出的，在零点的导数求得的泰勒级数又叫麦克劳林级数，具体的原版的公式我就不在这里贴出来了，这里只贴一个常用的泰勒级数，也就是以$e$为底数的自然对数的麦克劳林序列

$$ln(1-x) = -\sum_{n=1}^{\infty} \frac{x^n}{n} = -x-\frac{x^2}{2}-\frac{x^3}{3}-..-\frac{x^n}{n}$$

对任意属于$[-1,1)$内的$x$都成立。左右的符号同时取反，可以得到：

$$ln(1-x)^{-1} = \sum_{n=1}^{\infty} \frac{x^n}{n} = x+\frac{x^2}{2}+\frac{x^3}{3}+..+\frac{x^n}{n}$$

---

**欧拉乘积公式**（Euler product）是著名的瑞士数学家欧拉于1737年在俄罗斯的圣彼得堡科学院发表的重要公式，为数学家研究素数的分布奠定了基础，即：

$$\sum_{n} n^{-s} = \prod_{p}^1 (1-p^{-s})^{-1}$$

其中`n`为自然数，`p`为素数。

---

继续我们的推理。

在欧拉公式中，我们如果将所有的$s$用$1$来代替就可以得到

$$\sum_{n} n^{-1} = \prod_{p}^1 (1-p^{-1})^{-1}$$

对两侧同时使用$log$函数可以得到

$$ln(\sum_{n} n^{-1}) = ln(\prod_{p}^1 (1-p^{-1})^{-1})$$

简化之后可以得到

$$ln(\sum_{n} n^{-1}) = \sum_{p} ln((1-p^{-1})^{-1})$$

因为$-1 < p^{-1} < 1$，所以可以对上面公式的右侧的每一项进行泰勒展开得到

$$ln((1-p^{-1})^{-1}) = \sum_{n=1}^{\infty} \frac{1}{np^{n}}$$

当$p$趋近于无穷大的时候，右侧的公式收敛于$\frac{1}{p}$，就可以得到

$$ln((1-p^{-1})^{-1}) = \frac{1}{p}$$

代入到原公式可以得到

$$ln(\sum_{n} n^{-1}) =\sum_{p} \frac{1}{p} $$

上述公式左侧log内部正好是调和级数，把调和级数的近似公式代入左侧可以得到

$$ \sum_{p} \frac{1}{p} = ln(ln(n)+\gamma) $$

忽略右边的常数$\gamma$就可以得到最后的时间复杂度为$O(nln(ln(n)))$，也就是$O(nloglogn)$级别。

除了这个证明过程之外，在数论里面已经有一个定理证明这个时间复杂度——[Mertens' second theorem](https://en.wikipedia.org/wiki/Mertens%27_theorems)（维基百科需要科学上网，中文材料好像特别少）。

能够看到这个地方已经说明你有着超人般的毅力（还有什么比数学更令人头疼），如果觉得上面的讲解还不够清楚或者有很多数学的细节不太理解，可以看看参考文档。据我在网上查到的，还没有任何一篇文章能够像这篇一样把埃拉托色尼筛选法的时间复杂度讲的这么清楚的，希望能够帮助到大家。

### 参考

>[Prime Numbers–Why are They So Exciting?](https://kids.frontiersin.org/article/10.3389/frym.2018.00040)
>[prime number](https://whatis.techtarget.com/definition/prime-number)
>[What is a Prime Number?](https://www.livescience.com/34526-prime-numbers.html)
>[如何高效判定、筛选素数](https://leetcode-cn.com/problems/count-primes/solution/ru-he-gao-xiao-pan-ding-shai-xuan-su-shu-by-labula/)
>[LeetCode一求素数算法优化的简单研究](https://blog.csdn.net/Mynewclass/article/details/80272303)
>[How is the time complexity of Sieve of Eratosthenes is n*log(log(n))?](https://www.***.org/how-is-the-time-complexity-of-sieve-of-eratosthenes-is-nloglogn/)
>[调和级数近似求和公式推导](https://blog.csdn.net/u010622506/article/details/83039816)
>[欧拉乘积公式的推导过程](https://blog.csdn.net/pang9998/article/details/96218600)
>[泰勒公式](https://baike.baidu.com/item/%E6%B3%B0%E5%8B%92%E5%85%AC%E5%BC%8F)
>[泰勒级数](https://zh.wikipedia.org/wiki/%E6%B3%B0%E5%8B%92%E7%BA%A7%E6%95%B0)
>[EULER AND THE PARTIAL SUMS OF THE PRIME HARMONIC SERIES](http://pollack.uga.edu/eulerprime.pdf)
>[Mertens' theorems](https://en.wikipedia.org/wiki/Mertens%27_theorems)

更多内容请看我的[**个人博客**](http://sunshuyi.vip)