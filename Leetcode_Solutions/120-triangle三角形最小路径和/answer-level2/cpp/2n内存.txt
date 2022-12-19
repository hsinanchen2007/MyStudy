### 解题思路
动态规划

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> res(2, vector<int>(m, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j <= i; j++){
                if(i == 0 && j == 0){
                    res[1][0] = triangle[i][j];
                }else if(j == 0){
                    res[1][0] = res[0][0] + triangle[i][j];
                }else if(j == i){
                    res[1][j] = res[0][j-1] + triangle[i][j];
                }else{
                    res[1][j] = min(res[0][j-1], res[0][j]) + triangle[i][j];
                }
            }
            res[0] = res[1];
        }
        int minval = INT_MAX;
        for(auto num: res[0]){
            minval = min(minval, num);
        }
        return minval;
    }
};
```