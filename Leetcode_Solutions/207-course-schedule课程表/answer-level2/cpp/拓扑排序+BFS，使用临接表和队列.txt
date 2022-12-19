```
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses<=0){
            return false;
        }
        if(prerequisites.empty()){
            return true;
        }
        
        vector<int> indegree(numCourses, 0);
        vector<list<int>> adjacent(numCourses, list<int>({}));
        queue<int> myqueue;
        vector<int> res;
        
        for(vector<int> p : prerequisites){
            indegree[p[0]] ++;
            adjacent[p[1]].push_back(p[0]);
        }
        
        
        for(int i=0; i<numCourses; i++){
            if(!indegree[i]){
                myqueue.push(i);
            }
        }
        
        while(myqueue.size()){
            int num = myqueue.front();
            myqueue.pop();
            numCourses --;
            res.push_back(num);
            for(int v : adjacent[num]){
                indegree[v] --;
                if(!indegree[v]){
                    myqueue.push(v);
                }
            }
        }
        return numCourses == 0;
    }
};
```

* 执行用时 :36 ms, 在所有 C++ 提交中击败了61.48%的用户
* 内存消耗 :14 MB, 在所有 C++ 提交中击败了15.60%的用户
* 基本是参照其他题解写的，多了临接表的部分。