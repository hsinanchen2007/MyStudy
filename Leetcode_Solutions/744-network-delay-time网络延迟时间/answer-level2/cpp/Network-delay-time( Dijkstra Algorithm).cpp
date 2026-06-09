### 解题思路
单源最短路径( Dijkstra Algorithm )
1. 邻接矩阵存储边与权值
2. 用一个flag布尔数组判断是否是处理过的节点（确定了与源节点最短路径的节点）
3. 用一个整数数组distance存储每个节点到源节点的值
4. 迭代过程（结束条件：所有图中的节点全部处理完毕 flag[i]=true）：
    （1）每次找到distance中未被处理的距离最小的节点确定为处理好的节点
    （2）更新distance中与新处理节点相邻节点的值
5. 如果distance中有节点的值是 INT_MAX，说明无法到达该节点，返回-1（特别注意，本解法中直接利用find()返回了-1）；最终返回distance中的最大值；

### 代码

```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> map(N,vector<int>(N,INT_MAX));
        vector<bool> flag(N,false);
        vector<int> distance(N,INT_MAX);
        flag[K-1]=true;
        distance[K-1]=0;
        for(auto &p:times)
            map[p[0]-1][p[1]-1]=p[2];
        for(int i=0;i<N;i++) {
            map[i][i]=0;
            distance[i]=map[K-1][i];
        }
        int count=1,next,max=0;
        while(count<N){
            next = find(distance,flag);
            if(next==-1) return -1;
            flag[next]=true;
            for(int i=0;i<N;i++){
                if(map[next][i]==INT_MAX) continue;
                int value = map[next][i]+distance[next];
                if(value<distance[i]) distance[i]=value;
            }
            count++;
        }
        for(auto p:distance) if(p>max) max=p;
        return max;
        
        
    }
    int find(vector<int> &distance,vector<bool> &flag){
        int next=-1,value=INT_MAX;
        for(int i=0;i<distance.size();i++){
            if(flag[i]==true) continue;
            if(distance[i]<value){
                next=i;
                value = distance[i];
            }
        }
        return next;
    }
};
```