因为最后得到的结果可能是一个节点或者两个节点，因此我们设置n>2作为判定条件，使用BFS算法实现。
```
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<unordered_set<int> > adjs(n);
        for(auto edge:edges){
            adjs[edge[0]].insert(edge[1]);
            adjs[edge[1]].insert(edge[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(adjs[i].size()==1)   q.push(i);
        }
        while(n>2){
            int size=q.size();
            n-=size;
            while(size-->0){
                auto t=q.front();
                q.pop();
                for(auto itm:adjs[t]){
                    adjs[itm].erase(t);
                    if(adjs[itm].size()==1) q.push(itm);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
```