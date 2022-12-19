### 解题思路
需要注意的坑：
1.i,j设置为左下角，则是[m-1][0]，ij容易混淆
2.注意 判断矩阵为空的情况，最好用empty方法
    2.1 如果用size方法，要加两层判断，因为[[]]的size是1，还要进内层判断
        否则会引起边界问题

### 代码

```cpp
//左下角，matrix[m-1][0]
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {      
        if(matrix.size() == 0 || matrix[0].size()==0) return false;
        int j = 0;
        int i = matrix.size() - 1;
        while(i >= 0 && j <= matrix[0].size() - 1)
        {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) j++;
            else i--;
        }
        return false;
     
    }
};
```