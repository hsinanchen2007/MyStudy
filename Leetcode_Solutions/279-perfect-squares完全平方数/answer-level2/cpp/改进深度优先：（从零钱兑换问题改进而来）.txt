```
class Solution {
public:
    int numSquares(int n) {
       if(n<=0) return 0;
       int q=sqrt(n);
       int cnt=INT_MAX;
       dfs(n,0,cnt,q);
       return cnt;
    }
    void dfs(int n,int sum, int& cnt,int start)
    {
        if(start<0)
            return ;
        if(start==0 || n==0)
        {
            cnt=min(sum,cnt);
            return ;
        }   
        if(n%(int)pow(start,2)==0 )
        {
            cnt=min(sum+n/(int)pow(start,2),cnt);
            return ;
        }  
        for(int i=(n/start)/start;i>=0 ;--i)
        {
            if(sum+i>cnt)
                return ;
            dfs(n-i*start*start,sum+i,cnt,start-1);
        } 
    }
};

```
