```
class Solution {

public:
    
    vector<int> shortestAlternatingPaths(int n,        vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
    queue<pair<int ,int>>q;
    unordered_map<int,vector<pair<int,int>> >m;
    for(auto i:red_edges)// red 0  blue 1
    {
        m[i[0]].push_back({i[1],0});


    }
    int visit[110][110][2];
    memset(visit,0,sizeof(visit));
    cout<<visit[10][10][0];
     

     for(auto i:blue_edges)// red 0  blue 1
    {
        m[i[0]].push_back({i[1],1});
        

    }
    vector<vector<int > >ans(n,vector<int>(2,1000000));//0 red 1 blue
   ans[0][0]=0;
   ans[0][1]=0;
    for(auto i:m[0])
    {
        q.push({i.first,i.second});
        if(i.second==0)
        ans[i.first][0]=1;
        else
        ans[i.first][1]=1;

      
       
        


    }
    
    while(!q.empty())
    {
        int len=q.size();
        for(int i=0;i<len;++i)
        {
            pair t=q.front();
            q.pop();
            for(auto j:m[t.first])
            {
              
                if(j.second!=t.second&&!visit[t.first][j.first][j.second])
                {   
                    
                     q.push({j.first,j.second});
                     visit[t.first][j.first][j.second]=1;

                }
                if(j.second==0&&ans[j.first][0]>ans[t.first][1]+1)// red
                {
                    ans[j.first][0]=ans[t.first][1]+1;
                }
                else if(j.second==1&&ans[j.first][1]>ans[t.first][0]+1)
                {
                    ans[j.first][1]=ans[t.first][0]+1;
                }

                  
            }
        }
    }
    vector<int>res(n);
    res[0]=0;
    for(int i=1;i<n;++i)
    {
       if(ans[i][0]==1000000&&ans[i][1]==1000000)
       res[i]=-1;
       else
       {
           res[i]=min(ans[i][0],ans[i][1]);
       }
          

    }
  
    return res;
    
    }
};
```
