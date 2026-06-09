
中心拓展思想
--------------



```cpp
class Solution {
public:
    int cnt=0;
    //回文字符串：奇数个数和偶数个数两种
    //所以有两种中心扩展方式，以当前字符为中心、以当前字符和下一个字符为中心向两边拓展
    int countSubstrings(string s) {
        for(int i=0;s[i]!='\0';++i){
            expandSubString(s,i,i);
            expandSubString(s,i,i+1);
        }
        return cnt;
    }
    //中心扩散，回文字符串对称特点，两端相等
    void expandSubString(string s,int start,int end){
        while(start>=0 && end<s.length() && s[start]==s[end]){
            start--;
            end++;
            cnt++;  
        }
    }
};
```