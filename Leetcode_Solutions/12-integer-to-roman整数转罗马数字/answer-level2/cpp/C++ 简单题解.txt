```C++ []
class Solution {
public:
    const vector<pair<int, string> > v{
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
    string intToRoman(int num) {
        string res;
        for (int i = 0; i < v.size() && num > 0; ++i) {
            int k = num / v[i].first;
            num %= v[i].first;
            for (int j = 0; j < k; ++j) {
                res += v[i].second;
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/20a6fed7a60a0de43e118369bdcdf3b338ff2072435d2c1af64482a899cc0717-image.png)
