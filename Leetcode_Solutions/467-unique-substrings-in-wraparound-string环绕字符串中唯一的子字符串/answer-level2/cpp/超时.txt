class Solution {
public:
    vector<int> dp;
    map<string,int> m;
    int findSubstringInWraproundString(string p) {
        if(p.size()==0)
           return 0;
          dp.resize(p.size());
          m[p.substr(0,1)]=1;
          dp[0]=1;
          for(int i=1;i<p.size();++i){
              dp[i]=dp[i-1];
              if(m[p.substr(i,1)]==0){
                  dp[i]++;
                  m[p.substr(i,1)]=1;
              }
              for(int j=i-1;j>=0;--j){
               if(p[j]+1==p[j+1]||p[j]+1-26==p[j+1]){
                  string s=p.substr(j,i-j+1);
                  if(m[s]==0){
                       dp[i]+=1;
                       m[s]=1;
                  }
               }else
                  break;
               }
          }
          return dp[p.size()-1];
    }
};