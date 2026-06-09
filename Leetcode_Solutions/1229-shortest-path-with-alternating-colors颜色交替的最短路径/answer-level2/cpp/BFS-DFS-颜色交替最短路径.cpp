## 思路
1.本题两个节点之间有可能存在颜色不同的两条边，且存在环路。
2.直连某个结点x的边可能存在多条，多种颜色。我们需要保存从0到x的最短路径长度，正常情况下是这样的，但是由于本题要求红蓝交替，考虑一种情况：有一条红边和一条蓝边与结点x直连，且从红边进的那条路径更短，从如果我们只保留从红边到x的路径路径长度，那么由于x到Y只有红边,且进入x的边也是红边，并非交替，我们将无法到达Y,但实际上如果选择从蓝边进入x,那么是可以进入Y的。但是我们同样不能只保存从蓝边进入x的路径长度，因为0到x的最短路径是从红边进入的。所有我们要同时保留红蓝边进入x的最短路路径。
3.在遍历结束之后每个结点到0的最短距离分红蓝二者，我们比较一下取较小的，如果二者都为INT_MAX-1，则表明该结点不可达，设为-1；

![Untitled Diagram.png](https://pic.leetcode-cn.com/7362a880fb7384d043d50a37b289069993ee2060db8e1c50912eaf524dc5ca02-Untitled%20Diagram.png)

4.在建图的时候之前我是直接用一个n*n的矩阵保存，每次在red_edges和blue_edges里找（i，j）是否存在，使用find的函数，但是最后超时了。然后改用map<结点n,所有与n结点直连的结点的集合>来建图，但是要使用两个map，一个放直连的红色的边，一个放直连的蓝色的边。

5.在遍历每个直连的结点时不要用for(int i=0;i<n;i++)，而是直接用for(int i:connect_node),这样不用做无用的循环。


### BFS


```cpp
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        //建图
        unordered_map<int,unordered_set<int>>red;//一个结点：所有与其相邻的结点
        unordered_map<int,unordered_set<int>>blue;
        for(vector<int> i:red_edges)red[i[0]].insert(i[1]);
        for(auto i:blue_edges)blue[i[0]].insert(i[1]);

        //bfs
        queue<int>node;
        //first: last edge is red,second:last edge is blue
        vector<pair<int,int>>dis(n,make_pair(INT_MAX-1,INT_MAX-1));//每个点到0结点的两种距离
        dis[0]=make_pair(0,0);
        node.push(0);
        int temp,flag=false;
        while(!node.empty()){
            temp=node.front();
            node.pop();
            for(int i=0;i<n;i++){
                flag=false;
                if(red[temp].find(i)!=red[temp].end()) {//有红色路
                    //red
                    if (dis[temp].second + 1 < dis[i].first) {//
                        node.push(i);
                        flag = true;
                        dis[i].first = dis[temp].second + 1;
                    }
                }
                    //blue
                if(blue[temp].find(i)!=red[temp].end()){
                    if(dis[temp].first+1<dis[i].second){
                        if(!flag)node.push(i);//如果上一步放过了就不在放了，剪枝
                        dis[i].second=dis[temp].first+1;
                    }
                }

            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(dis[i].first==INT_MAX-1&&dis[i].second==INT_MAX-1)res.push_back(-1);
            else res.push_back(min(dis[i].first,dis[i].second));
        }

        return res;
    }
};
```


### DFS
```
class Solution {
public:
    unordered_map<int,unordered_set<int>>red;//一个结点：所有与其相邻的结点
    unordered_map<int,unordered_set<int>>blue;

    void dfs(vector<unordered_map<int,unordered_set<int>>>&map,vector<vector<int>> &dis,int from,int flag){
        for(int i:map[flag][from]){//一次考虑每个直连结点
                if(dis[from][flag]+1<dis[i][!flag]){
                    dis[i][!flag]=dis[from][flag]+1;
                    dfs(map,dis,i,!flag);
                }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        //建图
        for(vector<int> i:red_edges)red[i[0]].insert(i[1]);
        for(auto i:blue_edges)blue[i[0]].insert(i[1]);
        vector<unordered_map<int,unordered_set<int>>>map={red, blue};
        //dfs
        //first: last edge is red,second:last edge is blue
        vector<vector<int>>dis(n,vector<int>(2,INT_MAX-1));//每个点到0结点的两种距离距离
        dis[0]={0,0};
        dfs(map,dis,0,1);
        dfs(map,dis,0,0);
        vector<int>res;
        for(int i=0;i<n;i++){
            if(dis[i][0]==INT_MAX-1&&dis[i][1]==INT_MAX-1)res.push_back(-1);
            else res.push_back(min(dis[i][0],dis[i][1]));
        }
        return res;
    }
};

```
