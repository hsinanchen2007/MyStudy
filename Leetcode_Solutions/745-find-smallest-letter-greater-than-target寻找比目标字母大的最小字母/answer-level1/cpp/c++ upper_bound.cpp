```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        auto res = upper_bound(letters.begin(), letters.end(), target);
        return res == letters.end() ? *letters.begin() : *res;
    }
};
```
