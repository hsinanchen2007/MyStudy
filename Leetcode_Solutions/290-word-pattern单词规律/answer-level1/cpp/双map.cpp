### 解题思路
因为题目要求双向匹配，所以要设置两个map。

### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        istringstream ss(str);
        vector<string> v;
        string temp = "";
        while(ss >> temp)
            v.push_back(temp);
        if(v.size() != pattern.length())
            return false;
        for(int i = 0 ; i < pattern.length() ; ++i)
        {
            if(!mp1.count(pattern[i]) && !mp2.count(v[i]))
            {
                mp1[pattern[i]] = v[i];
                mp2[v[i]] = pattern[i];
            }
            else if(mp1[pattern[i]] != v[i] || mp2[v[i]] != pattern[i])
                return false;
        }
        return true;
    }
};
```