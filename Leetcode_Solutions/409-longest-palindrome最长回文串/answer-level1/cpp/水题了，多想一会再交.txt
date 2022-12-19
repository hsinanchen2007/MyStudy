```
class Solution {
public:
    int longestPalindrome(string s) {
        // 
        vector<int>cnt(52,0);
        for(int i=0;i<s.length();i++){
            int num;
            if(s[i] >='A' && s[i] <='Z') num = s[i] - 'A' + 26;
            if(s[i] >='a' && s[i] <='z') num = s[i] - 'a';
            cnt[num] ++;
        }
        int ans = 0;int sub = 0;
        for(int i=0;i<52;i++){
            if(cnt[i] % 2 == 0) ans += cnt[i];
            else{
                ans += cnt[i]-1;
                sub = 1;
            }
        }
        ans += sub;
        return ans;
    }
};
```
