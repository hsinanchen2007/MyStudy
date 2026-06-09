```
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int size = s.size();
        n %= size;
        return s.substr(n) + s.substr(0, n);
    }
};
```