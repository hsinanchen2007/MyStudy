### 解题思路
图

### 代码

```cpp
class Solution {
public:
    struct  GraphNode {
        int label;
        vector<GraphNode *>  neighbors;
        GraphNode(int x):label(x){};
    };
    //结点访问状态，-1没有被访问过，0代表正在访问，1代表已经完成访问。
    bool  DFS_graph(GraphNode *node,vector<int >& visit){
        visit[node->label]=0;
        for (int i=0;i<node->neighbors.size();i++){
            if (visit[node->neighbors[i]->label]==-1){
                if (DFS_graph(node->neighbors[i],visit)==0){
                    return false;
                }
            }
            else if (visit[node->neighbors[i]->label]==0){
                return false;
            }
        }
          visit[node->label]=1;
          return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<GraphNode*>  graph;//邻接表
        vector<int> visit;//结点访问状态，-1没有被访问过，0代表正在访问，1代表已经完成访问。
        for(int i=0;i<numCourses;i++)
        {
            graph.push_back(new GraphNode(i));//创建图的结点，并赋值访问状态为空
            visit.push_back(-1);
        }                    

        for(int i=0;i<prerequisites.size();i++)
        {   
            //创建图，连接图的顶点。
            GraphNode  *begin=graph[prerequisites[i][1]];
            GraphNode *end=graph[prerequisites[i][0]];
            begin->neighbors.push_back(end);       //使课程二指向课程一
        }
        for(int i=0;i<graph.size();i++)
        {
            if (visit[i] == -1 &&!DFS_graph(graph[i],visit))
            {
                return false;  //如果结点没有被访问，进行DFS，如果DFS遇到环，返回无法完成
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            delete  graph[i];
        }
        return true;
    }
};
```