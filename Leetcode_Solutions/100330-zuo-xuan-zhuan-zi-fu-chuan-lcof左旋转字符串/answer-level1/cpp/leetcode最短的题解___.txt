c++一行代码解决
```
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n)+s.substr(0,n);
    }
};
```
