### 解题思路
1.为空，为1时，直接返回结果，节省计算时间。
2.有多个时，取第1个字符串，从后面开始截取比较。
3.用标记位记录，如果已经找到最长的串，直接返回。
4.程序最后返回空字符串。

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 为空
        if (strs.size() == 0) {
            return "";
        }
        // 为1直接返回
        if (strs.size() == 1) {
            return strs[0];
        }
        string pre_string;
        int i=0,j=0,found_flag=0;
        for (i=strs[0].length();i > 0;i--) {
            // 截取字符串前缀
            pre_string = strs[0].substr(0, i);
            for (j=0;j<strs.size();j++) {
                if (strs[j].find(pre_string) != 0) {
                    break;
                }
                if (j == strs.size()-1) {
                    found_flag = 1;
                }
            }
            if (found_flag == 1) {
                return pre_string;
            }
        }
        return "";
    }
};
```