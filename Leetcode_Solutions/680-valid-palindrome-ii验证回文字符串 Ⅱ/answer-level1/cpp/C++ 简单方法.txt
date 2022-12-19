```
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i++] != s[j--])
                return check(s,i,j+1) || check(s,i-1,j);
        }
        return true;
    }
    bool check(string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};
```
