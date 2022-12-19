```
class Solution {
public:
    string reverseWords(string s) {
        s = s + ' ';
        auto begin = s.begin(), end = s.begin();
        while(end != s.end()) {
            if(*end == ' ') {
                reverse(begin, end);
                begin = end+1;
            }
            ++end;
        }
        s.erase(end-1);
        return s;
    }
};
```
