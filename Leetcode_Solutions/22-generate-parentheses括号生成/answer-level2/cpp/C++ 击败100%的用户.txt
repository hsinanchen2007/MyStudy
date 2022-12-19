```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int l = n-1;
        int r =n-1;
        vector<string> retStrs;
        char *s = new char[2*n+1];
        s[0] = '(';
        s[2*n - 1] = ')';
        s[2*n] = 0;

        func(l, r, s, 1, 2*n-1, retStrs);
        return retStrs;
    }

    bool isStrOk(char *s, int n) {
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') num++;
            else {
                if (--num < 0) return false;
            }
        }

        return true;
    }
    void func(int l, int r, char *s, int index, int n, vector<string>& retStrs) {
        if (!isStrOk(s, index)) return; 
        if (index == n) {
            if (l != 0) s[index] = '(';
            else s[index] = ')';

            if (isStrOk(s, n+1)) retStrs.push_back(s);
            return;
        }
        
        for (int i = 2; i > 0 && r + l > 0; i--) {
            if (i == 1 && r > 0) {
                s[index] = ')';
                func(l, r-1, s, index+1, n, retStrs);
            }
            if (i == 2 && l > 0) {
                s[index] = '(';
                func(l-1, r, s, index+1, n, retStrs);
            }
        }
    }
};
```
![捕获.PNG](https://pic.leetcode-cn.com/bbe021135f285f5ebf786ed109b58081a36300715104233b32a05dde068c2160-%E6%8D%95%E8%8E%B7.PNG)

