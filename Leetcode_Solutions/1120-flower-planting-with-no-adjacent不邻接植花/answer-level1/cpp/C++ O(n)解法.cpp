```
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) 
    {
        vector<int> result(N,0);
        vector<vector<int>> paths_map(N);
        //build path map from paths
        for (auto it:paths)
        {
            int v1 = it[0];
            int v2 = it[1];
            if (v1>v2)
            {
                paths_map[v1-1].push_back(v2-1);
            }
            else
            {
                paths_map[v2-1].push_back(v1-1);
            }
        }
        
        for (int i=0; i<N; ++i)
        {   
            vector<int> exist;
            auto path_set = paths_map[i];
            int color = 1;
            // store used colors
            for (auto it:path_set)
            {
                exist.push_back(result[it]);
            }
            //select a unused color 
            while (find(exist.begin(),exist.end(),color)!=exist.end())
                ++color;
            result[i] = color;
        }
        
        return result;
    }
};
```
