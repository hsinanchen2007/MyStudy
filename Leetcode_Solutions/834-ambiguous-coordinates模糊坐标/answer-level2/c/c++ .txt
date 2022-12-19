![image.png](https://pic.leetcode-cn.com/d1ad0712319dcbab48688e02a458f966757130dceb7d55f69b0c7d9842c6d89a-image.png)

``` c++
class Solution {
public:

    int toNum(string s, vector<string> &res) {
        // 前后是0
        if (s[0] == '0' && s[s.size() - 1] == '0') {
            if (s.size() == 1) {
                res.push_back("0");
                return 1;
            } else return 0;
        }
        // 只前是0
        if (s[0] == '0') {
            res.push_back(s.substr(0, 1) + '.' + s.substr(1));
        } else {
            // 前后都不是0
            if (s[s.size() - 1] != '0') {
                for (int i=1; i<s.size(); i++) {
                    res.push_back(s.substr(0, i) + '.' + s.substr(i));
                }
            }
            // 只后是0
            res.push_back(s);
        }
        return res.size();
    }

    void join(vector<string> &left, vector<string> &right, vector<string> &res) {
        for (auto l:left) {
            for (auto r:right) {
                res.push_back('(' + l + ", "+ r + ')');
            }
        }
    }

    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        S = S.substr(1, S.size() - 2);
        for (int i=1; i<S.size(); i++) {
            vector<string> left, right;
            if (toNum(S.substr(0, i), left) == 0) continue;
            if (toNum(S.substr(i), right) == 0) continue;
            join(left, right, res);
        }
        return res;
    }
};
```
