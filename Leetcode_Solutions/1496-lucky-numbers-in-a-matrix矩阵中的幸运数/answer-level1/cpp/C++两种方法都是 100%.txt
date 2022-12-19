### 解题思路
两种方法都是 100%

1.是记录每行最小值在第几列，进行查找


2.是得到每行最小和每列最大后，判断是否有相等值。如果有则肯定是同一个数，因为矩阵没有相同元素

### 代码
```

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> row_min(m,100000);
        vector<int> row_index(m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row_min[i] > matrix[i][j]){
                    row_min[i] = matrix[i][j];
                    row_index[i] =j;
                }
            }
        }

        vector<int> col_max(n,0);
        
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(col_max[j] < matrix[i][j]){
                    col_max[j] = matrix[i][j];
                }
            }
        }
        for(int i=0;i<m;i++){
            if(row_min[i] == col_max[row_index[i]]){
                res.push_back(row_min[i]);
            }
        }

        return res;
    }
};

//执行用时 :12 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗 :9.5 MB, 在所有 C++ 提交中击败了100.00%的用户
/*class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> row_min(m,100000);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row_min[i] > matrix[i][j]){
                    row_min[i] = matrix[i][j];
                }
            }
        }

        vector<int> col_max(n,0);
        
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(col_max[j] < matrix[i][j]){
                    col_max[j] = matrix[i][j];
                }
            }
            if()
        }
        for(auto c:row_min){
            if(find(col_max.begin(),col_max.end(),c)!=col_max.end()){
                res.push_back(c);
            }
        }
        return res;
    }
};*/
```
```

```cpp
