
```
class Solution {
public:
    int ToInt(string str)
    {
        int res;
        stringstream ss;
        ss << str;
        ss >> res;
        return res;
    }

    bool IsValid(string &str)
    {
        if ((str.length() > 1 && str[0] == '0') || ToInt(str) > 255) {
            return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s)
    {
        int len = s.length();
        vector<string> result;
        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j < 4; ++j) {
                for (int k = 1; k < 4; ++k) {
                    if (len - i - j - k > 3 || len - i - j - k <= 0) {
                        continue;
                    }
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, j);
                    string s3 = s.substr(i + j, k);
                    string s4 = s.substr(i + j + k);
                    if (IsValid(s1) && IsValid(s2) && IsValid(s3) && IsValid(s4)) {
                        string tmp = s1 + '.' + s2 + '.' + s3 + '.' + s4;
                        result.push_back(tmp);
                    }
                }
            }
        }
        return result;
    }
};

```
