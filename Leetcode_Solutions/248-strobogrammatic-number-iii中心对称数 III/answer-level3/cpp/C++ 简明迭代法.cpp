思路：对于长度为N的对称数，只需要将对称符号加到N-2的结果两端就可以了
注意：自对称数直接加即可，对称对数需要对应着加
详细代码如下：
```C++ []
class Solution {
public:
    vector<char> A = {'0', '1', '8'};
    unordered_map<char, char> B = {{'6', '9'}, {'9', '6'}};
    int num_less(string n1, string n2) {
        if (n1.size() != n2.size()) return n1.size() < n2.size();
        return n1 <= n2;
    }
    int strobogrammaticInRange(string low, string high) {
        int len1 = low.size();
        int len2 = high.size();
        int res = 0;
        vector<string> dp1 = {""};
        vector<string> dp2 = {"0", "1", "8"};
        for(auto& s : dp2) res += (num_less(s, high) && num_less(low, s));
        for (int i = 2; i <= len2; ++i) {
            vector<string> dp;
            for (auto& s : dp1) {
                for (auto& c : A) dp.push_back(c + s + c);
                for (auto& p : B) dp.push_back(p.first + s + p.second);
            }
            dp1 = dp2;
            dp2 = dp;
            if (i >= len1) for(auto& s : dp) res += num_less(s, high) && num_less(low, s) && s[0] != '0';
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/a77cb94fa2acb84c217291e63bd660fa6d947254788a0459be86d31dae9171df-image.png)


