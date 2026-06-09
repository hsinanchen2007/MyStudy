class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int min=0,fresh=0;
        queue<pair<int,int>> q;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    fresh++;
                }
                if(grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        while(!q.empty())
        {
            bool flag=false;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto temp=q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int new_x=temp.first+dx[j];
                    int new_y=temp.second+dy[j];
                    if(new_x>=0&&new_x<row&&new_y>=0&&new_y<col&&grid[new_x][new_y]==1)
                    {
                        fresh--;
                        grid[new_x][new_y]=2;
                        flag=true;
                        q.push(make_pair(new_x,new_y));
                    }
                }
            }
            if(flag)
            {
                min++;
            }
        }
        return fresh==0?min:-1;
    }
};