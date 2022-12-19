最长回文子串只有两种情况。
一种是子串为奇数，另一种为偶数。
奇数情况：只需从中间一位往左右遍历即可
偶数情况：只需从中间两位往左右遍历即可




```
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0; i < s.size(); i++){
            for(int j = i , k = i; j >= 0 && k < s.size() && s[j] == s[k]; j-- ,k++){
                if(res.size() < k - j + 1){
                    res = s.substr(j, k - j + 1);
                }
            }
            for(int j = i , k = i + 1; j >= 0 && k < s.size() && s[j] == s[k]; j-- ,k++){
                if(res.size() < k - j + 1){
                    res = s.substr(j, k - j + 1);
                }
            }
        }
        return res;
    }
};
```
