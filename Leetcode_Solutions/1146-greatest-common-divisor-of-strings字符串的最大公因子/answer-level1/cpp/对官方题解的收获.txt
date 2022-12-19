### 解题思路
首先是优化选择比较的范围：
最大的公因子的长度只能是两者中间长度较小的那个长度。
公因子可能有多个，先从最长的位置开始遍历，这样得到的第一个结果就是答案。

另外，考虑到比较确认公因子的代码有重复
因此可以将检查字符串是一个公因子的代码封装成一个函数。

以上两点要多体会。
### 代码

```cpp
class Solution {
    bool check(string test,string tar) {
        int len = (int)tar.length() / (int)test.length();
        string ans = "";
        for(int i = 1; i <= len; ++i) {
            ans += test;
        }
        return ans == tar;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int tra;
        int len1 = str1.length(), len2 = str2.length();
        string temp;

        for(tra = min(len1, len2); tra >= 1; --tra) {
            if(len1 % tra == 0 && len2 % tra == 0) {
                temp = str1.substr(0, tra);
                if(check(temp, str1) && check(temp, str2)) {
                    return temp;
                }
            }
        }
        return "";
    }
};
```