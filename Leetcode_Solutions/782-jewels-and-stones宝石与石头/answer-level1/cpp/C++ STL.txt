```c++
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s(J.begin(), J.end());
        int r = 0;
        for (auto c : S) {
            if (s.count(c)) r++;
        }
        return r;
    }
};
```