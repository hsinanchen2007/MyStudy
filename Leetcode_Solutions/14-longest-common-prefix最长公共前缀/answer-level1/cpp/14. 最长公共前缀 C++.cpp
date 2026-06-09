
```cpp

class Solution {
public:

    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty())
            return "";

        //取第一个字符串为基准，逐一比较字符是否相等，只要其他字符串结束 或 有不相等的 就返回
        for (int i = 0; i < strs.at(0).size(); ++i)
        {
            char tmp = strs.at(0).at(i);
            for (int j = 1; j < strs.size(); ++j)
            {
                if (i == strs.at(j).size() || strs.at(j).at(i) != tmp)
                    return string(strs.at(0).c_str(), i);
            }
        }

        return strs.at(0);
    }
};