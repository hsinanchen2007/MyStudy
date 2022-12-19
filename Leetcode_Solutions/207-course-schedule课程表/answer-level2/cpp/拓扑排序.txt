拓扑排序问题
`class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int> S;
        int count = 0;
        vector<int> inDegree(numCourses);
        addEdge(inDegree, prerequisites);
        for(int i = 0; i < numCourses; i ++ )
        {
            if(inDegree[i] == 0)
                S.push(i);
        }
        while(!S.empty())
        {
            int top = S.top();
            count ++ ;
            S.pop();
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
        if(count < numCourses)
            return false;
        return true;
        
    }
    int addEdge( vector<int>& inDegree, vector<vector<int>>& prerequisites){
        for(int i=0; i < prerequisites.size(); i++)
            inDegree[prerequisites[i][1]] ++;
        
        return 0;
    }
};`