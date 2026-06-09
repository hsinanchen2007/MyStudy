```
//执行用时 :16 ms, 在所有 C++ 提交中击败了97.87%的用户
//内存消耗 :9.9 MB, 在所有 C++ 提交中击败了94.12%的用户
//关键数组:vis标记起始点的访问情况，jump标记这个点是否已经爬过梯子或蛇
class Solution {
public:
    int i,j,n,cnt,size,dist;
    bool vis[500],jump[500],flag;
    int map[500];
    queue<int> que;
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();flag = true;cnt = 1;
        for(i=n-1;i>=0;i--) {//二维转一维
            if(flag) {
                for(j=0;j<n;j++) 
                    map[cnt++] = board[i][j];
                flag = false;
            }
            else {
                for(j=n-1;j>=0;j--)
                    map[cnt++] = board[i][j];
                flag = true;
            }
        }
        que.push(1);vis[1] = true;//记入初始位置
        while(que.size()) {
            size = que.size();
            while(size--) {
                auto p = que.front();que.pop();
                if(p==n*n) return dist;//找到目标值
                for(i=1;i<=6;i++) if(p+i<=n*n) {
                    if(map[p+i]!=-1) {
                        if(!jump[p+i]) {
                            jump[p+i] = true;//标记已经爬过梯子或蛇的点
                            que.push(map[p+i]);
                            vis[map[p+i]] = true;//计入新的起始点
                        }
                    }else {
                        if(!vis[p+i]) {
                            vis[p+i] = true;
                            que.push(p+i);
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};
```
