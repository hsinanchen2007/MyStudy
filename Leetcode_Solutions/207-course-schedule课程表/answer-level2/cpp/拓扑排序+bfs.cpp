### 解题思路
已知给定的二维数组就是从先修课到该课程的有向图（先修课指向该课）。
1.记录每门先修课及其后继课程（map映射存储该课，及该课后继的集合），以及每门课的先修课程数量（入度）。
2.用队列存储入度为0的课程（没有先修课，可以直接上）。
3.一次从队列中取出入度为0的课程，从图中删去该课程（根据map映射，将其后继课程的入度减一），若有课程入度减为0（所有先修课都已经上完），则将其加入队列。
4.循环3直到队列为空。
5.比较从队列中删除的课程数量（从图中删除的课程数量）和给定的课程总数，若相等，则说明所有课程都可以按序上完，返回true，否则返回false。


### 代码

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if (n == 0)
        {
            return true;
        }
        map<int, set<int>>mm;//记录有向图中每个节点和其所有后继节点。
        vector<int>degree(numCourses + 1, 0);//记录有向图中所有节点的入度。
        for (int i = 0; i < n; i++)//初始化记录
        {
            int a = prerequisites[i][1];//先修课程
            int b = prerequisites[i][0];//后继课程
            mm[a].insert(b);
            degree[b]++;
        }
        queue<int>q;//记录入度为0的课程（无先修课程，或先修课程已经上完）
        for (int i=0;i<numCourses;i++)//初始化
        {
            if (degree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty())
        {
            int temp = q.front();//取出一个入度为0的课程
            q.pop();
            count++;//记录可以完成的课程数量
            auto x = mm[temp];//找到该入度为0课程(temp)指向的后继课程集合(x);
            for (auto s : x)//遍历该集合，将其中所有课程入度减一
            {
                degree[s]--;
                if (degree[s] == 0)//若有课程入度减为0（所有先修课程都已经上完）则将其加入队列
                {
                    q.push(s);
                }
            }
        }
        if (count == numCourses)return true;
        else return false;
    }
};
```