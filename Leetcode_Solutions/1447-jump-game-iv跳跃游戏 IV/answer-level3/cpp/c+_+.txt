### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int> > umap;
        
        int t = -1;
        for(int i = 0;i < arr.size();++i){
            if(arr[i] == t && i + 1 < arr.size() && arr[i] == arr[i+1]) {
                arr.erase(arr.begin()+i);
                --i;
            }
            else t = arr[i];
        }

        for(int i = 0;i < arr.size();++i)
            umap[arr[i]].push_back(i);
        
        vector<int> dist(arr.size(), 0x3f3f3f);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        vector<bool> vis(arr.size(), false);
        while(!q.empty()){
            auto t = q.front();q.pop();
            vis[t] = true;
            if(t > 0 && dist[t-1] > dist[t] + 1 && !vis[t-1]) {
                dist[t-1] = dist[t] + 1;
                q.push(t-1);
            }
            if(t < arr.size()-1 && dist[t+1] > dist[t] + 1 && !vis[t+1]) 
            {
                dist[t+1] = dist[t] + 1;
                q.push(t+1);
            }
            for(auto p : umap[arr[t]]){
                if(p == t-1 || p == t+1)continue;
                if(!vis[p] && dist[p] > dist[t] + 1){
                    dist[p] = dist[t] + 1;
                    q.push(p);
                }
            }
        }
        return dist[arr.size()-1];
    }
};
```