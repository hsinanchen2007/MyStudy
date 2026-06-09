分享一个弗洛伊德加状态压缩DP的做法
先用弗洛伊德求出任意两点间的距离记录在dis[][]之中，然后做一次动态规划。
用f[S][i]表示当前状态S下，以i结尾的访问序列的总最短路径。
S是最大12位的二进制数，位置1表示当前点已访问过
转移公式为
f[S][i] = min(F[S'][k] + dis[i][k])
S'表示上一个状态，即将S中的第i位置0的状态
这里使用了记忆化搜索
弗洛伊德时间复杂度O(N^3)
总共有(2^N * N) 个状态，每个状态访问一次，所以总的复杂度为(2^N * N)
同理，空间复杂度也为(2^N * N)
```
const int MAXN = 12;
const int MAX_NUMS_STATE = 1 << MAXN;
int dis[MAXN][MAXN];
int f[MAX_NUMS_STATE][MAXN];
class Solution {
    int N;
    int dfs(int state, int pos){
        if (f[state][pos] != 0x3fffffff){
            return f[state][pos];
        }

        //新的状态（变量名令人迷惑^_^）
        int lastState = state ^ (1 << pos);
        
        int ret = 0x3fffffff;
        //遍历上次访问的节点
        for (int i = 0;i < N;++i){
            //状态里的第i位为0和最后访问的节点是i冲突，状态不合法，跳过
            if ((lastState & (1 << i)) == 0 || i == pos) 
                continue;
            ret = min(dfs(lastState, i) + dis[i][pos], ret);
        }

        f[state][pos] = ret;

        return ret;
    }
public:
    int shortestPathLength(vector<vector<int> >& graph) {
        N = graph.size();
        for (int i = 0;i < N;++i){
            for (int j = 0;j < N;++j){
                dis[i][j] = 0x3fffffff;
            }
        }
        for (int i = 0;i < (1 << N);++i){
            for (int j = 0;j < N;++j){
                f[i][j] = 0x3fffffff;
            }
        }

        for (int i = 0;i < N;++i){
            //dis[i][i] = 0;
            for (int j = 0;j < graph[i].size();++j){
                dis[i][graph[i][j]] = 1;
            }
        }
        //弗洛伊德算法，求任意两点间距离
        for (int k = 0;k < N;++k){
            for (int i = 0;i < N;++i){
                for (int j = 0;j < N;++j){
                    if (i != j && dis[i][j] > dis[i][k] + dis[k][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }

        for (int i = 0;i < N;++i){
            f[1 << i][i] = 0;
        }


        int ans = numeric_limits<int>::max();
        int finState = 1 << N;
        --finState;

        //cout << finState << endl;
        for (int i = 0;i < N;++i){
            ans = min(ans, dfs(finState, i));
            //cout << dfs(finState, i) << endl;
        }
        return ans;
    }
};
```
