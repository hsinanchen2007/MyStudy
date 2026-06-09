### 解题思路
本题看来题解才会做，而且目前也只采用了官方题解的水平扫描法，思路也很简单：初始化最长公共前缀为第一个字符串，用已有的最长公共前缀与下一个字符串元素匹配，更新最长公共前缀。注意特殊情况即可，strs.size() == 0的时候无任何字符串，返回""。

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string prefix = strs[0]; //初始化前缀
        for(int i = 1; i < strs.size(); i++) {
            int j;
            for(j = 0; j < prefix.length() && j < strs[i].length(); j++) {
                if(prefix[j] != strs[i][j]) break;
            }
            prefix = prefix.substr(0, j);
            if(prefix == "")
                break;
        }
        return prefix;
    }
}; 
```