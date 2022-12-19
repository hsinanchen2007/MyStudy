```
class Solution {
public:
    string longestPalindrome(const string& s) {
        int len = s.size();
        if (len <= 1) return s;
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < len-1; i++) {
            for (int j = i; j < len; j++) {
                if (j-i+1 > maxLen && isValid(s, i, j)) {
                    maxLen = j-i+1;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);
    }

private:
    bool isValid(const string& s,  int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) 
                return false;
        }
        return true;
    }
};
```
