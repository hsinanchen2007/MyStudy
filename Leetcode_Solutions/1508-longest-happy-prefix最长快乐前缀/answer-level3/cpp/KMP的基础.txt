### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestPrefix(string s) {
        s += "#";
        vector<int> next(s.length(), 0);

        int k = -1; 
        int j = 0;
        next[0] = -1;

        while( j < s.length()-1 )
        {
            if( k == -1 || s[j] == s[k])
                next[++j] = ++k;
            else
                k = next[k];
        }
        //next[0] = 0;
        string ans = "";
        if(s.length() > 1) ans = s.substr(0, next[s.length()-1]);
        return ans;
    }
};
```