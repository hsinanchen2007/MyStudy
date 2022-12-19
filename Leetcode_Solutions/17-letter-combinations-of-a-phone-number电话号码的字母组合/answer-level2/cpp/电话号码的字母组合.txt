### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            vector<string> res;
            //res.push_back("");
            return res;
        }
        vector<string> m_Vec(10, "");
        m_Vec[2] = "abc";
        m_Vec[3] = "def";
        m_Vec[4] = "ghi";
        m_Vec[5] = "jkl";
        m_Vec[6] = "mno";
        m_Vec[7] = "pqrs";
        m_Vec[8] = "tuv";
        m_Vec[9] = "wxyz";
        vector<string> res;
        return GetCombinations(digits, m_Vec, digits.size());
    }

    vector<string> GetCombinations(string digits, vector<string>& vec, int size) {
        if (digits == "") {
            vector<string> res;
            res.push_back("");
            return res;
        }
        string tmp = vec[digits[0] - '0'];
        //cout<<digits<<" "<<tmp<<endl;
        vector<string> res = GetCombinations(digits.substr(1), vec, size);
        vector<string> result;
        for( int i = 0; i < tmp.size(); ++i) {
            for(int j = 0; j < res.size(); ++j) {
                string item = res[j];
                item.insert(0, 1, tmp[i]);
                result.push_back(item);
            }
        }
        return result;
    }
};
```