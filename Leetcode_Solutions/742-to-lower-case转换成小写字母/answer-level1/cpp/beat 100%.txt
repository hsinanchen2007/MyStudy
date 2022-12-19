```
class Solution {
public:
    inline string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), [] (auto& ch) { return tolower(ch); });
        return str;
    }
};
```
