> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/7952da68174e8f2c0a8cb3e2b33edcd23188f173e0efa7573c8ae2764df51800-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)


> 这两天要帮老师录制一下题解视频，所以题目挑简单一点的，减（shui）轻（liang）大（pian）家（wen）压（zhang）力。

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
这道题是动态规划入门题，我相信大家都会做，如果不会做，那就当我没说过这句话。

令 $f[i]$ 为上 $i$ 个台阶的方案数，那么最后一步可以是跳 $1$ 步，或者跳 $2$ 步，或者跳 $3$ 步过去的，所以就有：
$$
f[i] = f[i-1] + f[i-2] + f[i-3]
$$
初始情况就是 $f[1] = 1, f[2] = 2, f[3] = 4$ 。

然后利用取模的加法公式，可以每算出一个 $f[i]$ 都取一下模。

当然了这题太水了，我主要就是想看看大家会怎么实现呢？

## 代码
### 定义长度为 $n$ 的数组
最朴素的方法当然是定义长度为 $n$ 的数组，然后算就完事了，代码如下：
```cpp
typedef long long ll;
const ll p = 1e9+7;
const int N = 1e6+10;

class Solution {
public:
    ll f[N] = {1, 2, 4};
    int waysToStep(int n) {
        for (int i = 3; i < n; ++i) {
            f[i] = (f[i-1] + f[i-2] + f[i-3]) % p;
        }
        return f[n-1];
    }
};
```

### 定义四个变量
但是这样太费空间了啊，其实每次只需要用到之前的三个状态就行了，然后还要用个临时变量用来交换状态值，代码如下：
```cpp
typedef long long ll;
const ll p = 1e9+7;

class Solution {
public:
    int waysToStep(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        ll a = 1, b = 2, c = 4, d;
        for (int i = 3; i < n; ++i) {
            d = (a + b + c) % p;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};
```

### 定义长度为 $3$ 的数组
但是用 $4$ 个变量也太丑陋了，对于我这种处女座患者（对不起我是射手座）来说，完全无法忍受！

所以我直接定义了一个长度为 $3$ 的数组，然后下标对 $3$ 取模来实现循环数组，这样代码看起来就很舒服啦：

```cpp
typedef long long ll;
const ll p = 1e9+7;

class Solution {
public:
    int waysToStep(int n) {
        ll f[3] = {1, 2, 4};
        for (int i = 3; i < n; ++i) {
            (f[i%3] += f[(i-1)%3] + f[(i-2)%3]) %= p;
        }
        return f[(n-1)%3];
    }
};
```

应读者要求，再来个 `python` 代码：
```python
class Solution:
    def waysToStep(self, n: int) -> int:
        f = [1, 2, 4]
        for i in range(3, n):
            f[i%3] += f[(i-1)%3] + f[(i-2)%3]
            f[i%3] %= 1e9+7;
        return int(f[(n-1)%3])
```