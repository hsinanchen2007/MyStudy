问题等价于：求最小的正整数 $k$，满足存在一个正整数 $m$ 使得 $\displaystyle\sum_{i=0}^{m} k^{i}=\frac{1-k^{m+1}}{1-k}=n$．

由于 $n$ 的取值范围很大，$k$ 的取值范围也很大，直接对 $k$ 从 $2$ 开始遍历的话是不行的．但注意到 $m$ 作为指数，取值范围比 $k$ 小很多，而要使 $k$ 最小等价于使 $m$ 最大，因此可以考虑对 $m$ 从大到小进行遍历，并求出对应的 $k$ 即可．

由
$$\frac{1-k^{m+1}}{1-k}=n$$
可得
$$m=\log _{k}(k n-n+1)-1<\log _{k}(k n)=1+\log _{k} n，$$
又由题知 $k \geq 2, m \geq 1$，所以有
$$1 \leq m \leq \log _{2} n．$$

故对于题目给定的 $n$，我们只需要对 $m$ 从 $\log _{2} n$ 到 $1$ 遍历，对每次遍历中的 $m$ 我们都要检查是否存在对应的正整数 $k$ 满足 $\displaystyle\frac{1-k^{m+1}}{1-k}=n$，一旦找到这样的 $k$，我们就将其返回即可．

我们使用二分法来找到满足条件的正整数 $k$．$k$ 的最小值为 $2$，又由
$$\frac{1-k^{m+1}}{1-k}=n$$
可得
$$k^{m+1}=n k-n+1< n k，$$
即
$$k<\sqrt[m]{n}．$$

故在区间 $[2, \sqrt[m]{n}]$ 上二分地查找 $k$ 即可．

代码如下：

```cpp
class Solution {
public:
  string smallestGoodBase(string n) {
    long long int num = atoll(n.c_str());
    for (int m = log2(num); m >= 1; m--) {
      long long l = 2, r = powl(num, 1.0 / m) + 1, mid, sum;
      while (l < r) {
        mid = (l + r) / 2;
        sum = 1;
        for (int j = 0; j < m; ++j) {
          sum = sum * mid + 1;
        }
        if (sum == num) {
          return string(to_string(mid));
        }
        else if (sum < num) {
          l = mid + 1;
        }
        else {
          r = mid;
        }
      }
    }
    return "";
  }
};
```
![TIM截图20190630182020.png](https://pic.leetcode-cn.com/d8afe7872f71ee44393516b5849875c8ae3e1f65053ab12b9b28cf2c37c707cd-TIM%E6%88%AA%E5%9B%BE20190630182020.png)
