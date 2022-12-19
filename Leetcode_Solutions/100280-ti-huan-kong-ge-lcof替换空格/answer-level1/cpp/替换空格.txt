### 解题思路
很神奇的一道题，变量名换为res时可以变为双百，执行时间0ms

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == ' ') {
                ans +="%20";
            }
            else ans+=s[i];
        }
        return ans; 
    }
};
```