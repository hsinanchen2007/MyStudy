### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
    int result=0;
    bool isOne=false;
    map<char,int> M;
    map<char,int>::iterator it;
    for (int i=0; i<s.length(); i++) {
        M[s[i]]++;
    }
    for (it=M.begin(); it!=M.end(); it++) {
        if (it->second%2==0) {
            result+=it->second;
        }
        if (it->second>0&&it->second%2!=0) {
            if (!isOne) {
                result+=it->second;
                isOne=true;
            }
            else{
                result+=it->second-1;
            } 
        }
    }
    return result;
}
};
```