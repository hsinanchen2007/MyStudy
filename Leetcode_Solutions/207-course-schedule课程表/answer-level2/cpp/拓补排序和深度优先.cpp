## 题目描述
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

![](https://pic.leetcode-cn.com/0e7f96227661dab19a29f15785fab577eaa4983cc5e1bfa90b7421b9ef6cdeb8.png)

[课程表](https://leetcode-cn.com/problems/course-schedule/ "课程表")

## 解决方法
### 拓补排序


1. 将所有入度为0的顶点放入队列；

2. 每次从队列中弹出一个顶点v，直到队列为空；

3. 遍历所有与v相连的顶点，将相邻顶点的入度减一（删边）；

4. 若某个相邻顶点入度为0，将其放入队列中，返回第2步；

5. 若所有顶点均访问到，说明排序完成。否则，说明总有顶点入度不为0，没有放入队列中，即该有向图有环

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses);//入度表
        vector<vector<int>>graph(numCourses,vector<int>());//邻接表
        queue<int>q;
        int count=0;
        //构造邻接表
        for(auto item:prerequisites){
            graph[item[1]].push_back(item[0]);
        }
        //构造入度表
        for(auto item:prerequisites){
            indegree[item[0]]++;
        }
        //入度为0的点
        for(int i=0;i<numCourses;i++){
            if(!indegree[i])q.push(i);
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            count++;
            int size=graph[temp].size();//当前点指向几个点
            for(int i=0;i<size;i++){
                if(--indegree[graph[temp][i]]==0)q.push(graph[temp][i]);
            }
        }
        if(count==numCourses)return true;
        return false;
    }
};
```

### DFS

- 单纯的向后遍历即可，如果访问到已经访问过的课程，说明有环，退出即可

```cpp
class Solution {
public:
    //判断是否有环
    bool helper(int i,vector<vector<int>>& graph,set<int>& visited,vector<bool>& flag){
        if(flag[i])return false;//访问过直接退出
        if(visited.count(i))return true;//当前元素已经访问过，说明有环
        visited.insert(i);
        for(auto item:graph[i]){
            if(helper(item,graph,visited,flag))return true;
        }
        flag[i]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses,vector<int>());//邻接表
        vector<bool>flag(numCourses,0);//dfs查表用，否则超时
        //构造邻接表
        for(auto item:prerequisites){
            graph[item[1]].push_back(item[0]);
        }
        for(int i=0;i<numCourses;i++){
            set<int> visited;
            if(helper(i,graph,visited,flag)){
                return false;
            }
        }
        return true;
    }
};
```

个人网站：[李一平](https://liyiping.cn)