方法一 BFS
根据https://leetcode-cn.com/problems/rotting-oranges/solution/994-by-ikaruga/
值 1 代表新鲜橘子，值 2 代表腐烂的橘子
在这里2还代表第0分钟坏的橘子，此后变坏橘子的值=使它变坏的烂橘子值+1，比如第一分钟变坏的橘子的值为3，第二分钟变坏的橘子的值为4。
最后所有橘子都是腐烂的时所需分钟数=最后一个变坏的橘子的值-2。
```
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int good = 0,res = 0;;
        queue<pair<int,int>> rot;//放坏橘子
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//上下左右四个方向
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1) good++;//good记录好橘子个数
                if (grid[i][j] == 2) rot.push({i,j});
            }
        }
        while (!rot.empty()){
            auto cur = rot.front();
            rot.pop();
            for (auto pr : dirs){
                int x = cur.first + pr.first;
                int y = cur.second + pr.second;//与坏橘子相邻的橘子 
                if (x < 0 || x >= grid.size()) continue;//超出边界
                if (y < 0 || y >= grid[0].size()) continue;//超出边界
                if (grid[x][y] != 1) continue;//与坏橘子相邻的橘子不是好橘子
                grid[x][y] = grid[cur.first][cur.second] + 1;//好橘子变坏
                rot.push({x,y});//将变坏的橘子加入坏橘子队列
                good--;//将变坏的橘子从好橘子剔除
                res = grid[x][y] -2;//该变坏橘子是第几分钟变坏的
            }
        }
        return good == 0 ? res:-1;
    }
};
```
方法二 队列+集合
```
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };//上下左右四个方向
        queue<pair<int,int>> rot;//放坏橘子
        set<pair<int,int>> good;//放好橘子
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) good.insert(make_pair(i,j));//将好橘子放到集合中
                if(grid[i][j] == 2) rot.push(make_pair(i,j));//将坏橘子放到队列中
            }
        }
        while(!rot.empty()){
            int flag = 0,rsize = rot.size(); 
            for(int i = 0; i < rsize; i++){
                auto cur=rot.front();
                rot.pop();//将遍历过的坏橘子弹出
                pair<int, int> tmp;
                for(auto pr : dirs){
                    tmp=make_pair(cur.first+pr.first,cur.second+pr.second);
                    if(good.find(tmp) != good.end()){ //找到与腐烂橘子相邻的好橘子
                        flag = 1;//表示有找到与腐烂橘子相邻的好橘子
                        good.erase(tmp);//将变坏的橘子从好橘子集合移除
                        rot.push(tmp);//将变坏的橘子加入坏橘子队列
                    }
                }
            }
            if(flag) res+=1;
        }
        return good.size() == 0 ? res:-1;
    }
};
```


