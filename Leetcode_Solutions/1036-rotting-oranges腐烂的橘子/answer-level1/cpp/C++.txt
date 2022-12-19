class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int result=-1;
        int fresh=0;
        queue<pair<int,int>> Q;
        if(grid.size()==0) return -1;        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2)
                {
                    Q.push(make_pair(i,j));
                }else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if(!fresh) return 0;
        static const int dx[]={1,0,-1,0};
        static const int dy[]={0,1,0,-1};
            while(!Q.empty())
        {
            int num=Q.size();
            result++;//此处利用num很好地把每一轮腐败进行区分，从而记录步数
            while(num--)
            {
            int get_x=Q.front().first;
            int get_y=Q.front().second;
            Q.pop();
        for(int i=0;i<4;i++)
        {
            int newx=get_x+dx[i];
            int newy=get_y+dy[i];
            if(newx<0||newx>=grid.size()||newy<0||newy>=grid[newx].size())
            {
                continue;
            }
            if(grid[newx][newy]==1)
            {
                fresh--;
                grid[newx][newy]=2;
                Q.push(make_pair(newx,newy));
            }
        }
            }
        }
        return fresh?-1:result;
    }
};