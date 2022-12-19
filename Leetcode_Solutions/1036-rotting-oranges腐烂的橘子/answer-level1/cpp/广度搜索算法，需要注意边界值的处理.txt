### 解题思路
根据题意：
1. 每次扩散上下左右位置（规则）；
2. 完成条件为fresh为0 或者腐烂扩散已经执行完成；

实际实现过程：
1. 遍历grid统计初始2的位置，统计为1的个数；
2. 使用队列统计每一次新腐烂的个数，并进行新一轮的感染扩散，直至无法新增，则意味着感染流程结束；
3. 每一轮感染处理完后，根据fresh的个数做判断是否返回；

遇到的问题：
1. row和col弄反导致内存越界异常，细节需要注意；
2. 对于time的判断，time+1需要处理完当前插入2的总数，对于queue来讲，需要每次进入循环获取当前queue的size，这里需要用个临时变量保存（或者也可以做减法），因为在处理过程中有插入新的2，所以其实size是会变的；

### 代码

```cpp
class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
//这个是个搜索问题；
//结果返回时间，即经过处理的time，可以对每一次处理计数+1；
//每一次处理要对所有2周围的数字检查一遍，则需要记录1的数量，用于返回判断（1的数量为0，或者都已经遍历过了）
//还需要记录为2的位置，逐步计算扩散（这个用队列比较合适，先进先出）
        queue<pair<int, int>> rotqueue;
        int freshCount = 0;
        //1. 遍历计算腐烂位置，和fresh数量；
        int row = grid.size();
        if(0 == row) return 0;
        int col = grid[0].size();
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(2 == grid[i][j]) {
                    // cout<<"i:"<<i<<" j:"<<j<<endl;
                    rotqueue.push({i, j});
                } else if(1 == grid[i][j]) {
                    freshCount++;
                }
            }
        }
        if(0 == freshCount) return 0;
        //计算上下左右坐标；
        int x_shift[] = {-1, 0, 1, 0};
        int y_shift[] = {0, 1, 0, -1};
        //BFS计算
        int time = 0;
        // cout<<freshCount<<endl;
        while(!rotqueue.empty()) {
            time++;
            // cout<<"rotqueue.size(): "<< rotqueue.size()<<endl;
            int size = rotqueue.size();
            for(int i=0; i<size; i++) {
                auto cur = rotqueue.front();
                rotqueue.pop();
                for(int j=0; j<4; j++) {
                    int x = cur.first + x_shift[j];
                    int y = cur.second + y_shift[j];
                    if(x<0 || x>=row || y<0 || y>=col || grid[x][y]!=1){
                        continue;
                    } else {
                        grid[x][y] = 2;
                        rotqueue.push({x, y});
                        freshCount--;
                    }
                }
                // cout<<"rotqueue.size1111: "<< rotqueue.size()<<endl;
                if(0 == freshCount) return time;
            }
            // cout<<"freshCount: "<<freshCount<<endl;
        }
        return -1;
    }

};
```