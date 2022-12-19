### 解题思路
此处撰写解题思路
先考虑传入数组中有一个有效字符串，直接返回。
之后利用辅助函数逐次让相等字符个数返回。
每次遍历取最小值
### 代码

```cpp
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 1)
            return strs[0];
        string str;
        int temp = 0;
        int i = 0;
        int minnumber = INT_MAX;
        while (i + 1 < strs.size())
        {
            temp = StrStr(strs[i], strs[i + 1]);
            minnumber = temp < minnumber ? temp : minnumber;
            ++i;
        }
        for (int i = 0; minnumber != INT_MAX && i < minnumber; ++i)
            str += strs[0][i];
        return str;
    }

    int StrStr(string s1, string s2)
    {
        int i = 0;
        while (i < s1.length() && i < s2.length() && s1[i] == s2[i])
            ++i;
        return i;
    }

};
```
