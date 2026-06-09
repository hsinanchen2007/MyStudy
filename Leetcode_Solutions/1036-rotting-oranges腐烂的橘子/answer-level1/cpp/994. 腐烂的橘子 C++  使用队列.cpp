### 解题思路
此处撰写解题思路

### 代码

```cpp

struct Position
{
    Position(int r, int c) : row(r), col(c) {}
    int row;
    int col;
};

class Solution {
public:

    //存在新鲜橘子
    bool fresh_exist(vector<vector<int>>& grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid.at(i).size(); ++j)
            {
                if (grid.at(i).at(j) == 1)
                {
                    return true;
                }
            }
        }
        return false;
    }


    int orangesRotting(vector<vector<int>>& grid) {

        //开始找所有烂橘子 入队
        queue<Position> q;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid.at(i).size(); ++j)
            {
                if (grid.at(i).at(j) == 2)
                {
                    q.push(Position(i, j));
                }
            }
        }

        int minute = 0;

        for (;;)
        {
            vector<Position> v_pos;
            v_pos.reserve(q.size());

            while (!q.empty())
            {
                //一次出队所有的烂橘子 然后才去烂橘子四个正方向上找新鲜橘子（为了统计分钟数）
                v_pos.push_back(q.front());
                q.pop();
            }

            //去所有烂橘子四个正方向上找新鲜橘子 将新鲜橘子腐烂后 入队
            for (int i = 0; i < v_pos.size(); ++i)
            {
                //上
                if (v_pos.at(i).row - 1 >= 0)
                {
                    Position pos(v_pos.at(i).row - 1, v_pos.at(i).col);
                    if (grid.at(pos.row).at(pos.col) == 1) //新鲜橘子
                    {
                        grid.at(pos.row).at(pos.col) = 2; //腐烂
                        q.push(pos); //入队
                    }
                }

                //下
                if (v_pos.at(i).row + 1 < grid.size())
                {
                    Position pos(v_pos.at(i).row + 1, v_pos.at(i).col);
                    if (grid.at(pos.row).at(pos.col) == 1) //新鲜橘子
                    {
                        grid.at(pos.row).at(pos.col) = 2; //腐烂
                        q.push(pos); //入队
                    }
                }

                //左
                if (v_pos.at(i).col - 1 >= 0)
                {
                    Position pos(v_pos.at(i).row, v_pos.at(i).col - 1);
                    if (grid.at(pos.row).at(pos.col) == 1) //新鲜橘子
                    {
                        grid.at(pos.row).at(pos.col) = 2; //腐烂
                        q.push(pos); //入队
                    }
                }

                //右
                if (v_pos.at(i).col + 1 < grid.at(0).size())
                {
                    Position pos(v_pos.at(i).row, v_pos.at(i).col + 1);
                    if (grid.at(pos.row).at(pos.col) == 1) //新鲜橘子
                    {
                        grid.at(pos.row).at(pos.col) = 2; //腐烂
                        q.push(pos); //入队
                    }
                }
            }

            //1分钟后 没有新腐烂的橘子
            if (q.empty())
            {
                break;
            }

            ++minute;
        }

        if (fresh_exist(grid)) //仍有新鲜橘子
        {
            return -1;
        }

        return minute;
    }
};
```