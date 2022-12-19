### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ret;
        for (int i = 0;i<n;i++){
            int minn = 999999999;
            int index = -1;
            for (int j = 0;j<m;j++){
                if(matrix[i][j]<=minn){
                    index = j;
                    minn = matrix[i][j];
                }
            }
            int maxx = -999999999;
            for(int k = 0;k<n;k++){
                maxx = max(maxx,matrix[k][index]);
            }
            if(maxx==minn){
                ret.push_back(maxx);
            }
        }
        return ret;
    }
};
```