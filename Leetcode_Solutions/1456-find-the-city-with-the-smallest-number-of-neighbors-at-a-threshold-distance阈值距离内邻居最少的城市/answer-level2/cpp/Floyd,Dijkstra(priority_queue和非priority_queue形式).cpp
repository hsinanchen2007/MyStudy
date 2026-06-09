### 解题思路
dijkstra有两种形式，一种采用邻接矩阵的形式，适用于稠密图。
另一种形式采用邻接表的形式，适用于稀疏图，利用了priority_queue。

### 代码

```cpp
class Solution {
public:
    // int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //     // floyd算法 依次将第三个点作为中间结点
    //     // 需要邻接矩阵 读入邻接矩阵部分
    //     int inf=0x3f3f3f3f;
    //     int e[n][n];
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==j) e[i][j] = 0;
    //             else e[i][j] = inf;
    //         }
    //     }
    //     // 读入边
    //     int form,to,weight;
    //     for(int i=0;i<edges.size();i++){
    //         int from = edges[i][0];
    //         int to = edges[i][1];
    //         int weight = edges[i][2];
    //         e[from][to] = weight;
    //         e[to][from] = weight;
    //     }
    //     // Floyd算法部分
    //     for(int k=0;k<n;k++){
    //         for(int i=0;i<n;i++){
    //             for(int j=0;j<n;j++){
    //                 if(e[i][j]>e[i][k]+e[j][k]){
    //                     e[i][j] = e[i][k]+e[j][k];
    //                     e[j][i] = e[i][j];
    //                 }
    //             }
    //         }
    //     }
    //     map<int,int> mp; // 城市，数量
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(e[i][j]<=distanceThreshold){
    //                 mp[i]++;
    //             }
    //         }
    //     }
    //     vector<pair<int,int>> vec(mp.begin(),mp.end());
    //     sort(vec.begin(),vec.end(),cmp);
    //     return vec[0].first;
    // }
    // static bool cmp(pair<int,int>& a,pair<int,int>& b){
    //     if(a.second==b.second) return a.first>b.first;
    //     return a.second<b.second;
    // }
    
//     int points;
//     int inf = 0x3f3f3f3f;
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         // 采用dijstra算法 稠密图
//         points = n;
//         vector<vector<int>> e(n,vector<int>(n,inf));
//         int len = edges.size();
//         for(int i=0;i<len;i++){
//             int from = edges[i][0];
//             int to = edges[i][1];
//             e[from][to] = edges[i][2];
//             e[to][from] = edges[i][2];
//         }
//         for(int i=0;i<points;i++){
//             e[i][i] = 0;
//         }
//         int city = -1;
//         int cityn = inf;
//         for(int i=0;i<points;i++){
//             vector<int> dis = dijstra(e,i);
//             cout<<"i"<<i<<endl;
//             for(auto c:dis) cout<<c<<endl;
            
//             int cnt=0;
//             for(int j=0;j<n;j++){
//                 if((i!=j)&&dis[j]<=distanceThreshold) cnt++;
//             }
//             if((city==-1)||(cnt<=cityn)){
//                 city = i;
//                 cityn = cnt;
//             }
//         }
//         return city;
//     }
//     vector<int> dijstra(vector<vector<int>>& e,int startpoint){
//         // dijstra 稠密图 输入起点和邻接矩阵，返回该点到其他点的最短距离
//         vector<int> dis = e[startpoint]; // 初始距离
//         vector<int> used(points,-1); 
//         used[startpoint] = 1; // 标记起点已经放入
//         // 依次从points中选取距离startpoint最近的点
//         for(int i=1;i<points;i++){
//             int k=-1;
//             for(int j=0;j<points;j++){
//                 if((used[j]!=1)&&((k==-1)||dis[j]<dis[k])) k = j;//在未使用的点中寻找到startpoint最近的点
//             }
//             used[k] = 1;// 把k点放入集合中
//             // 将k点作为中转点，更新集合中的点到startpoint点的距离
//             for(int p=0;p<points;p++){
//                 if(dis[p]>dis[k]+e[k][p]) dis[p] = dis[k] + e[k][p];
//             }
//         }
//         return dis;
//     }
    int points;
    int inf = 0x3f3f3f3f;
    // vector<map<int,int>> vec;
    typedef pair<int,int> PII;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Dijstra算法 priority_queue形式，按边遍历，适用于稀疏图
        //构建邻接表
        points = n;
        vector<map<int,int>> vec(n);
        int len = edges.size();
        for(int i=0;i<len;i++){
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];
            vec[from][to] = weight;
            vec[to][from] = weight;
        }
        int resp =-1; // 返回的点
        int resn = inf; // 连接的点数目
        for(int i=0;i<n;i++){
            // 遍历n个点
            int curp = i;
            int curn = -1; // 排除自身
            vector<int> dis = dijstra(vec,curp);

            for(int j=0;j<n;j++){
                if(dis[j]<=distanceThreshold) curn++;
            }
            if(curn<=resn) {resp = curp;resn=curn;}
            
        }
        return resp;
    }
    struct cmp{
        bool operator()(PII&a,PII&b){
            return a.second>b.second;
        }
    };
    vector<int> dijstra(vector<map<int,int>>& vec,int startpoint){
        //稀疏图 邻接链表 priority_queue
        vector<int> dis(points,inf);
        vector<int> used(points,0);
        priority_queue<PII,vector<PII>,cmp> qu;
        qu.push({startpoint,0});
        while(!qu.empty()){
            auto qtop = qu.top();qu.pop();
            int curp = qtop.first;
            int curv = qtop.second;
            if(used[curp]==1) continue;
            dis[curp] = curv;
            used[curp] = 1;
            // 对curp的临接点距离更新
            for(map<int,int>::iterator it=vec[curp].begin();it!=vec[curp].end();it++){
                qu.push({it->first,it->second+curv});
            }
        }
        return dis;
    }
};


```