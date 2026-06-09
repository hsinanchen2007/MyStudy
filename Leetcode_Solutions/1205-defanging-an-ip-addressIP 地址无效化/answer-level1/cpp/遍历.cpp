### 解题思路


### 代码

```cpp
class Solution {
public:
    string defangIPaddr(string str) {
        string res = "";
        for(int i = 0;i < str.size();i++)
            if(str[i] != '.') res += str[i];
            else res += "[.]";
        return res;
    }
};
```