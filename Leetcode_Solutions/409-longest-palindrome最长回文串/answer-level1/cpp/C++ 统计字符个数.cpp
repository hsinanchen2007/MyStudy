题目只说了求长度，不要求给出具体的串，其实只需要判断每个字符的个数就可以。
对于字符串s中的每个字符c：
    如果出现个数是偶数个，那么一定可以全部用上，直接加上c的个数
    如果是奇数个，那么至多可以用个数减1
但是，对于回文串的中心是可以有一个单独的字符的，所以如果有奇数字符的出现，最终结果还要加1.
```
class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        if(n<=1) return n;
        vector<int>mp(256,0);
        for(char c:s)  mp[c]++;
        int ans=0,res=0;
        for(int i=0;i<256;i++){
            if(mp[i]%2==0) ans+=mp[i];
            else{
                ans+=mp[i]-1;
                res=1;
            }
        }
        return ans+res;
    }
};
```
