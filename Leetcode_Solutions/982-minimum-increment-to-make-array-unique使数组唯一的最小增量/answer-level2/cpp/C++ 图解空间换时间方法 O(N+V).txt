先来讲一下思路：
如果一个数 x 出现了 c 次，当 c > 1 时，必然要对 c-1 个 x 执行 move 操作，以使得 x 在整个数组中具有唯一性。
那么对于 c-1 个 x+1 如何处理呢？
那当然是按照上述步骤继续处理，直到数组中的元素两两不相等：
当 c-1 > 1 时，必然对 c-2 个 x+1 执行move操作，以使得 x+1 在整个数组中具有唯一性。

因为给出的元素不会超过 40000，所以操作之后的最大元素不会超过80000。
设 maxValue 为操作之后的最大值。鉴于  maxValue 并不大我们可以使用hash数组来统计数组中每个元素的格数。之后我们遍历该数组并记录move操作的次数即可。
以 [3,2,1,2,1,5] 为例， 首先对次数进行统计，如下图所示：
![image.png](https://pic.leetcode-cn.com/e739d24de27430506a10356cf9c7dca12d0234285491f49d904e8502bc3f6aa5-image.png)


统计完成后，遍历得到的哈希数组以计算操作次数，如下图所示：
![遍历hash数组.png](https://pic.leetcode-cn.com/3f70bca706a087e60bb4cbbd0af09bf5fe57b0ee1fcf06c24e9617ecd75fbce8-%E9%81%8D%E5%8E%86hash%E6%95%B0%E7%BB%84.png)

运行结果如下图，时间很快，空间很多😂
![image.png](https://pic.leetcode-cn.com/550dd7e18130035e3907dcb27bbb5b70b7abc6643342927116e8ac2064652aa4-image.png)
```
class Solution {
public:
    enum { MAXN = 80001 };
    int mark[MAXN] = {0};
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() <= 0){
            return 0;
        }
        int maxValue = 0;
        for(size_t i = 0, n = A.size(); i < n; ++i){
            ++mark[A[i]];
            maxValue = max(maxValue, A[i]);
        }
        int ans = 0;
        maxValue <<= 1;
        for(int i = 0; i <= maxValue; ++i){
            if(mark[i] > 1){
                ans += mark[i] - 1;
                mark[i+1] += mark[i]-1;
                mark[i] = 1;
            }
        }
        return ans;
    }
};
```

# 扫码关注 HelloNebula 
![qrcode_for_gh_6e5f8557b1f8_258.jpg](https://pic.leetcode-cn.com/ef4f1e49cd234739ab5a4e4aef6c8f1098d27820f04004ace62574dda7669dd1.jpg)
