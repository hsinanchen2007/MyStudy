### 解题思路
剪枝的核心分为两点：
1、单段长度：IP每一段的长度在1-3个字符之间，除此之外还可以继续约束，最小长度为 剩余字符串长度 - 剩余段数 * 3，如“12312312312”，现在进行到“12.”，那么第二段的最短长度为 11 - 2 - 2 * 3 = 3，所以第二段压根不需要尝试长度1和2，也即是“12.1”和“12.12”，因为这两种情况就算之后的每一段都是最长也无法用完原始字符串。
2、数值有效：每一段的数值要小于255，且如果第一位是0，那么这一段的长度只能为1.

### 代码

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string curstr;
        vector<string> res;
        recursive(s, curstr, res, 0, 1);
        return res;
    }

    void recursive(string& s, string& curstr, vector<string>& res, int start, int level)
    {
        if (level == 5)
        {
            res.push_back(curstr.substr(0, curstr.size() - 1));
            return;
        }

        int minlen = s.size() - start - (4 - level) * 3;
        minlen = minlen < 1 ? 1 : minlen;
        int maxlen = s.size() - start;
        maxlen = maxlen > 3 ? 3 : maxlen;

        int num = 0;
        for (int i = minlen; i <= maxlen; ++i)
        {
            string str = s.substr(start, i);
            if (stoi(str) > 255) break; 
            if (str[0] == '0' && str.size() > 1) break;
            curstr += str + ".";
            recursive(s, curstr, res, start + i, level + 1);
            curstr = curstr.substr(0, curstr.size() - str.size() - 1);
        }
    }
};
```