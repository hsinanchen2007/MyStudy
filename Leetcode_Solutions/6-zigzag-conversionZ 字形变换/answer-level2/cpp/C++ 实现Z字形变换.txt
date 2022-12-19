### 解题思路
参考一个大佬的思路，实现的C++版本。
定义一个numRows行的vector，将string中的字符按行写到vector。设置一个flag，到第一行或者最后一行时，改变flag，从而改变写入vector的顺序。

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2) {
            return s;
        }
        vector<string> res(numRows, "");
        int i = 0, flag = -1;
        for (int j = 0; j < s.size(); ++j) {
            if (i == 0 || i == numRows - 1) {
                flag = -flag;
            }
            res[i] += s[j];
            i += flag;
        }
        
        string ret_res = "";
        for (int i = 0; i < res.size(); ++i) {
            ret_res += res[i];
        }
        return ret_res;
    }
};
```