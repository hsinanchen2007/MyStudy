
```
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1){
                    count++;
                }
                else{
                    break;
                }
            }
            pair<int,int> p(count,i);
            pq.push(p);
        }
        int n=pq.size();
        for(int i=0;i<n-k;i++){
            pq.pop();
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```
