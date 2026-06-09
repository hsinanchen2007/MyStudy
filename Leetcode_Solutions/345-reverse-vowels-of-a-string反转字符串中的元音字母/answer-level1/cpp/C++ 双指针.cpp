```c++
class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        string e = "aeiouAEIOU";
        unordered_set<char> v(e.begin(), e.end());
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            while (i < j && !v.count(s[i])) i++;
            while (i < j && !v.count(s[j])) j--;
            if (i < j) swap(s[i], s[j]);
        }
        return s;
    }
};
```