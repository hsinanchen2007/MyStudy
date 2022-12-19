```
class Solution {
public:
    class Node{
    public:
        int r, c;
        Node(int i, int j): r(i), c(j){
        }
    };

    int maxDistance(vector<vector<int> >& grid)
    {
        queue<Node> qu;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[1].size(); j++)
                if(grid[i][j] == 1)
                    qu.push(Node(i, j));

        if(qu.size() == 0 || qu.size() == grid.size() * grid[0].size())
            return -1;

        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int max = 0;
        while(!qu.empty())
        {
            for(int i = 0; i < 4; i++)
            {
                int r = qu.front().r + dir[i][0];
                int c = qu.front().c + dir[i][1];
                if(r >= 0 && r < grid.size() 
                    && c >= 0 && c < grid[0].size()
                    && grid[r][c] == 0)
                {
                    grid[r][c] = grid[qu.front().r][qu.front().c] + 1;
                    max = std::max(grid[r][c], max);
                    qu.push(Node(r, c));
                }	
            }
            qu.pop();
        }
        return max-1;
    }
};
```
