```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans=0,ret=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(mp[s[j]]==0){
                    mp[s[j]]=1;
                    ans++;
                }else{
                    break;
                }
            }
            ret=max(ret,ans);
            mp.clear();
            ans=0;
        }
        return ret;
    }
};
```
