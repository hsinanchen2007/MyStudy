大体思路： 
因为X为 str1 和 str2的最大公因子。

=>   X的长度为str1(或者str2)长度的因子。(可以利用长度信息对isSubstring函数进行计算优化)

我们定义了一个函数isSubstring(string &str2, string &str1);
能够判断str2 是不是str1的子串。

我们遍历所有str1(或者str2)的因子（for 循环）, 找到X，同时满足是str1 和str2的因子即可。

```
class Solution {
public:
    bool isSubstring(string &str2, string &str1) {
        if (str1.size() % str2.size() != 0)
            return false;

        int end = 0;
        while (end != str1.size() ){
            if (str1.substr(end, str2.size()) != str2)
                return false;
            end += str2.size();
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        for (int i = 1; i <= str2.size(); i++) {
            if (str2.size() % i == 0) {
                string tmp_str = str2.substr(0, str2.size()/i);
                // cout << tmp_str << endl;
                if (isSubstring(tmp_str, str2) && isSubstring(tmp_str, str1))
                    return tmp_str;
            }
        }
        return "";
    }
};
```
