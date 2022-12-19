### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans=0;
        queue<int> q;
        vector<int> box;
        int n=status.size();
        vector<bool> visited(n,false);
        for(int i=0;i<initialBoxes.size();i++){
            if(status[initialBoxes[i]]==1){
                q.push(initialBoxes[i]);
                visited[initialBoxes[i]]=true;
            }
            box.push_back(initialBoxes[i]);
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            ans+=candies[t];
            for(int i=0;i<keys[t].size();i++){
                status[keys[t][i]]=1;
            }
            for(int i=0;i<containedBoxes[t].size();i++){
                box.push_back(containedBoxes[t][i]);
            }
            for(int i=0;i<box.size();i++){
                if(status[box[i]]==1&&visited[box[i]]==false){
                    q.push(box[i]);
                    visited[box[i]]=true;
                }
            }
        }
        return ans;
    }
};
```