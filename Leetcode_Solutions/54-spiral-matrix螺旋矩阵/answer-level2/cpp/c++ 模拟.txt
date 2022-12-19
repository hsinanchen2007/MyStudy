### 解题思路
借鉴了dalao的思路，分四条边去模拟，但是一定要注意关键的一点，就是它不一定是方阵，如果是m > n,那么对第三个for循环就要加限制条件，否则会重复输出第一行的值，如果n > m，那么要对第四个for循环加限制条件，否则会重复输出最后一列的值，就酱。。。。

### 代码

```cpp
class Solution {
private:
    vector<int> path;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0,j;
        if(matrix.size() == 0){
            return path;
        }
        int n = matrix.size(),m = matrix[0].size();
        int count = (min(m,n)+1)/2;
        while(i<count){
            for(j=i;j<m-i;j++){
                path.push_back(matrix[i][j]);
            }
            for(j=i+1;j<n-i;j++){
                path.push_back(matrix[j][m-i-1]);
            }
            for(j=m-i-2;j>=i && n-i-1 != i;j--){
                path.push_back(matrix[n-i-1][j]);
            }
            for(j=n-i-2;j>=i+1 && m-i-1 != i;j--){
                path.push_back(matrix[j][i]);
            }
            i++;
        }
        return path;
    }
};
```