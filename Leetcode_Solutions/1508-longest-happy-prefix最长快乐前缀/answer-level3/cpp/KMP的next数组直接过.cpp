class Solution {
public:
    string longestPrefix(string s) {
    int n=s.size();
    vector<int>next(n);

    next[0]=-1;
    int k=-1;

    for(int i=1;i<n;i++){
        while(k>-1&&s[k+1]!=s[i])k=next[k];
        if(s[k+1]==s[i])k=k+1;
        next[i]=k;
    }


    string ans="";
    for(int i=0;i<next[n-1]+1;i++){
        ans+=s[i];
    }
    return ans;
    }
};