### 解题思路
模仿辗转相除法写一下递归还真过了。

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1==str2)return str1;
        if(str1==""||str2=="")return "";
        if(str1.size()<str2.size())swap(str1,str2);
        string s=str1.substr(0,str2.size());
        if(s!=str2)return "";
        return gcdOfStrings(str1.substr(str2.size(),str1.size()-str2.size()),str2);
    }
};
```