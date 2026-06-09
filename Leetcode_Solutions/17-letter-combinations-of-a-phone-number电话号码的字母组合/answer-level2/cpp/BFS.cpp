### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

    void fun(map<char, string> &keyValue, string digits, int pos,       vector<string>& output) {
        vector<string> outputChild;
        string str;

        if (pos < 0 || pos >= digits.length()) {
            return;
        }

        string strChild = keyValue[digits[pos]];
        for (int i = 0; i< strChild.length(); i++) {
            if (output.size() <= 0) {
                string str;
                str += strChild[i];
                outputChild.push_back(str);
                str.clear();
            } else {
                for (int j = 0; j < output.size(); j++) {
                    string str = output[j];
                    str += strChild[i];
                    outputChild.push_back(str);
                }
            }
        }
        output = outputChild;
    }
    vector<string> letterCombinations(string digits) {
        map<char, string> keyValue;
        keyValue['2'] = "abc";
        keyValue['3'] = "def";
        keyValue['4'] = "ghi";
        keyValue['5'] = "jkl";
        keyValue['6'] = "mno";
        keyValue['7'] = "pqrs";
        keyValue['8'] = "tuv";
        keyValue['9'] = "wxyz";
        vector<string> output;
        for (int i = 0; i < digits.length(); i++) {
            fun(keyValue, digits, i, output);
        }
        return output;
    }
};
```