```
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int count = 0 ;
        stack<int> S;
        vector<int> res;
        vector<int> inDegree(numCourses);
        addEdge(inDegree, prerequisites);
        for(int i=0; i < numCourses; i ++)
        {
            if(inDegree[i] == 0)
                S.push(i);
        }
        while(!S.empty())
        {
            int top = S.top();
            res.insert(res.begin(), top);
            S.pop();
            count ++;
            for(int i=0; i < prerequisites.size(); i++)
            {
                if(prerequisites[i][0] == top)
                {
                    int node = prerequisites[i][1];
                    if(!--inDegree[node])
                        S.push(node);
                }
            }
        }
        if( count < numCourses)
        {
            res.clear();
            return res;
        }
        return res;
    } 
    int addEdge(vector<int>& inDegree, vector<vector<int>>& prerequisites)
    {
        for(int i=0; i < prerequisites.size(); i++)
            inDegree[prerequisites[i][1]] ++;
        return 0;
    }
};
```
