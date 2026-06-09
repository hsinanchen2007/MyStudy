```
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1,vector<double> (query_row+1,0));
        
        //int rest=poured;
        if(poured < 1){
            return 0.0;
        }
        if(query_row==0 && query_glass == 0)
                return poured>1?1.0:poured;
        if(poured >= 1){
            dp[0][0]=poured-1;
            
        }
        
        //cout<<dp[0][0]<<"   ";                          
        //dp[i][j]表示倒入第i,j个杯子后溢出的量
        for(int i=1;i<query_row+1;i++){
            for(int j=0;j<i+1;j++){
                if(j==0)
                    dp[i][j]=dp[i-1][j]/2.0 ;
                else if(j==i)
                    dp[i][j]=dp[i-1][j-1]/2.0;
                else
                    dp[i][j]=dp[i-1][j-1]/2.0+dp[i-1][j]/2.0;
                //cout<<i<<"  "<<j<<"  "<<dp[i][j]<<"   ";  
                if(query_row  ==i&& query_glass== j){//所以在算溢出的量之前，先判断该杯子的量
                    //cout<<(dp[i][j]>=1)<<"   "<<(dp[i][j]>=1?1:dp[i][j])<<"   ";
                    return dp[i][j]>=1?1:dp[i][j];
                }
                    
                dp[i][j]=dp[i][j]-1>0?dp[i][j]-1:0;
                //cout<<dp[i][j]<<endl;  
                
            }
        }
        return 0.0;    
    }
};
```
