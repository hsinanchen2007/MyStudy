class Solution 
{

public:
    struct node
    {
        int x, y;
    };
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int build(int x, int y, vector<vector<int>>& grid) //广度优先搜索
    {
        int width = grid[0].size(), height = grid.size();

        int result = 1;
        queue<node> my_que;
        my_que.push(node{x, y});
        grid[x][y] = 0;

        while(!my_que.empty())
        {
            auto head = my_que.front();
            my_que.pop();

            for(int i = 0; i < 4; i++)
            {
                int xx = head.x+dx[i], yy = head.y+dy[i];
                if(xx >= 0 && yy >= 0 && yy < width && xx < height && grid[xx][yy])
                    my_que.push(node{xx,yy}), 
                    grid[xx][yy] = 0,
                    result++;
            }
        }

        return result;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int ans = 0;
        int width = grid[0].size(), height = grid.size();

        for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            if(grid[i][j] == 1)
                ans = max(ans, build(i, j, grid));
                //cout << i << ' ' << j << endl;

        return ans;
    }
};
