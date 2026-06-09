```

class ToLower {
public:
    void operator()(char &ch)
    {
        ch = tolower(ch);
    }
};

class Solution {
public:
    string maskPII(string S) {
        for_each(S.begin(), S.end(), ToLower());
        regex maixRule(R"(([a-z])[a-z]*([a-z])(@\w+\.\w+))");

        string rst;
        smatch m;
        bool fund = regex_match(S, m, maixRule);
        if (fund) {
            if (S.size() < 8) {
                return rst;
            }
            rst += m[1].str();
            rst += "*****";
            rst += m[2].str();
            rst += m[3].str();
            return rst;
        }

        // 下面处理Phone
        string phone;
        for (const auto &ch : S) {
            if (isdigit(ch)) {
                phone.push_back(ch);
            }
        }

        if (phone.size() < 10 || phone.size() > 13) {
            return rst;
        }
        if (phone.size() == 10) {
            rst += "***-***-";
        } else {
            string tmp(phone.size() - 10, '*');
            rst = "+" + tmp + "-***-***-";
        }
        rst += phone.substr(phone.length() - 4);
        return rst;
    }
};
```