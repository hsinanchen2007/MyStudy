    class Solution {
    public:
        string encode(string s) {
            int n=s.size();
            vector<vector<string>> dp(n,vector<string>(n,""));
            for(int step=1;step<=n;++step){
                for(int i=0;i<n-step+1;++i){ 
                    int j=i+step-1;
                    string r="",t;
                    int pos;
                    t=s.substr(i,step);
                    pos=(t+t).find(t,1);
                    dp[i][j]=t;
                    if(pos<step){
                        r=to_string(step/pos)+'['+dp[i][i+pos-1]+']';
                        if(r.size()<t.size())dp[i][j]=r;
                    }
                    
                    for(int k=i;k<j;++k){
                        string L=dp[i][k];
                        string R=dp[k+1][j];
                        if(L.size()+R.size()<dp[i][j].size())dp[i][j]=L+R;
                    }
                }
            }
            return dp[0][n-1];
        }
    };