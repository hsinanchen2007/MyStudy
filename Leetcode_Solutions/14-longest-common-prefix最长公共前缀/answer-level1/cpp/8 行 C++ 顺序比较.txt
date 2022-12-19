```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r = strs.size() ? strs[0] : "";
        for(auto s: strs){
            while(s.substr(0, r.size()) != r){
                r = r.substr(0, r.size() - 1);
                if(r == "") return r;
            }
        }
        return r;
    }
};
```
- 同官方题解1，按顺序比较下来
- 3个字符串的最长公共前缀一定被包含在前2个字符串的最长公共前缀之中，同理，N个字符串的前缀一定是其中（N-1）个字符串的最长公共前缀与第N个字符串的最长公共前缀