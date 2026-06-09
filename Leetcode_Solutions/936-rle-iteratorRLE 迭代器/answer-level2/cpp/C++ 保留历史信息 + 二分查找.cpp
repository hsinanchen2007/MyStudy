运行4ms，超过100%
详见代码注释：
```
class RLEIterator {
public:
    using ll = long long;
    vector<int> nums;
    vector<ll> counts; // 保留截止到每个位置之前数的总个数
    ll past; // 已经遍历过的数据总个数
    ll total; // 数据总个数
    int left; // 查询起始下标
    int N; 
    RLEIterator(vector<int>& A) {
        N = A.size() / 2;
        nums.resize(N);
        counts.resize(N);
        past = 0;
        left = 0;
        for (int i = 0; i < N; ++i) {
            nums[i] = A[2 * i + 1];
            counts[i] = ((i > 0) ? counts[i - 1] : 0) + A[2 * i];
        }
        total = counts[N -1];
    }
    int bisearch(ll n) {
        int l = left;
        int r = N - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (counts[m] < n) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
    int next(int n) {
        past += n;
        if (past >= total) {
            left = N;
            return -1;
        }
        left = bisearch(past);
        return nums[left];
    }
};
```
![image.png](https://pic.leetcode-cn.com/d65da026e308eba81a5d6e74753158b90ce70a26ab9a034eda78df3b0ec50b9b-image.png)
