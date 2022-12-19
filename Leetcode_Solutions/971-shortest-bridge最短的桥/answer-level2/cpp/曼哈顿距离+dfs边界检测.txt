```
class Solution {
public://刚开始用记忆搜索蒙蔽了很麻烦，后来想到用边界加曼哈顿距离（不过这也是卡了样例bug,有中心湖的话还要改改）
    int i,j,len,index=2,res=INT_MAX;
    vector<pair<int,int>> con,con1;
    vector<vector<int>> grid;
    bool vis[100][100];
    int shortestBridge(vector<vector<int>>& A) {
        len = A.size();grid = A;
        for(i=0;i<len;i++) {
            for(j=0;j<len;j++) {
                if(grid[i][j]==1) {
                    mark(i,j);
                    index++;
                }
            }
        }
        for(auto& it: con) 
            for(auto& it1: con1)
                res = min(res,abs(it.first-it1.first)+abs(it.second-it1.second)-1);
        return res;
    }
    void mark(int i,int j) {
        if(i<0||i>len-1||j<0||j>len-1||vis[i][j]||!grid[i][j]) return;
        vis[i][j] = true;
        grid[i][j] = index;
        if(judge(i,j)) {
            auto& v = index==2?con:con1;
            v.push_back(make_pair(i,j));
        }
        mark(i,j+1);mark(i,j-1);mark(i+1,j);mark(i-1,j);
    }
    bool judge(int i,int j) {
        if(j<len-1&&!grid[i][j+1]) return true;
        if(j>=1&&!grid[i][j-1]) return true;
        if(i<len-1&&!grid[i+1][j]) return true;
        if(i>=1&&!grid[i-1][j]) return true;
        return false;
    }
};
```
