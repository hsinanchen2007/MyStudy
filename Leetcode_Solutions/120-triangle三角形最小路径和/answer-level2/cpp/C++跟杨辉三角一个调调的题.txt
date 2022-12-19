执行用时 :4 ms, 在所有 cpp 提交中击败了97.04%的用户
内存消耗 :9.6 MB, 在所有 cpp 提交中击败了95.39%的用户
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int min = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++){
            triangle[i][0] += triangle[i-1][0];
            min = triangle[i][0];
            for(int j = 1; j < i; j++){
                triangle[i][j] += triangle[i-1][j-1] < triangle[i-1][j] ? triangle[i-1][j-1] : triangle[i-1][j];
                if(min > triangle[i][j])    min = triangle[i][j];
            }
            triangle[i][i] += triangle[i-1][i-1];
            if(min > triangle[i][i]) min = triangle[i][i];
        }
        return min;
    }
};
```
