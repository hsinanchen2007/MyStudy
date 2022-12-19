> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/8431a9c798d8f8808b2f9a803e4ad7aea136671d43f574ebc01216606dfeb128-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)

## 题解
### 位运算
首先将数组里的数再加上 $1$ 到 $n$ 中所有的数构成一个更大的集合，那么问题就变成了**一个数组里有两个数只出现了一次，其余数都出现了两次，求这两个数是多少？**

是不是很熟悉？这其实就是 LeetCode 另一道位运算题目：
[LeetCode 面试题56 - I. 数组中数字出现的次数](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/ "LeetCode 面试题56 - I. 数组中数字出现的次数")

首先还是常规套路，把所有的数异或起来，得到的值 $x$ 一定就是出现一次的两个数的异或值。

那么再回顾一道最基本的位运算题：
[LeetCode 136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/ "LeetCode 136. 只出现一次的数字")

也就是**一个数组里有一个数只出现了一次，其余数都出现了两次，求这个数是多少？**这就很简单了，只需要全部异或起来就是这个数的值了。

那么回到本题，有没有办法将这 $2n-2$ 个数拆分成两个集合，每个集合都满足上面这种最简单的条件（只有一个数出现了一次）呢？

刚刚得到了两个只出现一次数字的异或值 $x$ ，那么 $x$ 中的 $1$ 就表示了这两个数那一位是不同的。那就很简单了啊，我们把所有 $2n-2$ 个数那一位是 $0$ 的归为一个集合，那一位是 $1$ 的归为一个集合，那么这两个只出现一次的数一定会分属两个不同的集合。而其他出现了两次的数，每个数字都会在同一个集合里。

最后对两个集合分别求异或值，就得到了两个出现一次数的值了。

这里有个关键点，就是按照 $x$ 某一位为 $1$ 来划分两个集合，其实取任意一位是 $1$ 的位都是可以的。但是最简单的方法就是取最低位 $1$ ，因为这样可以采用位运算 $x \& (-x)$ 直接得到。

位运算系列还有一个进阶版：
[LeetCode 137. 只出现一次的数字 II](https://leetcode-cn.com/problems/single-number-ii/ "LeetCode 137. 只出现一次的数字 II")

这题就与本题无关了，我们留着下次继续讲。

### 数学法
首先假设缺失的两个数字为 $x, y$ 。

令 $S_1$ 为 $nums$ 数组中的元素和，$S_2$ 为 $nums$ 数组中的元素平方和。

再用 $1$ 到 $n$ 的元素和减去 $S_1$ 就得到了 $x+y$ 的值，记为 $a$。用 $1$ 到 $n$ 的元素平方和减去 $S_2$ 就得到了 $x^2+y^2$ 的值，记为 $b$。

最后只要解出下面这个二元二次方程组就行了：
$$
\begin{aligned}
&x + y = a   \\\
&x^2 + y^2 = b
\end{aligned}
$$
用求根公式可以解出两个解是：
$$
\frac{a \pm \sqrt{2b-a^2}}{2}
$$
其中：
$$
\begin{aligned}
&a = \sum_{i=1}^n{i} - \sum_{i=0}^{n-3}{nums[i]} = \frac{n(n+1)}{2}  - \sum_{x \in nums}{x}  \\\
&b = \sum_{i=1}^n{i^2} - \sum_{i=0}^{n-3}{(nums[i])^2} = \frac{n(n+1)(2n+1)}{6} - \sum_{x \in nums}{x^2}
\end{aligned}
$$

### 下标哈希
一个很直觉的方法就是，我新开辟一个大小为 $n+1$ 的数组，然后把 $nums$ 数组中的元素都放在新数组中下标对应的位置，最后看哪两个位置没有数就行了。但是现在要用原地算法，不允许新开辟空间，那我们就只能直接放在原数组里面了。

首先我们还是得把原数组扩展到大小为 $n+1$，也就是在末尾增加 $3$ 个空间，数字就放 $-1$。

然后遍历数组，对于 $nums[i]$ 来说，它的位置上最后放的应该是数字 $i$ 才对，而 $nums[i]$ 应该被放在下标为 $nums[i]$ 的位置。所以我们把 $nums[i]$ 移动到下标为 $nums[i]$ 的位置上去，但是 $nums[i]$ 位置上的数字怎么办呢？不能直接覆盖，不然就再也无法访问了，所以我们把它移动到下标 $i$ 的位置就行了。也就是说交换下标 $i$ 和 $nums[i]$ 位置上的两个数。

那么问题接着来了，位置 $nums[i]$ 上面的数对了，但是位置 $i$ 上面的数还是错的啊。那么只要继续重复交换操作，直到位置 $i$ 位置上面的数是 $i$ ，或者是 $-1$ 就行了。

最后所有数都摆回正确位置了，再扫描一遍数组，如果 $nums[i] = -1$ ，就说明 $i$ 这个数不在数组里。

这个方法理论上适合缺任意 $k$ 个数，只需要一开始在数组后面补上 $k+1$ 个 $-1$ 就行了。


## 代码
### 位运算（c++）
```cpp
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (auto i : nums) x ^= i;
        for (int i = 1; i <= n+2; ++i) x ^= i;
        int lb = x & -x;
        int y = 0;
        for (auto i : nums) {
            if (i&lb) y ^= i;
        }
        for (int i = 1; i <= n+2; ++i) {
            if (i&lb) y ^= i;
        }
        return {y, y^x};
    }
};
```

### 数学法（c++）
```cpp
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        long n = nums.size()+2;
        long S1 = accumulate(nums.begin(), nums.end(), 0);
        long S2 = 0;
        for (auto x : nums) S2 += x*x;
        long a = n*(n+1)/2-S1;
        long b = n*(n+1)*(2*n+1)/6-S2;
        long x = (a+sqrt(2*b-a*a))/2;
        long y = (a-sqrt(2*b-a*a))/2;
        return {x, y};
    }
};
```

### 下标哈希（c++）
```cpp
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        for (int i = 0; i < 3; ++i) {
            nums.push_back(-1);
        }
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != -1 && i != nums[i]) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        vector<int> res;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == -1) res.push_back(i);
            if (res.size() == 2) break;
        }
        return res;
    }
};
```
