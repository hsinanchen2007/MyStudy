### 解题思路
khan算法挺简单的不说了。
dfs递归方法，使用逆邻接矩阵遍历得到的结果就是一个拓扑排序的结果。
所以首先要建一个逆邻接表；之后正常遍历就可以，但是要注意，is_visited数组的状态位要有3个了，因为需要判断是否有环。
当一个节点被访问时先标记它为-1（表示正在被访问），如果在后续的遍历中遍历到哪个节点为-1，说明循环了，也就是有环了，这时就不用返回结果了，直接return。 
看我的代码吧，代码比较好懂。

另外bfs也可以进行拓扑排序，今天太晚了，明天再实现

### 代码

```cpp
/*class Solution {//先用khan算法
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> v;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; ++i)
            graph.push_back(v);
        for(int i=0; i<prerequisites.size(); ++i)//建立图并建立indegree
        {
            ++indegree[prerequisites[i][0]];
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(auto it=graph.begin(); it!=graph.end(); ++it)
        {
            for(auto it1=(*it).begin(); it1!=(*it).end(); ++it1)
                cout<<*it1<<" ";
            cout<<endl;
        }
        queue<int> que;
        for(int i=0; i<numCourses; ++i)//把入度为0的节点放入队列
            if(indegree[i]==0)
                que.push(i);
        while(!que.empty())
        {
            int tmp=que.front();
            res.push_back(tmp);
            que.pop();
            for(int i=0; i<graph[tmp].size(); ++i)
            {
                --indegree[graph[tmp][i]];
                if(indegree[graph[tmp][i]]==0)
                    que.push(graph[tmp][i]);
            }
        }
        if(res.size()==numCourses)
            return res;
        else
            return {};
    }
};*/
class Solution {//先用dfs算法
public:
    bool is_dag=false;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses);
        for(int i=0; i<numCourses; ++i)
        {
            graph.push_back(res);
        }
        for(int i=0; i<prerequisites.size(); ++i)//创建匿邻接表
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> is_visited(numCourses,0);//0表示未被访问，1表示已经被访问，-1表示正在被访问
        for(int i=0; i<numCourses; ++i)
        {
            if(is_visited[i]==0)
            {
                is_visited[i]=-1;
                for(int j=0; j<graph[i].size(); ++j)
                    dfs(graph[i][j],graph,is_visited,res);
                is_visited[i]=1;
                res.push_back(i);
            }
        }
        if(!is_dag)
            return res;
        else
            return {};
    }
    void dfs(int ver,vector<vector<int>>& graph,vector<int>& is_visited, vector<int>& res){//注意这块，这3个数组一定要用引用，否则会超时，我刚开始忘记把graph的引用忘掉了，怎么做都超时，一直看代码想着优化。看着看着突然发现忘加引用了，加完引用后速度就正常了。
        if(is_visited[ver]==1)
            return;
        is_visited[ver]=-1;
        for(int i=0; i<graph[ver].size(); ++i)
        {
            if(is_visited[graph[ver][i]]==0)
                dfs(graph[ver][i],graph,is_visited,res);
            else if(is_visited[graph[ver][i]]==-1)
                {
                    is_dag=true;
                    return;
                }
        }
        is_visited[ver]=1;
        res.push_back(ver);
    }
};

```