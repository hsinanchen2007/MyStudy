```c++
class Solution {
public:
    string replaceSpace(string s) {
        return regex_replace(s, regex(" "), "%20");
    }
};
```