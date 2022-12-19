详细注释都在代码中
```
class Solution {
public:
    vector<int> digits(int n) {
        vector<int> res;
        while (n > 0) {
            res.push_back(n % 10);
            n /= 10;
        }
        return res;
    }
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        vector<int> C(11, 0); // C[i]代表D中有多少个数比i小
        for (auto& x : D) ++C[x[0] - '0' + 1];
        for (int i = 1; i <= 10; ++i) C[i] += C[i - 1];
        vector<int> nums = digits(N);
        int S = nums.size();
        vector<int> P(S, 1); // P[i]代表数字位数为i个时，D中元素能能构成多少个数
        int res = 0;
        for (int i = 1; i < S; ++i) {
            P[i] = P[i - 1] * D.size();
            res += P[i];
        }
        bool can_equal = true;
        for (int i = S - 1; i >= 0; --i) {
            res += P[i] * C[nums[i]];
            if (C[nums[i] + 1] == C[nums[i]]) {
                can_equal = false; // 意味着D中不存在nums[i]
                break;
            }
        }
        res += can_equal;
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/300b34c4a4b78140a329723d75d8be1290b2d0200c1bf02d92343e3e84659c5b-image.png)


