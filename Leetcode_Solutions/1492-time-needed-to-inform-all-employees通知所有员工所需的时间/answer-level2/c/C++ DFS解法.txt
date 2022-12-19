```c++
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> my_son(manager.size());
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1) my_son[manager[i]].push_back(i);
        }
        queue<pair<int,int>> Q;
        Q.push({headID,0});
        int max=0;
        pair<int,int> cur;
        while(!Q.empty()){
            cur=Q.front();
            Q.pop();
            if(cur.second>max) max=cur.second;
            for(auto it:my_son[cur.first]){
                Q.push({it,cur.second+informTime[cur.first]});
            }
        }
        return max;
    }
};
```
