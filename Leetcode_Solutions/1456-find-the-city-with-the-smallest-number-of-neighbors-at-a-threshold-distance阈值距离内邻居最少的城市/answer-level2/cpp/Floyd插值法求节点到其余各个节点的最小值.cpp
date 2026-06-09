### 解题思路
首先感谢题解区的各位同学！！！
思路：
1、建立邻接矩阵G和计数数组count;
2、将edges读入邻接矩阵；
3、利用floyd插值法，求出各个节点到其余各个节点的距离最小值；
4、对每一行进行统计，看有多少个节点可达，放入count数组；
5、对count数组从尾至头遍历，找出值最小但index最大但数。


### 代码

```cpp
class Solution {
public:

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //对每个节点做深度遍历，找到一个城市就+1
        int G[101][101];
        int count[101];
        fill(G[0], G[0] + 101*101, INT_MAX);//初始化邻接矩阵，注意二维矩阵的赋值要用G[0]
        memset(count, 0, sizeof(count));//初始化统计矩阵
        for (int i=0; i<edges.size(); i++){
            G[edges[i][0]][edges[i][1]]=edges[i][2];
            G[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for (int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if (i==j || G[i][k]==INT_MAX || G[j][k]==INT_MAX) continue;
                    G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
                    G[j][i]=G[i][j];
                }
            }
        }
        for(int i=0; i<n; i++){
            for (int j=0; j<n; j++) if (G[i][j]<=distanceThreshold) count[i]++;
        }
        int Min=INT_MAX;
        int re=n-1;
        for(int i=n-1; i>=0; i--){
            if (Min>count[i]){
                Min=count[i];
                re=i;
            }
        }
        return re;
    }
    
};
```