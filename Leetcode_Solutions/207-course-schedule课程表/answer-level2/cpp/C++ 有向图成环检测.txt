C++ 有向图成环检测
1.构造邻接表来表示图
2.利用拓扑排序来检测是否成环，有环则无拓扑排序，无环则有拓扑排序

图论相关介绍可以参考
https://wenku.baidu.com/view/a62704fcc381e53a580216fc700abb68a882ad09.html?from=search

```
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //记录顶点入度
        vector<int> indegree(numCourses, 0);
        //邻接表
        vector<vector<int>> adjacencyList(numCourses, vector<int>());
        int len = prerequisites.size();
        //计算所有的顶点的入度值
        for (int i = 0; i < len; i++) {
            vector<int> item = prerequisites[i];
            int curCourse = item[0];
            int preCourse = item[1];
            //计算入度
            indegree[preCourse]++;
            //构造邻接表
            adjacencyList[curCourse].push_back(preCourse);
        }

        //将所有入度为0的顶点入队列
        queue<int> courseQueue;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                courseQueue.push(i);
            }
        }

        int count = 0; //记录访问过的顶点数
        //拓扑排序遍历顶点
        while (!courseQueue.empty()) {
            int point = courseQueue.front();
            courseQueue.pop();
            count++;
            //从邻接表里面访问，把从该顶点出发所能到达人顶点的入度减一
            for (int i = 0; i < adjacencyList[point].size(); i++) {
                int preCourse = adjacencyList[point][i];
                indegree[preCourse]--;
                //入度为0则加入队列
                if (indegree[preCourse] == 0) {
                    courseQueue.push(preCourse);
                }
            }
        }

        //如果遍历完还有顶点没有访问到，说明该有向图有环
        return count == numCourses;
    }
};
```
