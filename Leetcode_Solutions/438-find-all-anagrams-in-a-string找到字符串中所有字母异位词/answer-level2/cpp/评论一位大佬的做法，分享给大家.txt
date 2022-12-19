### 解题思路
真的强，我感觉比很多题解清晰不少。

### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length() > s.length())
            return ans;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for(auto ch : p)
            v1[ch - 'a']++;
        int l = 0, r = 0;
        while(r < s.length())
        {
            v2[s[r] - 'a']++;
            r++;
            if(r < p.length())
                continue;
            if(v1 == v2)
                ans.push_back(l);
            v2[s[l] - 'a']--;
            l++;
        }
        return ans;
    }
};
```