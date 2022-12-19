```
class Solution {
public:
    string maskPII(string S)
    {
        string result = maskEmail(S);
        if (result.empty()) {
            return maskPhoneNum(S);
        }
        return result;
    }

private:
    string maskPhoneNum(const string &S)
    {
        string result;
        string number;
        for (int i = 0; i < S.size(); ++i) {
            if (S.at(i) >= '0' && S.at(i) <= '9') {
                number.push_back(S.at(i));
            }
        }
        const int minPhoneNum = 10;
        const int maxPhoneNum = 13;
        if (number.size() < minPhoneNum || number.size() > maxPhoneNum) {
            return "";
        }

        int starCount = number.size() - minPhoneNum;
        const int showPhoneNumCount = 4;
        number = number.substr(number.size() - showPhoneNumCount);
        if (starCount > 0) {
            result += "+";
            for (int i = 0; i < starCount; ++i) {
                result += "*";
            }
            result += "-";
        }
        result += "***-***-";
        result += number;
        return result;
    }

private:
    string maskEmail(const string &S)
    {
        string result;
        size_t pos = S.find('@');
        if (pos == string::npos) {
            return "";
        }
        string name = S.substr(0, pos);
        if (name.size() < 2) {
            return "";
        }

        result.push_back(name.front());
        result += "*****";
        result.push_back(name.back());
        result += S.substr(pos);
        for (size_t i = 0; i < result.size(); ++i) {
            if (result.at(i) >= 'A' && result.at(i) <= 'Z') {
                result[i] -= ('A' - 'a');
            }
        }
        return result;
    }
};

```
