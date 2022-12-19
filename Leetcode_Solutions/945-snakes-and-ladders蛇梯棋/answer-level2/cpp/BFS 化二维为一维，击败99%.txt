```
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
       int n=board.size();
       queue<int >q;
       vector<int>b;
       b.push_back(-1);
       int flag=1;
       for(int i=n-1;i>=0;--i)
       {   
           if(flag==1)
           {
        for(int j=0;j<n;++j)
        {   
           b.push_back(board[i][j]);
        }
           }
       
          else{
        for(int j=n-1;j>=0;--j)
        {   
           b.push_back(board[i][j]);
        }
          }
          flag=-flag;
       }
       
       
       vector<int>visit(n*n+1,0);
       q.push(1);
       visit[1]=1;
       int cnt=0;
       
       while(!q.empty())
       { 
           cnt++;
         int len=q.size();
         for(int i=0;i<len;++i)
         {
             int t=q.front();
             q.pop();
             for(int j=1;j<=6;j++)
             {    
                 
                 if(t+j<=n*n)
                 {  
                    if(b[t+j]==n*n||t+j==n*n)
                      return cnt;
                    if(b[t+j]!=-1)//snake or ladders
                    {
                        if(visit[b[t+j]]==0)
                        {
                            visit[b[t+j]]=1;
                            q.push(b[t+j]);
                        }
                    }
                    else
                    {
                        if(visit[t+j]==0)
                        {
                            visit[t+j]=1;
                            q.push(t+j);
                        }
                    }
                 }
             }
         }

       }

     return -1;
    }
};
```
