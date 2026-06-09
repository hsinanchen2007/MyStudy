#### 使用hash数组记录每一个字母出现的次数就可以啦，注意，当出现偶数的时候直接加上，当出现奇数的时候先减一加上，最后一步，ans++,因为奇数可以放在最中间！
```
class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        vector<int>cnt(128,0);
        //int cnt[n+1]={0};
        for(int i=0;i<n;i++){
            //int num=s[i]-'A';
            cnt[s[i]-'A']++;
        }
        int ans=0;
        int maxn=0;
        bool flag=false;
        for(int i=0;i<128;i++){
            if(cnt[i]!=0&&cnt[i]%2==0){
                ans+=cnt[i];
            }
            if(cnt[i]%2==1&&cnt[i]!=0){
                ans+=(cnt[i]-1);
                flag=true; 
            }
        }
        if(flag)ans++;
        return ans;
    }
};
```