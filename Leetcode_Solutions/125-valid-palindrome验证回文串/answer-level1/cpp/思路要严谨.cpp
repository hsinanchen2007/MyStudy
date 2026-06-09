### 解题思路
判断大小写的时候要提前判断下，是否为字母

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        // 左右指针
        int j = s.size() - 1;
        int i=0;
        while(i<j)
        {
            if(!judgenumorchar(s[i])){++i; continue;}
            if(!judgenumorchar(s[j])){--j; continue;}
            if(s[i] == s[j]||(s[i]>64&&s[j]>64&&(s[i] + 32 == s[j]||s[j] + 32 == s[i]))) {++i; --j;continue;}// 大小写,均转换为小写
            return false;
        }
        return true; 
    }
    bool judgenumorchar(char c){
        if((c>47&&c<58)||(c>64&&c<91)||(c>96&&c<123)) return true;
        else return false;
    }
};
```