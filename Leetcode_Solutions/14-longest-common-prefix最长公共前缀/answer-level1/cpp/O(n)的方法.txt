### 解题思路
前n个字符串的公共子串 等于 前n-1个字符串的公共子串与 第n个字符串 的公共子串

### 代码

```cpp
class Solution {
public:
     
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())    return "";
        string a = strs[0];
        for(int i=1; i<strs.size(); ++i){
            string b = strs[i];
            string c = "";
            int j = 0;
            while(j<a.size() && j<b.size() && a[j]==b[j])
                c += a[j++];
            a = c;
        }
        return a;
    }
};
```