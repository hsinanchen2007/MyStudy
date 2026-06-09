```
class Solution {
public:
    vector<int> decimals(int n) {
        vector<int> res;
        while (n > 0) {
            res.push_back(n % 10);
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int monotoneIncreasingDigits(int N) {
        auto nums = decimals(N);
        int i = 0;
        while (i + 1 < nums.size() && nums[i + 1] >= nums[i]) {
            ++i;
        }
        if (i == nums.size() - 1) {
            return N;
        }
        while (i > 0 && nums[i - 1] == nums[i]) --i;
        int res = 0;
        for (int j = 0; j < i; ++j) {
            res = res * 10 + nums[j];
        }
        res = res * 10 + nums[i] - 1;
        for (int j = i + 1; j < nums.size(); ++j) {
            res = res * 10 + 9;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/21fcba63444e0553c3d827ea1860698d1ccb3c77721ab04690a40ad51d7b022c-image.png)
