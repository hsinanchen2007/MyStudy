我太菜了

```
class Solution {
public:
    vector<vector<int> > d;
    int max;
    int massage(vector<int>& nums) {
        if(nums.empty())
            return 0;
        d.push_back(nums);
        d.push_back(vector<int>(nums.size(),0));
        max=0;
        dfs(0,0,0);
        dfs(1,0,0);
        return max;
    }
    void dfs(int i, int j, int path){
        path+=d[i][j];
        if(j==d[0].size()-1){
            if(path>max)
                max=path;
            return;
        }
        if(i==0)
            dfs(1,j+1,path);
        if(i==1){
            dfs(0,j+1,path);
            dfs(1,j+1,path);
        }
    }
};
```
