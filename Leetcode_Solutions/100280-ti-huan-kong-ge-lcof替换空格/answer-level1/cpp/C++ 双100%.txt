

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(int i = 0;i<s.size();++i)
        {
            if(isspace(s[i]))
                res.append("%20");
            else
                res.push_back(s[i]);
        }    
        return res;
    }
};
```