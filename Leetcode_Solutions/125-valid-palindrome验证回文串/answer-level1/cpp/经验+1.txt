### 解题思路
本题的关键是处理非字母非数字的其他字符，看张同学的题解可知，关于字符串的操作有

islower(char c) 是否为小写字母
isuppper(char c) 是否为大写字母
isdigit(char c) 是否为数字
isalpha(char c) 是否为字母
isalnum(char c) 是否为字母或者数字
toupper(char c) 字母小转大
tolower(char c) 字母大转小

知道这些就好操作了，还有要注意大小写字母不区分

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0) return true;
        string str;
        for(int i=0;i<s.size();i++){
            if(islower(s[i])||isdigit(s[i])) str+=s[i];
            else if(isupper(s[i])) str+=(s[i]+32);
        }
        int m=0,n=str.size()-1;
        while(m<n){
            if(str[m]!=str[n]) return false;
            m++;
            n--;
        }
        return true;

    }
};
```