```
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int len = grid[0].size();
        
        if(len == 0)
            return 0;
        
        vector<int> left;
        vector<int> up;
        
        //求出从左边/右边看的数组 
        for(int i=0; i<len; i++){
            int max = grid[i][0];
            for(int j=0; j<len; j++){
                if(grid[i][j]>max)
                    max = grid[i][j];
            }
            left.push_back(max);
        }
        
        //求出从上面或下面看的数组
        for(int j=0; j<len; j++){
            int max = grid[0][j];
            for(int i=0; i<len; i++){
                if(grid[i][j] > max)
                    max = grid[i][j];
            }
             up.push_back(max);
        }
        
        //新的数组是up，left数组对应的最小值 结果是grid数组和gridNew数组对应元素相减 再将这些值相加
        int res=0;
        vector<vector<int>> gridNew(len);
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                int Min = min(left[i],up[j]);
                gridNew[i].push_back(Min);
                res += (gridNew[i][j]-grid[i][j]);
            }
        }
        
        return res;
    }
};
```
