和官方题解思路差不多，不过它对每个为1的点（陆地）进行搜索，可能更浪费时间，不如先把所有陆地纪录，只遍历一遍陆地
```
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        set<pair<int,int>> total;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]) total.insert(make_pair(i,j));
            }
        }
        int val=0;
        for(auto it=total.begin();it!=total.end();){
            int cnt=0;
            queue< pair<int,int> > que;//找到附近的点，存储，准备删除
            que.push(*it);//每次放入队列时，从集合中删除
            auto first=que.front();//队列的第一个点
            ++it;
            total.erase(first);
            vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
            while(!que.empty()){
                auto x=que.front();
                for(int i=0;i<4;++i){
                    int j=x.first+dir[i][0];
                    int k=x.second+dir[i][1];
                    if(total.find(make_pair(j,k))!=total.end()) {
                        que.push(make_pair(j,k));
                        if(*it==make_pair(j,k)) ++it;
                        total.erase(make_pair(j,k));
                    }
                }
                ++cnt;
                que.pop();
            }
            val=max(val,cnt);
        }
        return val;
    }
};
```
