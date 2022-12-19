### 解题思路
 另开一个数组进行赋值就好了。这里用的是在原地修改。
 首先，把数组左右翻转。例如[1,2,3]变为[3,2,1]。然后再进行每个元素的写对角线进行翻转即可。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n <= 1)return ;
        for(int i = 0 ; i < n ; i++){
            int l = 0 , r = n - 1;
            while(l < r){
                swap(matrix[i][l++] , matrix[i][r--]);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n - 1 - i ; j++){
                swap(matrix[i][j] , matrix[n - 1 - j][n - 1 - i]);
            }
        }
    }
};
```