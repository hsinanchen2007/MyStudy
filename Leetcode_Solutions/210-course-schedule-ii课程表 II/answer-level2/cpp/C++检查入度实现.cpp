### 解题思路
代码思路比较简单，如果是上一个课程表已经实现了，那么只要加一个vector进行保存就可以了

### 代码

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> m;
        vector<int> res;
        int indeg[numCourses]={0};
        for(auto x:prerequisites){
            m[x[1]].emplace_back(x[0]);
            indeg[x[0]]++;
        }
        int solved=0;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i] == 0){
                q.push(i);
                solved++;
                res.emplace_back(i);
            }
        }
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto x:m[i]){
                indeg[x]--;
                if(indeg[x] == 0){
                    q.push(x);
                    solved++;
                    res.emplace_back(x);
                }
            }
        }
        if(solved == numCourses)
            return res;
        else
            return vector<int>();
        
    }
};
```