```C++
class Solution {
public:
    string reverseWords(string s) {
        regex re("[^ ]+");
        vector<string> v(sregex_token_iterator(s.begin(), s.end(), re, 0), sregex_token_iterator());
        return accumulate(v.rbegin(), v.rend(), string(), [](auto& a, auto& b) {
            return a.empty() ? b : a + " " + b;
        });
    }
};
```