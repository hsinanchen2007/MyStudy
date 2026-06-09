### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int n = num.size();
        int i = 0;
        while(i < n && k > 0) {
            if (res.empty() || res.back() <= num[i]) {
                res.push_back(num[i]);
                ++i;
            } else {
                res.pop_back();
                --k;
            }
        }
        while(i < n) {
            res.push_back(num[i]);
            ++i;
        }
        if (k == 0) {
            int j = 0;
            //cout<<res<<endl;
            while(res[j] == '0') {
                ++j;
            }
            if (j == res.size()) {
                return "0";
            }
            return res.substr(j);
        }
        res.erase(res.size() - k);
        int j = 0;
        cout<<res<<endl;
        while(res[j] == '0') {
            ++j;
        }
        if (j == res.size()) {
            return "0";
        }
        return res.substr(j);
    }
};
```