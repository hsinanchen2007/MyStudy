### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        // 0ms 7.8MB 两个都超越100%
        string res;
        for(auto c : s)
        {
            if(c == ' ')
            {
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
                continue;
            }
            res.push_back(c);
            
        }
        return res;
        // 4ms, 7.7MB
        // int size = s.size();
        // if(size == 0)
        //     return string("");
        // string res("");
        // for(int i = 0; i < size; ++i)
        // {
        //     if(s[i] == ' ')
        //     {
        //         res += "%20";
        //         continue;
        //     }   
        //     res += s[i];
        // }
        // return res;
    }
};
```