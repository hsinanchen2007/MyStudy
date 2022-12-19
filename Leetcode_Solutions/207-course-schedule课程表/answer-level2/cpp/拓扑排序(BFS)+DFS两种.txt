（一）深度优先遍历(DFS)
直观思考，对于先决条件0-->1, 1-->2, 0-->2来说，课程0需要首先修课程1作为先决条件，构建依赖关系表deps。深度优先遍历每个课程的依赖关系，并对已经遍历过的课程做标记-1，当出现环状依赖说明进入死循环，该循环中的任何一个课程均不可能被修完。
```
class Solution {
    bool hasCircle(vector<list<int> > &deps, int course, vector<int> &courses){
        if(courses[course]==0) return false;
        if(courses[course]==-1) return true;
        courses[course]=-1;
        for(const auto &dep:deps[course])
            if(hasCircle(deps, dep, courses)) return true;
        courses[course]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int> > deps(numCourses, list<int>());
        vector<int> courses(numCourses, 0);
        for(const auto &v:prerequisites){
            deps[v[0]].push_back(v[1]);
            courses[v[0]]=1;
        }
        for(int course=0; course<numCourses; ++course)
            if(hasCircle(deps, course, courses)) return false;
        return true;
    }
};
```

（二）拓扑排序(Topological Sort, BFS)
对于先决条件0-->1, 1-->2, 0-->2来说，修课程1是修课程0的必要条件，修课程2也是修课程0的必要条件，可以使用有向图表示推导条件关系edges，并记录任意课程的必要条件（入度）个数，如0的入度为2， 1的入度为1,2的入度为0.注意，这里推导关系edges与上面的依赖关系deps正好相反。
入度为0的课程可以直接修不需要任何先决条件。逐步删除（表示已经被修完）入度为0的课程，并更新需要该课程做必要条件的课程的入度，即入度-1.逐步删除入度课程，统计所有被删除的课程个数，是否与总课程数相等。
```
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int> > edges(numCourses, list<int>());
        vector<int> indegrees(numCourses, 0);
        for(const auto &v:prerequisites){
            edges[v[1]].push_back(v[0]);
            ++indegrees[v[0]];
        }
        queue<int> courses;
        for(int i=0; i<numCourses; ++i)
            if(indegrees[i]==0) courses.push(i);
        for(; !courses.empty(); --numCourses, courses.pop())
            for(const auto &node:edges[courses.front()])
                if(--indegrees[node]==0) courses.push(node);
        return numCourses==0;
    }
};
```
