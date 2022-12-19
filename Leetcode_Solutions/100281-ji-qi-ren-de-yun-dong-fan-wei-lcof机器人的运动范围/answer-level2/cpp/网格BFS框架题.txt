### 解题思路
执行用时击败81.25%，说明应该是找到正确的方法了；
思路：
1、建立m*n的网格，初始化为0；
2、遍历网格，将满足条件的格子标记为1；
3、从（0，0）点出发，用BFS遍历（0，0）所在的连通分支（网格值得为1），计算能到多少个网格

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        //遍历一边所有的格子，看那些格子是满足的
        //从0出发，用BFS看能到多少格子
        if(k==0) return 1;
        vector<vector<int>> grid(m, vector<int> (n, 0));//初始化网格
        //标记满足条件的网格为1
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(Judge(i, j)<=k) grid[i][j]=1;
            }
        }
        //初始化上下左右四种操作
        vector<pair<int, int>> op;
        op.push_back({1,0});
        op.push_back({-1,0});
        op.push_back({0,1});
        op.push_back({0,-1});
        //BFS遍历(0,0)在的连通分支节点数
        vector<vector<bool>> inq(m, vector<bool> (n, false));//是否入队过
        queue<pair<int, int>> q;
        q.push({0,0});
        int re=1;
        inq[0][0]=true;
        while(!q.empty()){
            pair<int, int> now=q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int ii=now.first+op[i].first;
                int jj=now.second+op[i].second;
                if(ii>=0 && ii<m && jj>=0 && jj<n){
                    if(!inq[ii][jj] && grid[ii][jj]){
                        inq[ii][jj]=true;
                        re++;
                        q.push({ii, jj});
                    }
                }
            }
        }
        return re;
    }
    int Judge(int a, int b){
        int re=0;
        while(a>0){
            re+=a%10;
            a=a/10;
        }
        while(b>0){
            re+=b%10;
            b=b/10;
        }
        return re;
    }
};
```