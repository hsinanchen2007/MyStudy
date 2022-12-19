### 解题思路


### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        vector<int> preIndexOfS(256);
        vector<int> preIndexOfT(256);
        for (int i = 0; i < s.size(); i++)
        {
            char sc = s[i];
            char tc = t[i];
            if (preIndexOfS[sc] != preIndexOfT[tc])
                return false;
            preIndexOfS[sc] = i + 1;
            preIndexOfT[tc] = i + 1;
        }
        return true;

    }
};
```