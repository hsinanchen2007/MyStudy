思路是计算每个10^i对应的答案，然后输入的数字，根据每个位上的数字，将结果逐一合并起来
```
class Solution {
public:
    vector<long long> tens{1};
    vector<long long> pows{1};
    Solution() {
        for (int i = 1; i <= 18; ++i) {
            pows.push_back(10 * pows.back());
            tens.push_back(pows[i - 1] * i + 1);
        }
    }
    int countDigitOne(int n) {
        int res = 0;
        int curr = 0;
        for (int i = 0; n >= pows[i]; ++i) {
            curr = (n / pows[i]) % 10;
            if (curr > 1) {
                res += curr * (tens[i] - 1) + pows[i];
            } else if (curr == 1) {
                res += tens[i] + n - (n / pows[i] * pows[i]);
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/65f9f84695266936db4566cc0d31138feab6db4e2c2a765546e8dc2416c40682-image.png)
