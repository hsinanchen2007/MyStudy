### 解题思路
一圈一圈遍历

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(m == 0) return ans;
        int n = matrix[0].size();
        spider(matrix, ans, m, n, 0, 0);
        return(ans);
    }

    void spider(vector<vector<int>>& matrix, vector<int>& ans, int m, int n, int a, int b){
        if(m<=0 || n<=0) return;
        if(m == 1){ 
            for(int i=b; i<b+n; i++){
                ans.push_back(matrix[a][i]);
            }
            return;
        }
        if(n == 1){
            for(int i=a; i<a+m; i++){
                ans.push_back(matrix[i][b]);
            }
            return;
        }
        int i=a, j=b;
        for(;j<b+n; j++){
            ans.push_back(matrix[i][j]);
        }
        j--;
        i++;
        for(;i<a+m; i++){
            ans.push_back(matrix[i][j]);
        }
        i--;
        j--;
        for(; j>=b; j--){
            ans.push_back(matrix[i][j]);
        }
        j++;
        i--;
        for(; i>a; i--){
            ans.push_back(matrix[i][j]);
        }
        spider(matrix, ans, m-2, n-2, a+1, b+1);
        return;
    }
};
```