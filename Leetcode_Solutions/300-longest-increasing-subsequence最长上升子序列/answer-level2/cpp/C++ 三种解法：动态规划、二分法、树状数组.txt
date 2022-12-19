# 解法一：
动态规划
```C++ []
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/936aa461a08fee70df14491f7f675a6bcd1833c479729ec32c0bfeac707993de-image.png)


# 解法二：
二分查找更新法
```C++ []
class Solution {
public:
    int bisearch(vector<int>& nums, int t) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < t) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> res;
        for (auto n : nums) {
            if (res.empty() || res.back() < n) {
                res.push_back(n);
            }
            int i = bisearch(res, n);
            res[i] = n;
        }
        return res.size();
    }
};
```
![image.png](https://pic.leetcode-cn.com/8a9659d0a024225a61256dd505d60abcd11f0a9422c7e8338727fad9350d507f-image.png)


# 解法三：
树状数组
1，离散化数组
2，每次都找比当前数小的最长递增序列，不断更新结果
```
class Solution {
public:
    vector<int> bits;
    int N;
    void add(int i, int d) {
        while (i <= N) {
            bits[i] = max(bits[i], d);
            i += i & (-i);
        }
    }
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res = max(res, bits[i]);
            i -= i & (-i);
        }
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> s(nums.begin(), nums.end());
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        N = s.size() + 1;
        bits = vector<int>(N + 1, 0);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int k = lower_bound(s.begin(), s.end(), nums[i]) - s.begin();
            res = max(res, 1 + query(k));
            add(k + 1, query(k) + 1);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/be68095b4f7bf16b4e281f0680b2f39bd9dea0bf5181c5d6ff732426355b2933-image.png)
