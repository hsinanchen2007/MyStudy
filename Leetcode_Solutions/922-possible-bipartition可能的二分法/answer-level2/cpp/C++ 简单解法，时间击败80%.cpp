```
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> Map(N+1, vector<int>());
        for(int i=0;i<dislikes.size();i++) {
            int a=dislikes[i][0];
            int b=dislikes[i][1];
            Map[a].push_back(b);
            Map[b].push_back(a);
        }
        vector<int> color(N+1, -1);
        for(int i=0;i<dislikes.size();i++) {
            int a=dislikes[i][0];
            if(color[a]==-1) {
                if(!dfs(a, 0, color, Map)) {
                    return false;
                }  
            }
        }
        return true;
    }
    bool dfs(int f, int flag, vector<int>& color, vector<vector<int>>& Map) {
        if(color[f]!=-1&&color[f]!=flag) {
            return false;
        }
        if(color[f]==flag) {
            return true;
        }
        color[f]=flag;
        for(int i=0;i<Map[f].size();i++) {
            int b=Map[f][i];
            bool res=dfs(b, flag^1, color, Map);
            if(!res) {
                return false;
            }
        }
        return true;
    }
    
};
```
