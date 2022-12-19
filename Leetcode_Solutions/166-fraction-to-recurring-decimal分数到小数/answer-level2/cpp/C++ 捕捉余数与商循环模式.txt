# 解法一
```C++ []
class Solution {
public:
    vector<int> decimals(long num, long den, int& loop_ind) {
        loop_ind = -1;
        num = abs(num);
        den = abs(den);
        num %= den;
        if (num == 0) {
            return {};
        }
        vector<int> res;
        map<pair<vector<int>, int>, int> m;
        while (num) {
            num *= 10;
            vector<int> v;
            while (num < den) {
                v.push_back(0);
                num *= 10;
            }
            v.push_back(num / den);
            int r = num % den;
            pair<vector<int>, int> p = {v, r};
            if (m.count(p)) {
                loop_ind = m[p];
                break;
            } else {
                m[p] = res.size();
                for (auto x : v) {
                    res.push_back(x);
                }
            }
            num = r;
        }
        return res;
    }
    string fractionToDecimal(int numerator, int denominator) {
        long num = numerator;
        long den = denominator;
        string res;
        if (num * den < 0) {
            res += "-";
        }
        num = abs(num);
        den = abs(den);
        res += to_string(num / den);
        int loop_ind = -1;
        auto nums = decimals(num, den, loop_ind);
        if (nums.empty()) {
            return res;
        } else {
            res += ".";
        }
        if (loop_ind == -1) {
            for (auto x : nums) {
                res += to_string(x);
            }
            return res;
        }
        for (int i = 0; i < loop_ind; ++i) {
            res += to_string(nums[i]);
        }
        string loop_part;
        for (int i = loop_ind; i < nums.size(); ++i) {
            loop_part += to_string(nums[i]);
        }
        res += "(" + loop_part + ")";
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/ae7229cf2de8984ce398832e8dd46aa4fb6cc15487897f265fdfcf3eea9e734b-image.png)


# 解法二：
如下题解参考官方解答，更加简洁高效
```C++ []
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long num = long(numerator);
        long den = long(denominator);
        string res;
        if (num * den < 0) {
            res += "-";
        }
        num = abs(num);
        den = abs(den);
        res += to_string(num / den);
        num %= den;
        if (num == 0) {
            return res;
        }
        
        res += ".";
        int loop_ind = -1;
        unordered_map<long, long> m;
        while (num != 0) {
            if (m.count(num)) {
                loop_ind = m[num];
                break;
            } else {
                m[num] = res.size();
            }
            num *= 10;
            res += to_string(num / den);
            num %= den;
        }
        if (num == 0) {
            return res;
        }
        return res.substr(0, loop_ind) + "(" + res.substr(loop_ind) + ")";
    }
};
```
![image.png](https://pic.leetcode-cn.com/f7824ffe93febee823429e9a853041bd3a2ca07dd899f4646a6cf9f38411d306-image.png)

