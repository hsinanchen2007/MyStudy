### 解题思路
普通的筛法相信大家很容易明白，但它还有优化的空间
普通筛法的冗余性在于，一个数可能被多个质因子筛到
如6被2、3筛，12也被2、3筛，这样的情况，导致普通筛法的复杂度无法到达线性
那么怎么避免这种情况呢？
很简单，保证每个数，**只会被它最小的质因子筛掉即可**。
在下面的代码中，体现这一条的是
`if (i % prime[j] == 0) break;`
也就是说，假设30要被筛掉，30=2*3*5，则30只在当i=15，取到质数2时被筛掉
原因留给读者慢慢思考
网上也有很多线性筛的资料，这里就不赘述

由于线性筛中每个数只会被筛一次，所以复杂度是O(n)的

### 代码
```cpp
class Solution {
public:
    int countPrimes(int n) {
        int prime[n+1]; //存放质数
        int label[n+1]; //标记数组
        memset(label, 0, sizeof(label));
        int m = 0;
        for (int i = 2; i < n; ++i) {
            if (label[i] == 0)
                prime[m++] = i;
            for (int j = 0; j < m; ++j) {
                if (i * prime[j] >= n)
                    break;
                label[i * prime[j]] = 1;
                if (i % prime[j] == 0)
                    break;
            }    
        }
        return m;
    }
};
```