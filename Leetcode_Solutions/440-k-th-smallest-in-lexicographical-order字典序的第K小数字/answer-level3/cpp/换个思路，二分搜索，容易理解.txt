### 解题思路
取一个 n = 123。任取 1 ~ n 中一个 **三位数** x = 115，有多少 小于等于n 的数按字典序排在 x 之前（或与 x 相同）？
- 三位数：100 ~ 115
- 二位数：10 ~ 11
- 一位数：1

上面的规律适用于所有的 **位数 == n** 的 x。

另一个规律是，对于所有的三位数 100 ~ 123，其字典序排名是递增的。
因此可以在区间 [100, 123] 进行二分搜索，找到 **字典序排名 >= k** 且 **最接近 k** 的 **三位数**。
记数字 x 的字典序排名为 rank(x).

##### 例外1、如果最大的三位数 x = 123 的排名 rank(123) < k：
那么所求的数一定在 123 之后，且是位数小于 3 的数。
看一下 123 附近的按字典序排序的数：
```
118
119
12  <- 字典序在 123 之前的最后一个 位数小于 3 的数
121
122
123 <- 设 kn = rank(123)，k > kn，则后面尚需 kn - k 个一位数和两位数。
13  <- 在 123 之后一定都是 位数小于 3 的数
14
```
所以可以先求数字 12 在 **所有的 一位数 和 两位数（即 <= 99 的数）** 中的字典序排名，求法同最上面的求法。记为 rank_99(12)。
而在其之后仍需 k - rank(123) 个 <= 99 的数。
这相当于 **求小于 99 的数中，排名为 rank_99(12) + k - rank(123) 的数**，递归调用即可。

##### 例外2、如果二分查找结束后，rank(x) > k：
那说明排在 x 之前必插有位数小于 3 的数：
比如，排在 119 之后但在 120 之前的数为 12。
```
119
12
120
```
再如，排在 100 之前的数有 10 和 1。
```
1
10
100
```
因此可以每次将数除以 10，rank--，直到 rank == k。

### 代码

```cpp
class Solution {
public:
    // 求 x 在所有 位数 <= x 的数中的 字典序 rank.
    int getRank(int x)
    {
        string s = to_string(x);
        int res = 0, from = pow(10, s.size() - 1);
        while(x)
        {
            res += x - from + 1;
            x /= 10;
            from /= 10;
        }
        return res;
    }
    int findKthNumber(int n, int k) {
        string s = to_string(n);
        int kn = getRank(n);

        // 例外 1: rank(n) < k
        if(kn < k)
            return findKthNumber(pow(10, s.size() - 1) - 1, getRank(n / 10) + k - kn);

        int l = pow(10, s.size() - 1), r = n;
        while(l < r)
        {
            int m = (l + r) / 2;
            int cnt = getRank(m);
            if(cnt < k) l = m + 1;
            else r = m;
        }
        int kl = getRank(l);

        // 例外 2: rank(l) > k
        while(kl-- > k)
            l /= 10;

        return l;
    }
};
```