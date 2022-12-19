### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())return s;
        int len = 0;
        string ans = "";
        for(int m = s.size()-1; m >= 0; m--)
        {
            if(s[m] == ' ' && len != 0)
            {
                ans += s.substr(m+1,len) + " "; len = 0; continue; ////substr函数:插入m+1位置长度为len的stringstring
            }
            if(s[m] != ' ') len++;
        }
        if(len != 0) ans += s.substr(0, len) + " ";
        if(ans.size() > 0) ans.erase(ans.size() - 1, 1);//erase函数 擦除 一段string
        return ans;

    }
};

```