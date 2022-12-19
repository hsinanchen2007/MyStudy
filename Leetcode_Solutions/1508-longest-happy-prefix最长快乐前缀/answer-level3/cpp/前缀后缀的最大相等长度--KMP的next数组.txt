### 解题思路
KMP算法中最重要的一个环节是求next数组。而next其实代表当前字符之前的字符串中，有多大长度的相同前缀后缀。我们只有能够拿到字符串s的next数组，就能够轻易得到该题的答案了

### 代码

```cpp
class Solution {
public:
    string longestPrefix(string s) {
        if(s.length()<=1) return "";
        int n = s.length();
        int next[n+1];
        next[0] = -1;
        int k = -1;
        int j = 0;
        while(j <= n-1){
            if(k == -1 || s[k] == s[j]){
                ++j;
                ++k;
                next[j] = k;
            }else{
                k = next[k];
            }
        } 
        return s.substr(0,next[n]);      
    }
};
```