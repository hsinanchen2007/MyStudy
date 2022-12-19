```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        char table[128] = {0};
        for(auto i: J) table[i] = 1;
        int n = 0;
        for(auto i: S) n += table[i];
        return n;
    }
};
```
