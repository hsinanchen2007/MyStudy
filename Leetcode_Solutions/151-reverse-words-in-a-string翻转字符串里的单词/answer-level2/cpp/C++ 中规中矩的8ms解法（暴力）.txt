```cpp
class Solution {
public:
    string reverseWords(string s) {
        istringstream words(s);
        string w, ans = "";
        while (words >> w) ans = " " + w + ans;
        return ans.empty() ? "" : string(ans.begin() + 1, ans.end());
    }
};
```