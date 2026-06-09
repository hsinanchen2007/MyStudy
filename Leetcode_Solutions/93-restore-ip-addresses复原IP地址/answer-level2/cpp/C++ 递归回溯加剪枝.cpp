```
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> vec;
        if (s.empty() || s.length() < 4)
            return vec;
        helper(s,vec, 0);
        return vec;
    }

    void helper(string str, vector<string>& res, int level) {
        if (level == 4 && !str.empty())
            return;
        if (str.empty() && level == 4)
            res.push_back(_res.substr(0, _res.length() - 1));
        else
            for (int i = 1; i <= 3; ++i) {
                int len = _res.length();
                string check = str.substr(0,i);
                _res += check;
                _res += ".";
                //剩余部分还需的最大的字符串的长度
                int maxNeedLength = (3 - level) * 3;
                //剩余部分至少还需的字符串的长度
                int minNeedLength = 3 - level;
                int resStringLength = str.length() - i;
                if(maxNeedLength >= resStringLength && resStringLength >= minNeedLength && !(check.length() > 1 && check[0] == '0') &&stoi(check) <= 255)
                    helper(str.substr(i,str.length()), res, 1 + level);
                _res = _res.substr(0, len);
            }
    }

private:
    string _res = "";
};
```

每次向下递归后，判断之后最多需要多长的字符串以及最少需要多长的字符串，判断当前截取剩余的字符串长度能否满足要求，如果能则向下递归，否则continue.
