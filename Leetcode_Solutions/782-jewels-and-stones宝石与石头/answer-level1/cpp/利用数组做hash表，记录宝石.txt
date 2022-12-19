```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int mp[128];
        memset(&mp, 0, sizeof(mp));
        for(auto j:J)
        {
            mp[j] = 1;
        }
        int count = 0;
        for(auto s:S)
        {
            count += mp[s];
        }
        return count;
    }
};
```
