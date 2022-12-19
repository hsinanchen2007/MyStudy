```c
class Solution {
public:
    int longestPalindrome(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> hash;
        int cnt = 0;
        bool flag = false;

        for (auto str : s) hash[str] ++ ;
        for (auto str : hash) {
            if (str.second % 2 != 0) cnt += str.second - 1, flag = true;
            else cnt += str.second;
        }
        if (cnt % 2 == 0 && flag) cnt += 1;
        return cnt;
    }
};
```