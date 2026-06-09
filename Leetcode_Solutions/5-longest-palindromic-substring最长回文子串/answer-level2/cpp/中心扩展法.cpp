### 解题思路
使用中心扩展法。
分为中心点是一个字符的情况和两个字符的情况，分别向两遍扩展，不断更新最左边界和最大长度即可
### 代码

```cpp
class Solution {
public:
    int index = 0;
    int max_len = 0;
    string longestPalindrome(string s) {
        int len = s.size();
        if(len <= 1)
            return s; // 边界条件判断

        for(int i = 0; i < len; i++){ 
            extend_str(s,i,i,len); // 对该字符进行扩展
            extend_str(s,i,i+1,len); // 对相邻的两个字符进行扩展
        }
        return s.substr(index,max_len);
    }

    void extend_str(string& s, int l, int r,int len){
        while(l >= 0 && (r < len) && (s[l] == s[r])){
            l--;
            r++;
        }

        if(r - l - 1 > max_len){
            max_len = r - l - 1;
            index = l+1;
        }

    }
};
```