### 解题思路


### 代码

```cpp
class Solution {
public:
    void core(vector<string>& re, string& ans, int stage, string & s, int pos) {
        if (stage==5) {
            if (pos==s.size()) {
                ans.erase(ans.size()-1);
                re.push_back(ans);
                return;
            }
            else {
                return;
            }
        }
        if (pos==s.size()) {
            return;
        }
        int k=pos+1;
        while (k <= s.size()) {
            string _a = s.substr(pos, k-pos);
            if (_a.size()>1 && _a[0]=='0') return;
            int a = stoi(_a);
            if (a>255) return;
            _a += '.';
            int b = ans.size();
            ans += _a;
            core(re, ans, stage+1, s, k);
            ans.erase(b);
            k++;
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> re;
        if (s.empty()) return re;
        string ans;
        core(re, ans, 1, s, 0);
        return re;
    }
};
```