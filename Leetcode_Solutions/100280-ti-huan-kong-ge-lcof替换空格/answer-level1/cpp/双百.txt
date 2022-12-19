### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ')ans+="%20";
            else ans+=s[i];
        }
        return ans;
    }
};
```