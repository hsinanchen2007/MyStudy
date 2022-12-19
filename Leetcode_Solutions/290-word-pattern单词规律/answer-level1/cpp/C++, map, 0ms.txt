### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream s(str);
        vector<string> ans;
        string tmp;
        while(s >> tmp)
        {
            ans.push_back(tmp);
        }
        if (ans.size() != pattern.size())
        {
            return false;
        }
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        
        for(int i = 0; i < pattern.size(); i ++)
        {
            
             if (m1[pattern[i]] != m2[ans[i]])
            {
                return false;
            }
            
            m1[pattern[i]] = i + 1;
            m2[ans[i]] = i + 1;
           
        }
        return true;
    }
};
```