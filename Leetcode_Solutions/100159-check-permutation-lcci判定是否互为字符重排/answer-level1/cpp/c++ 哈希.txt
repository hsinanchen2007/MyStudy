```
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int ans[200]={0},flag=1;
        for(int i=0;i<s1.size();i++) ans[s1[i]-'0']++;
        for(int i=0;i<s2.size();i++) ans[s2[i]-'0']--;
        for(int i=0;i<200;i++)
            if(ans[i]!=0) flag=0;
        if(flag==0) return false;
        else return true;
    }
};
```
