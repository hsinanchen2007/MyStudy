```
class Solution {
public:
    bool isPalindrome(string s) {
        
        int n=s.length();
        vector<char>ans;
        for(int i=0;i<n;i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
                if((s[i]>='A'&&s[i]<='Z'))s[i]=tolower(s[i]);
                ans.push_back(s[i]);
            }
        }
        int k=ans.size();
        for(int i=0,j=k-1;i<j;i++,j--){
            if(ans[i]!=ans[j])return false;
        }
        return true;
    }
};
```
