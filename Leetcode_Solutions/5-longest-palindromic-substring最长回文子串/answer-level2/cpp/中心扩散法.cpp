```cpp
	string f(string &s, int l, int r, int len) {
        while(l >= 0 && r < len) {
            if(s[l] == s[r]) {
                --l;
                ++r;
            } else break;
        }
        return s.substr(l + 1, r -l - 1);//这里下标要注意，不能包含l和r
    }
    string longestPalindrome(string s) {
        int l = s.size();
        if(l < 2) return s;//特判
        int maxl = 1;
        string ans = s.substr(0, 1);
        for(int i = 0; i < l - 1; ++i) {//最右边即len-1的元素及其右边的间隙不需要遍历
            //兼顾两种情况，就不需要再分情况讨论了
            string s1 = f(s, i, i, l), s2 = f(s, i , i + 1, l);
            string s3 = s1.size() > s2.size()?s1:s2;
            if(s3.size() > maxl) {
                maxl = s3.size();
                ans = s3;
            }
        }
        return ans;
    }

```
