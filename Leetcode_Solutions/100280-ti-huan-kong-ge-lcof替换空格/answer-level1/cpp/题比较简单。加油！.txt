### 解题思路
循环进行替换。

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {

        string res = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                res += "%20";
            }else
                res += s[i];

        }
        return res;
    }
};
```