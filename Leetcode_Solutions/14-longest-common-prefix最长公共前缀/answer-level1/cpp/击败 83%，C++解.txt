### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string prefix = strs.at(0);
        vector<string>::iterator it = strs.begin();
        ++it;
        for(;it != strs.end(); ++it)
        {
            int size = prefix.size() < it->size() ? prefix.size() : it->size();
            int i=0;
            for(;i<size;++i)
            {
                if(prefix.at(i) != it->at(i))
                {
                    if(i == 0)
                        return "";
                    break;
                }
            }
            prefix = prefix.substr(0,i);
        }

        return prefix;
    }
};
```

主要利用prefix.substr(0,i)方法获取前缀子串