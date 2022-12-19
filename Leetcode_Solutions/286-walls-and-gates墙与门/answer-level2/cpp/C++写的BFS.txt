官方题解中方法一的C++版本。
```
代码块
#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define INF 2147483647
#define WALL -1
#define DOOR 0
using namespace std;

class Solution
{
private:

public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {

        for (int i = 0; i < rooms.size(); i++)
        {
            for (int j = 0; j < rooms[0].size(); j++)
            {
                if (rooms[i][j] == INF)
                { /*遍历每一个rooms*/
                    rooms[i][j] = distanceToNearestGate(rooms, i, j);
                }
            }
        }
    }
    /**
     * distanceToNearestGate
     * 
     * i,j: 起始横纵坐标
     * return: 到最近门的距离
     * */
    int distanceToNearestGate(vector<vector<int>> &rooms, int i, int j)
    {
        int M = rooms.size();
        int N = rooms[0].size();
        int step = 0;

        queue<vector<int>> q;
        vector<vector<int>> used(M,vector<int>(N));
        int direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

        q.push({i, j});

        while (!q.empty())
        {
            int m = q.front()[0];
            int n = q.front()[1];
            q.pop();
            for(int i = 0;i<4;i++){
                int r = m + direction[i][0];
                int c = n + direction[i][1];
                if(r<0||c<0||r>=M||c>=N||rooms[r][c]== WALL||used[r][c]!=0){
                    continue;
                }
                used[r][c] = used[m][n]+1;
                if(rooms[r][c] == DOOR){
                    return used[r][c];
                }
                q.push({r,c});
            }
        }
        return INF;
    }
};

int main(void)
{
    vector<vector<int>> rooms;
    // rooms.push_back({0,-1,2147483647,-1});
    // rooms.push_back({-1,2147483647,-1,0});
    rooms.push_back({INF, -1, 0, INF});
    rooms.push_back({INF, INF, INF, -1});
    rooms.push_back({INF, -1, INF, -1});
    rooms.push_back({0, -1, INF, INF});
    Solution s;
    s.wallsAndGates(rooms);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << rooms[i][j];
        }
        cout<<endl;
    }

    return 0;
}
```
