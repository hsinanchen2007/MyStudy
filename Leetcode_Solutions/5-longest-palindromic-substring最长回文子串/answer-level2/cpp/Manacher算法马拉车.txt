```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<int> P(n*2 + 3, 0);
        manacher(s, P);
        
        return s.substr((resCenter - resLen + 1)/2, resLen - 1);
    }

private:
    void manacher(string s, vector<int>& P) {
        int len = s.size();
        string T = "$#";
        for (int i = 0; i < len; i++) {
            T.push_back(s[i]);
            T.push_back('#');
        }
        T.push_back('@');
        int r = 0, c = 0;
        for (int i = 1; i < T.size(); i++) {
            P[i] = r > i ? min(P[2 * c - i], r - i) : 1;
            while (T[i + P[i]] == T[i - P[i]]) P[i]++;
            if (i + P[i] > r)  r = i + P[i], c = i;
            if (resLen < P[i]) {
                resLen = P[i];
                resCenter = i;
            }
        }
    }
    int resLen;
    int resCenter;
};
```