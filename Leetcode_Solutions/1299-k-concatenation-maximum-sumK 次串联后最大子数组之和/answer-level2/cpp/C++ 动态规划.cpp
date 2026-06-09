时间复杂度: O(N) N = arr.size()
空间复杂度：O(1)
```cpp
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        constexpr auto mm = 1000000007;
        const int size = arr.size() * 2;
        const int asize = arr.size();
        int sum = 0;
        for (const auto x : arr)
            sum += x;
        k %= mm;
        sum %= mm;
        auto last_dp = arr[0];
        int ret = arr[0] > 0 ? arr[0] : 0;
        for (int i = 1; i < size; i++) {
            auto cp = arr[i % asize];
            if (last_dp > 0)
                cp += last_dp;
            if (cp > ret)
                ret = cp;
            last_dp = cp;
        }
        if (sum > 0) {
            ret = ((long long)(k - 2) * sum + ret) % mm;
        }
        return ret;
    }
};
```