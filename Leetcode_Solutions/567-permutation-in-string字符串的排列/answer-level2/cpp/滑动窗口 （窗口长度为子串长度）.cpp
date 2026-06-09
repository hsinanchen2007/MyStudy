

### 代码

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int l = 0;
        vector<int> s(26,0),w(26,0);
        for(int i = 0; i < s1.size(); i++)
            s[s1[i] - 'a']++;
        for(int i = 0; i < s2.size(); i++)
        {
            w[s2[i] - 'a']++;
            while(i - l + 1 > s1.size())
            {
                w[s2[l] - 'a']--;
                l++;
            }
            if(s == w) return true;
        }
         return false;
    }
};
```