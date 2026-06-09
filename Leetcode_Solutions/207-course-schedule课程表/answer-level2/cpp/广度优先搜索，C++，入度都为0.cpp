### 解题思路
广度优先搜索，C++，入度都为0

### 代码

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> ajac(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> qu;
        int cnt = 0;
        for(auto& pre: prerequisites)         
        {
            ajac[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;              //计算入度
        }    

        for(int i = 0; i < numCourses; i++)  //入度为0的节点入队
        {
            if(indegree[i] == 0)
            {
                qu.push(i);
                cnt++;                       //计算入度为0 的节点数量
            }
        }

        while(!qu.empty())                   //队列不为0
        {
            int cur = qu.front();
            qu.pop();
            for(int& succ: ajac[cur])
            {
                indegree[succ]--;
                if(indegree[succ] == 0)
                {
                    cnt++;
                    qu.push(succ);
                }
                if(cnt == numCourses)
                    return true;
            }
        }
        return cnt == numCourses;             //所有节点都可以变为入度为0，表示无环
    }
};

```