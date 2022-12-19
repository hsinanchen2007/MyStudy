### 解题思路
这道题还是有些意思的，按照题目捋一遍过程，可以联想到用BFS的思路。
BFS的实现是标准的队列方法，这里不用过多赘述。
不过这道题有趣的地方是要求你返回多源BFS的最大深度，这里的代码是采用了一个额外的哨兵放在BFS的队列中，我觉得这种方法还是有些巧妙的。每当从队列中取出的是这个哨兵的时候，说明BFS已经走完了一层，计数+1，然后继续将哨兵放回队列即可。
最后还要注意当且仅当图里有橘子且不连通的时候才返回-1，无橘子的图需要返回0。

最后，我觉得Leetcode把这道题设为简单是因为这道题测试例的数据量很小，最大也就是10*10，因此各种奇怪的暴力算法也能够通过。如果把数据量提高一些，那就基本上非BFS不可了。

### 代码

```cpp
class Solution {
public:
    struct Position{
        int x, y;
        Position(){}
        Position(int _x, int _y): x(_x), y(_y){}
    };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Position> que;
        Position offset[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int goodOranges = 0;
        int time = 0;

        for(int i = 0; i <grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(2 == grid[i][j]){
                    que.push(Position(i, j));
                }
                else if(1 == grid[i][j])
                {
                    goodOranges++;
                }
            }
        }
        que.push(Position(-1, -1)); //A scout


        while(que.size() > 1)
        {
            Position p = que.front();
            que.pop();

            if((-1 == p.x) && (-1 == p.y))
            {
                time++;
                que.push(p);
            }
            else
            {
                for(int i = 0; i < 4; i++)
                {
                    Position n(p.x + offset[i].x, p.y + offset[i].y);
                    if((n.x < grid.size()) && (n.y <grid[n.x].size()) && (1 == grid[n.x][n.y]))
                    {
                        grid[n.x][n.y] = 2;
                        que.push(n);
                        goodOranges--;
                    }
                }
            }
        }

        if(goodOranges > 0) time = -1;

        return time;

    }
};
```