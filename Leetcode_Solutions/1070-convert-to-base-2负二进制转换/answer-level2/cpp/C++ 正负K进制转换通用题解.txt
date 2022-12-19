通过数学推导可以得到+K/-K进制的通用转化法
```
class Solution {
public:
    // 无论K是正数还是负数都支持（只支持-10～10进制，因为更高进制需要引入字母）
    vector<int> baseK(int N, int K) {
        if (N == 0) return {0};
        vector<int> res;
        while (N != 0) {
            int r = ((N % K) + abs(K)) % abs(K); // 此处为关键
            res.push_back(r);
            N -= r;
            N /= K;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string baseNeg2(int N) {
        vector<int> nums = baseK(N, -2);
        string res;
        for (auto x : nums) res += to_string(x);
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/cb6bf6cb5094bebd6c847b620a988a6ae16111e2fac466c487e28db8344e2231-image.png)
