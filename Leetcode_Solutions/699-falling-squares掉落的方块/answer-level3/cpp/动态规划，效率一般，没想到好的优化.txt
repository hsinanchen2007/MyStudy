必须得说点啥
。
。
。
。
。
。


class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& p) {
        int len=p.size();
        vector<int> dp(len,0);
        vector<int> result(len,0);

        dp[0]=p[0][1];
        result[0]=p[0][1];
        for(int i=1;i<len;i++){
            dp[i]=p[i][1];

            for(int j=0;j<i;j++){
                if(p[j][0]<=p[i][0] && p[i][0]<(p[j][0]+p[j][1])){
                    dp[i]=max(dp[i],dp[j]+p[i][1]);
                } else  if(p[j][0]<(p[i][0]+p[i][1]) && (p[i][0]+p[i][1])<=(p[j][0]+p[j][1])) {                   
                    dp[i]=max(dp[i],dp[j]+p[i][1]);
                }  else if(p[j][0]>(p[i][0]) && (p[i][0]+p[i][1])>(p[j][0]+p[j][1])){
                    dp[i]=max(dp[i],dp[j]+p[i][1]);
                }

            }
            result[i]=max(dp[i],result[i-1]);
          }
        return result;        
    }


};