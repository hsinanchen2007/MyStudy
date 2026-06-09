```cpp
class Solution {
public:
    const int inf=0x7fffffff;
    int N;
    void dj(int n,vector<int> vis,vector<vector<double>> &Map){//类似迪杰斯特拉算法，由已知合并未知，未知的位置值为inf
        for(int i=1;i<=N;i++){
            int t=0;
            for(int j=1;j<=N;j++)
                if(j-n&&!vis[j]&&Map[n][j]<inf){
                    t=j;
                    break;
                }
            if(!t)
                return;
            vis[t]=1;
            for(int j=1;j<=N;j++)
                if(j-n&&t-j&&!vis[j]&&Map[n][j]==inf&&Map[t][j]<inf)
                    Map[n][j]=Map[n][t]*Map[t][j];
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,int> M;
        N=0;
        for(int i=0;i<equations.size();i++){//计算已知字符串个数，同时把字符串哈希
            if(!M.count(equations[i][0]))
                M[equations[i][0]]=++N;
            if(!M.count(equations[i][1]))
                M[equations[i][1]]=++N;
        }
        vector<vector<double>> Map(N+1,vector<double>(N+1,0x7fffffff));
        for(int i=1;i<=N;i++)//相同两个字符串相除结果为1
            Map[i][i]=1;
        for(int i=0;i<equations.size();i++){//建立已知字符串对的二维表
            Map[M[equations[i][0]]][M[equations[i][1]]]=values[i];
            Map[M[equations[i][1]]][M[equations[i][0]]]=1/values[i];
        }
        for(int i=1;i<=N;i++){//对每一个字符串为除数合并未知的被除数
            vector<int> vis(N+1,0);
            dj(i,vis,Map);
        }
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(Map[i][j]==inf)//把二维表初始值的位置改为-1
                    Map[i][j]=-1;
        vector<double> A(queries.size(),-1);//结果字符串初始化每一个值为-1
        for(int i=0;i<queries.size();i++)
            if(M.count(queries[i][0])&&M.count(queries[i][1]))//两个字符串若都存在哈希值则把结果数组中当前位置的值改为Map中对应位置的值
                A[i]=Map[M[queries[i][0]]][M[queries[i][1]]];
        return A;
    }
};
```
