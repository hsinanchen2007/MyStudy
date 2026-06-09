# 滑动窗口

```c++ []
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int res = n+1;
        int cur = 0;
        for (int i = 0, j = 0; i < n; i++) {
            cur += nums[i];
            while (j <= i && cur >= s) {
                res = min(res, i - j + 1);
                cur -= nums[j];
                ++j;
            }
        }
        return res == n+1 ? 0 : res;
    }
};
```


# 前缀和 + 二分

```c++ []
class Solution {
private:
    int binaryFind(const vector<int>& sums, int end, int x) {
        int l = 0, r = end;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (sums[mid] <= x) l = mid;
            else r = mid - 1;
        }
        return sums[l] > x ? -1 : l;
    }
    
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> sums(n+1, 0);
        for (int i = 1; i <= n; i++) sums[i] = sums[i-1] + nums[i-1];
        
        int res = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int x = sums[i] - s;
            int bound = binaryFind(sums, i-1, x);
            if (bound != -1) res = min(res, i - bound);
        }
        return res == INT_MAX ? 0 : res;
    }
};
```
