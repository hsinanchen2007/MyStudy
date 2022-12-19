![image.png](https://pic.leetcode-cn.com/961468a4ea3fb202bb8488e5cbf54cef3109bf53bf6942d43eaf02ea6428794b-image.png)

使用自底向上的动态规划快速求解。

本题提交代码：
```cpp
class Solution {
private:
    int even_calculate (int a, int b) {
        return a * a + 2 * a * b;
    }

    int odd_calculate (int a, int b) {
        return a * a + b * b;
    }

public:
    int fib(int n) {
        if (n == 0) return 0;

        int count = 32;
        unsigned int ruler = 0x80000000;
        // 跳过n前面的0bit位
        while ((n & ruler) == 0) {
            ruler >>= 1;
            count--;
        }
        ruler >>= 1;
        count--;
        int a = 1, b = 0, tmp = a + b, c = 2, d = 1;
        for (int i = 0; i < count; i++) {
            if (n & ruler) {
                tmp = a + b;
                c = odd_calculate(tmp, a);
                d = even_calculate(a, b);
            } else {
                c = even_calculate(a, b);
                d = odd_calculate(a, b);
            }
            a = c;
            b = d;
            ruler >>= 1;
        }
        
        return a;
    }
};
```

讲解部分，也可以去我[个人网站](https://www.keyanjie.net/one-more-thing-about-fibonacci/)看：

斐波那契数的计算方式是：
$$
fib(n)=\left\{\begin{matrix}
0 & n=0\\
1 & n=1\\
fib(n-1)+fib(n-2) & n\geq 2 \\
\end{matrix}\right.
$$

# ⚡️算法核心

如果要将算法的时间复杂度降下来，那么就要改改上面的斐波那契数列递推公式。

当n足够大时，做如下推理：
![image.png](https://pic.leetcode-cn.com/fdebc6445b397b1ec186a52811c8694f015042e3f3ffe8d6b9b56cb0a5fcf5ce-image.png)


看多项式的系数，不正是斐波那契数列的项吗？
![image.png](https://pic.leetcode-cn.com/05dfa921049ee5a522b6365ab8bbc6b817e9137b64c6f1300442e736e54caa33-image.png)
通过上述推理，发现了一个规律，其中i可以是1到n中任意一个数：
$$
fib(n)=fib(i)fib(n+1-i)+fib(i-1)fib(n-i) \quad \forall i \in \{x|1\leq x \leq n\}
$$
而当$i$取$n$的一半时，这个公式就发生了一些奇妙的变化。

取一半这个操作需要考虑n是奇数还是偶数：

## n为奇数

此时$i$为$(n+1)/2$，代入公式可得：
![image.png](https://pic.leetcode-cn.com/7157891818ebcccd44b9ea0b1143c20971f0d2fafdca4040bc4ebfebd1983a86-image.png)


## n为偶数

此时$i$为$n/2$，代入公式可得：
![image.png](https://pic.leetcode-cn.com/cf9e037382b05344bcbdd97b9b4668cf61b47b6a64ac1fe8e8347865ccb02574-image.png)


## 合并一下公式

$$
fib(n)=\left\{\begin{matrix}
0 & n=0\\
1 & n=1\\
[fib(\frac{n+1}{2})]^2 + [fib(\frac{n-1}{2})]^2 & \text{n >1 and n is odd} \\
[fib(\frac{n}{2})]^2+2fib(\frac{n}{2})fib(\frac{n}{2}-1)& \text{n > 1 and n is even}\\
\end{matrix}\right.
$$

这样n就不直接和自己的后两项发生关系，而是和自己的一半那个数扯上关系了。

# 🚄递归代码

## 思路

使用上述递推式可以很容易写出的递归代码，虽然是个效率很低的递归思路，但是也比最朴素的递归求斐波那契数的算法效率高不少。

## 代码

```cpp
#include <iostream>
using namespace std;

unsigned long long fib(int n) {
    if (n == 0) return 0;
    
    if (n == 1) return 1;
    
    if (n & 1) {
        return fib((n + 1) / 2) * fib((n + 1) / 2) + fib((n - 1) / 2) * fib((n - 1) / 2); // a为奇数
    } else {
        return fib(n / 2) * fib(n / 2) + 2 * fib(n / 2) * fib(n / 2 - 1); // a为偶数
    }
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
```

# 🛩使用记忆法进行优化

## 思路

记忆法是动态规划的一个变种，和上面的差不多，同样也是自顶向下的递归算法，区别在于算过的值都被记录下来，避免重复计算，提升了不少效率，这就是时间复杂度O(log(n))空间复杂度O(n)的算法：

## 代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

// memory数组用于记录是否计算过这个值，默认都是0
// 如果memory中此值是0，表示需要计算，计算完将结果填入memory数组中
// 如果此值已经计算过，直接从memory中取出即可
vector<unsigned long long> memory;

unsigned long long fib(int n) {
    if (n == 0) {
        memory[0] = 0;
        return memory[0];
    }
    else if (n == 1) {
        memory[1] = 1;
        return memory[1];
    }
    
    if (memory[n] != 0)
        return memory[n];
    
    if (n & 1) {
        memory[n] = fib((n + 1) / 2) * fib((n + 1) / 2) + fib((n - 1) / 2) * fib((n - 1) / 2); // a为奇数
    } else {
        memory[n] = fib(n / 2) * fib(n / 2) + 2 * fib(n / 2) * fib(n / 2 - 1); // a为偶数
    }
    return memory[n];
}

int main() {
    int n;
    cin >> n;
    memory.resize(n + 1);
    cout << fib(n) << endl;
    return 0;
}
```

# 🚀使用迭代法进一步优化

这是真正自底向上的算法了，迭代法算法可以在时间复杂度O(log(n))空间复杂度O(1)下计算第n个斐波那契数。

## 思路

### 迭代规则

首先这样思考：

1、如果我使用$fib(n)=fib(n-1)+fib(n-2)$的递推思路，那么当我要求得$fib(n)$的值时，必须把$fib(0) - fib(n-1)$的值全部算出来；

2、现在改为折半的递推思路，那么当我要求得$fib(n)$的值时，需要计算哪些值呢？

举个栗子，当我要计算$fib(2729)$时：

1、2729是奇数，需要先求得$fib(1365)$和$fib(1364)$（因为[奇数公式](#n为奇数)），而$fib(1365)$是可以通过$fib(1363)+fib(1364)$求得的，这里只需要求出$fib(1363)$和$fib(1364)$。

**为什么是求这两个数而不是求$fib(1365)$和$fib(1364)$，这是我踩的一个大坑。**

**我可以算$fib(1365)$和$fib(1364)$，也可以算$fib(1364)$和$fib(1363)$。**

而我自己规定，遇到以下两种情况：

1. 所需要求的fib(n)​中，n是奇数时（比如这里2729是奇数）;
2. 一个要求先求得fib(x+1)和fib(x)，另一个需要先求得fib(x)和fib(x-1)时。比如下面求fib(341)和fib(340)的部分。

都算后面两个数。**而且整个计算图都需要保持计算规则的一致性，都计算后面两个数。**

2、计算$fib(1364)$，1364是偶数，需要先求得$fib(682)$和$fib(681)$。

3、计算$fib(1363)$，1363是奇数，需要先求得$fib(682)$和$fib(681)$。

发现要计算的数是一样的，都是$fib(682)$和$fib(681)$

4、计算$fib(682)$，682是偶数，需要先求得$fib(341)$和$fib(340)$。

计算$fib(681)$，681是奇数，需要先求得$fib(341)$和$fib(340)$。

5、计算$fib(341)$，341是奇数，需要先求得$fib(171)$和$fib(170)$。

计算$fib(340)$，341是偶数，需要先求得$fib(170)$和$fib(169)$。

这时要计算的数就不一样了，但是$fib(171)$可以通过$fib(170)$和$fib(169)$很轻易算出——$fib(171)=fib(170)+fib(169)$，所以只需要计算$fib(170)$和$fib(169)$就好了。

However，计算$fib(171)$和$fib(170)$也是可以的。**但是计算规则要一致，要么就都算后两个，要么就都算前两个。**

而我选择计算后两个，因为可以更快收敛到$fib(1)$和$fib(0)$。(其实差别不大)

6、如此递推下去，直到$fib(1)=1$和$fib(0)=0$为止……

可以画出一张计算图，若需要计算相同的斐波那契数，在右边标记为0；若需要计算不同的斐波那契数，但通过后两项相加得前一项，在右边标记为1（红色的标记暂时不管，这是代码中考虑的部分）：

![fib2729.png](https://pic.leetcode-cn.com/2d54521b336818593eae532aa78a2955cdcbd62d4c40fb9dc35bae4e8632bc97-fib2729.png)

**迭代规则总结**

每次迭代都需要计算两个斐波那契数，记为$fib(a)$和$fib(b)$，**最终要求得的值是$fib(a)$**。

1、当a为偶数时，计算$fib(a)$和$fib(b)$需要相同的数；

2、当a为奇数时，计算$fib(a)$和$fib(b)$需要的数不同，我的计算规则是只算后两个；

每次计算都会因为a的奇偶性不同而采取不同的运算策略，也就是只根据a的奇偶性，就可以知道该如何运算了。

**如果到这里为止都看懂了再继续往下看。**

### 获取计算图

每次二分操作都要分a是奇数还是偶数，可以通过不断的将a进行模2运算得出结果。这个操作有没有觉得似曾相识，当初十进制转二进制不就是这么算的吗，也就是说最顶端的数，即要求的数$fib(n)$的二进制表示方法就是一张现成的计算规则。

还是比如$fib(2729)$，2729的二进制表示是1010 1010 1001，而上面计算图右边的数从下往上看，就是他的二进制表示。

或者换个思路想，上面迭代规则总结中，是按a奇偶性分情况处理的，那么a的奇偶性会导致不同的模2结果，也就是n的二进制表示计算方式。

在代码中，我使用了一个`ruler`的变量来读取n二进制的每一个bit位的值。具体操作如下：

1、n是一个`int`型的变量，共有32个bit位；

2、`ruler`是用于读取n的指定bit位的值的工具，初始化时`ruler`的第一个bit位是1，其他都是0，将`ruler`与`n`进行按位与运算，结果为0表示`n`这一个bit位是0；结果非0表示`n`这一个bit位是1；

3、读取次数使用`count`变量来记录，`count`初始值为32，表示需要统计32次；

4、跳过n前面的0bit位，计算机存储一个正数的时候，前面会补0，要先把这些0跳掉，一个`while`循环搞定：

```cpp
while ((n & ruler) == 0) {
    ruler >>= 1;
    count--;
}
```

5、跳过第一个为1的bit位，所有的数第一个有效bit位都是1，上面的计算图也可以看出跳过这个bit位，从第2个bit位开始；

```cpp
ruler >>= 1;
count--;
```

6、此时`a`和`b`两个数就是$fib(1)$和$fib(0)$。设置`tmp`变量，用于奇数运算时，存储$fib(a)+fib(b)$的值。设置`c`和`d`变量，用于接收运算结果；

7、处理完后`c`的值赋予`a`，`d`的值赋予`b`，进入下一轮迭代；

8、最后取`a`的值作为所要求的结果。为什么取`a`不取`b`，因为我的计算规则里就是始终把`a`作为要求得的值。

## 代码

我没有兼容求$fib(0)$，感觉不跳第一个有效位可以兼容，但我这里没有深入思考。

```cpp
#include <iostream>
using namespace std;

unsigned long long even_calculate (unsigned long long a, unsigned long long b) {
    return a * a + 2 * a * b;
}

unsigned long long odd_calculate (unsigned long long a, unsigned long long b) {
    return a * a + b * b;
}

int main() {
    int n, count;
    cin >> n;
    count = 32;
    unsigned int ruler = 0x80000000;
    // 跳过n前面的0bit位
    while ((n & ruler) == 0) {
        ruler >>= 1;
        count--;
    }
    ruler >>= 1;
    count--;
    unsigned long long a = 1, b = 0, tmp = a + b, c = 2, d = 1;
    for (int i = 0; i < count; i++) {
        if (n & ruler) {
            tmp = a + b;
            c = odd_calculate(tmp, a);
            d = even_calculate(a, b);
        } else {
            c = even_calculate(a, b);
            d = odd_calculate(a, b);
        }
        a = c;
        b = d;
        ruler >>= 1;
    }
    
    cout << a << endl;
    
    return 0;
}
```